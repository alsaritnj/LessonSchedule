#pragma once
#include "Observer.h"
class Publisher
{
public:
	virtual void notifySubscribers() const = 0;
	virtual void subscribe(const Observer* observer) = 0;
	virtual void unsubscribe(const Observer* observer) = 0;
};