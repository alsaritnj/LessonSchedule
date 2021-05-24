#pragma once
#include "Publisher.h"
class Observer
{
public:
	virtual void notify(const Publisher* publisher) const = 0;
};