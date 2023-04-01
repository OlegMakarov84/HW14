#pragma once

#include <iostream>
#include <vector>

class TrieNode {
public:
	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data) {
		this->data = data;
		children = new TrieNode * [26];
		for (int i = 0; i < 26; i++) {
			children[i] = nullptr;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode* root;

public:
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}
	bool insertWord(TrieNode* root, std::string word);
	void insertWord(std::string word);
	void complete(TrieNode* root, std::string word, std::string output, bool& possible, std::string& key);
	void autoComplete(std::string& key, bool& possible);
	
};