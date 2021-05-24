#include "CreatorAncestor.h"

CreatorAncestor::CreatorAncestor(const int& countOfParameters)
{
    parameters = new void*[countOfParameters];
    this->countOfParameters = countOfParameters;
}

std::string CreatorAncestor::getAsk(const int& index)
{
    return getAsks()[index];
}

void CreatorAncestor::setParameter(const int& index, void* parameter)
{
    parameters[index] = parameter;
}

int CreatorAncestor::getCountOfParameters()
{
    return countOfParameters;
}
