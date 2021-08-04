#include "ÑlassInstanceCreatorAncestor.h"

ÑlassInstanceCreatorAncestor::ÑlassInstanceCreatorAncestor(const std::vector<Question>& questions) :
	questions(questions)
{
}
#include <iostream>//dell
ÑlassInstanceCreatorAncestor::~ÑlassInstanceCreatorAncestor()//dell
{
	std::cout << "~ÑlassInstanceCreatorAncestor" << std::endl;
	for (auto el : questions)
	{
		el.~Question();
	}
}

Question ÑlassInstanceCreatorAncestor::getQuestion(const short& index) const
{
	return questions[index];
}

unsigned ÑlassInstanceCreatorAncestor::getCountOfQuestions() const
{
	return questions.size();
}
