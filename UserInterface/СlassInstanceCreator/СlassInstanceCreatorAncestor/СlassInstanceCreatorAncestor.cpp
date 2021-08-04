#include "�lassInstanceCreatorAncestor.h"

�lassInstanceCreatorAncestor::�lassInstanceCreatorAncestor(const std::vector<Question>& questions) :
	questions(questions)
{
}
#include <iostream>//dell
�lassInstanceCreatorAncestor::~�lassInstanceCreatorAncestor()//dell
{
	std::cout << "~�lassInstanceCreatorAncestor" << std::endl;
	for (auto el : questions)
	{
		el.~Question();
	}
}

Question �lassInstanceCreatorAncestor::getQuestion(const short& index) const
{
	return questions[index];
}

unsigned �lassInstanceCreatorAncestor::getCountOfQuestions() const
{
	return questions.size();
}
