#include "SimplePublisher.h"

void SimplePublisher::notifySubscribers() const
{
	for (const auto& el : observers)
		el->notify(this);
}

void SimplePublisher::subscribe(const Observer* observer)
{
	this->observers.emplace_back(observer);
}

void SimplePublisher::unsubscribe(const Observer* observer)
{
	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
	if (it == this->observers.end())
		throw(std::exception("This publisher haven't this observer in subscribers"));
	this->observers.erase(it);
}

SimplePublisher::~SimplePublisher()
{
	notifySubscribers();
}
