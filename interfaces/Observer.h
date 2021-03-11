#pragma once
#include "Publisher.h"
class Observer
{
public:
	virtual void notify() const = 0;
};