#include "�lassInstanceCreatorAncestor.h"

�lassInstanceCreatorAncestor::�lassInstanceCreatorAncestor(const std::vector<Question*>& questions) :
	questions(questions)
{
}

�lassInstanceCreatorAncestor::~�lassInstanceCreatorAncestor()
{

	for (auto el : questions)
	{
		delete el;
	}
}

const Question& �lassInstanceCreatorAncestor::getQuestion(const short& index) const
{
	return *questions[index];
}

unsigned �lassInstanceCreatorAncestor::getCountOfQuestions() const
{
	return questions.size();
}
