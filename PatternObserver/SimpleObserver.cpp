#include "SimpleObserver.h"
void SimpleObserver::notify(const Publisher* publisher)
{
	std::find(trackedPublishers.begin(), trackedPublishers.end(), publisher).operator*()->unsubscribe(this);
}