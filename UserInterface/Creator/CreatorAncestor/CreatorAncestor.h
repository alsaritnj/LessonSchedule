#pragma once
#include "../../interface/Creator.h"
#include <vector>

class CreatorAncestor : public Creator
{
public:
	CreatorAncestor(const int& countOfParameters);
	virtual std::string getAsk(const int& index) override;
	virtual void setParameter(const int& index, void* parameter) override;
	virtual int getCountOfParameters() override;

protected:
	virtual const std::vector<std::string>& getAsks() = 0;
	void** parameters;
	int countOfParameters;
};