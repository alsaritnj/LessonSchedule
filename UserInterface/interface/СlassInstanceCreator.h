#pragma once
#include "../Question/Question.h"

class ÑlassInstanceCreator
{
public:
	virtual void* create() const = 0;
	virtual Question getQuestion(const short& index) const = 0;
	virtual void setAnswer(const short& index, void* answer) = 0;
	virtual unsigned getCountOfQuestions() const = 0;
	virtual std::string nameOfCreatableClass() const = 0;

};