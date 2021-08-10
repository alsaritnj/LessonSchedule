#pragma once
#include "../../interface/�lassInstanceCreator.h"
#include <vector>

class �lassInstanceCreatorAncestor : public �lassInstanceCreator
{
public:
	�lassInstanceCreatorAncestor(const std::vector<Question*>& questions);
	~�lassInstanceCreatorAncestor();
	const Question& getQuestion(const short& index) const override;
	unsigned getCountOfQuestions() const override;

protected:
	std::vector<Question*> questions;
};