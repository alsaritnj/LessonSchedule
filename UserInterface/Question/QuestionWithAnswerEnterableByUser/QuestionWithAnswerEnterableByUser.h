#pragma once
#include "../../interface/Question.h"

class QuestionWithAnswerEnterableByUser : public Question
{
public:
	QuestionWithAnswerEnterableByUser(const std::string& question);
	std::string getQuestion() const override;

private:
	std::string question{};

};