#pragma once
#include "Question.h"

class ÑlassInstanceCreator
{
public:
	virtual void* create() const = 0;
	virtual const Question& getQuestion(const short& index) const = 0;
	virtual void setAnswer(const short& index, const std::string& answer) = 0;
	virtual unsigned getCountOfQuestions() const = 0;
	virtual std::string nameOfCreatableClass() const = 0;

};