#include "ÑlassInstanceCreatorAncestor.h"

ÑlassInstanceCreatorAncestor::ÑlassInstanceCreatorAncestor(const std::vector<Question*>& questions) :
	questions(questions)
{
}

ÑlassInstanceCreatorAncestor::~ÑlassInstanceCreatorAncestor()
{

	for (auto el : questions)
	{
		delete el;
	}
}

const Question& ÑlassInstanceCreatorAncestor::getQuestion(const short& index) const
{
	return *questions[index];
}

unsigned ÑlassInstanceCreatorAncestor::getCountOfQuestions() const
{
	return questions.size();
}
