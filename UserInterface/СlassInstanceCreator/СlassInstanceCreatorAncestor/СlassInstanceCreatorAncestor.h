#pragma once
#include "../../interface/ÑlassInstanceCreator.h"
#include <vector>

class ÑlassInstanceCreatorAncestor : public ÑlassInstanceCreator
{
public:
	ÑlassInstanceCreatorAncestor(const std::vector<Question*>& questions);
	~ÑlassInstanceCreatorAncestor();
	const Question& getQuestion(const short& index) const override;
	unsigned getCountOfQuestions() const override;

protected:
	std::vector<Question*> questions;
};