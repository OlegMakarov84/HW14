#pragma once
#include "User.h"

class Message
{
public:
	Message(const std::string& from, const std::string& to, const std::string& text) :_from(from), _to(to), _text(text) {}
	Message(const std::string& from) :_from(from) {}
	const std::string& getFrom() const{ return _from; }
	const std::string& getTo() const{ return _to; }
	const std::string& getText() const { return _text; }
	

private:
	const std::string _from;
	const std::string _to;
	const std::string _text;
};

