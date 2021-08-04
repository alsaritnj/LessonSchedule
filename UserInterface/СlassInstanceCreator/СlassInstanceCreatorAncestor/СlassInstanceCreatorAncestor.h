#pragma once
#include "../../interface/�lassInstanceCreator.h"

class �lassInstanceCreatorAncestor : public �lassInstanceCreator
{
public:
	�lassInstanceCreatorAncestor(const std::vector<Question>& questions);
	~�lassInstanceCreatorAncestor();
	Question getQuestion(const short& index) const override;
	unsigned getCountOfQuestions() const override;

protected:
	std::vector<Question> questions;
};