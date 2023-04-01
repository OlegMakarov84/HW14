
#include "Trie.h"
#include <iostream>
#include <vector>

bool Trie::insertWord(TrieNode* root, std::string word) {
	// Base case
	if (word.size() == 0) {
		if (!root->isTerminal) {
			root->isTerminal = true;
			return true;
		}
		else {
			return false;
		}
	}

	// Small Calculation
	int index = word[0] - 'a';
	TrieNode* child;
	if (root->children[index] != nullptr) {
		child = root->children[index];
	}
	else {
		child = new TrieNode(word[0]);
		root->children[index] = child;
	}

	// Recursive call
	return insertWord(child, word.substr(1));
}

// For user
void Trie::insertWord(std::string word) {
	if (insertWord(root, word)) {
		this->count++;
	}
}
void Trie::complete(TrieNode* root, std::string word, std::string output, bool& possible, std::string& key) {
	if (word.length() == 0) {
		if (root->isTerminal) {
			///this is first word we found that has key as a prefix
			if (!possible)
				std::cout << "\nWords containing " << key << " as prefix are:\n";
			possible = 1;
			std::cout << output << std::endl;
		}
		for (int i = 0; i < 26; i++) {
			if (root->children[i] != nullptr) {
				std::string output1 = output;
				output1 += root->children[i]->data;
				complete(root->children[i], word.substr(), output1, possible, key);
			}
		}
		return;
	}
	int index = word[0] - 'a';
	if (root->children[index] == nullptr)
		return;
	else
		complete(root->children[index], word.substr(1), output + word[0], possible, key);
}

void Trie::autoComplete(std::string& key, bool& possible) {
	std::string output = "";
	complete(root, key, output, possible, key);
}