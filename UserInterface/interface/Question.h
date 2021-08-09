#pragma once
#include <string>

class Question
{
public:
	virtual std::string getQuestion() const = 0;
};