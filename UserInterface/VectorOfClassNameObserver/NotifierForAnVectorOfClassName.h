#pragma once
#include "ObserverForAnVectorOfClassName.h"
#include <algorithm>


class NotifierForAnVectorOfClassName
{
public:
	virtual void subscribe(ObserverForAnVectorOfClassName& subscriber);
	virtual void unsubscribe(ObserverForAnVectorOfClassName& subscriber);
	virtual void notify() = 0;

protected:
	std::vector<ObserverForAnVectorOfClassName*> subscribers;
};