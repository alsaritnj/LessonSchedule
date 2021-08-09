#include "QuestionWithAnswerEnterableByUser.h"

QuestionWithAnswerEnterableByUser::QuestionWithAnswerEnterableByUser(const std::string& question) :
	question(question)
{}

std::string QuestionWithAnswerEnterableByUser::getQuestion() const
{
	return question;
}