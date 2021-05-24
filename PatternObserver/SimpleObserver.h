#pragma once
#include "../interfaces/Observer.h"
#include <vector>
#include <algorithm>

class SimpleObserver : public Observer
{
public:
	void notify(const Publisher* publisher);

protected:
	std::vector<Publisher*> trackedPublishers;
};