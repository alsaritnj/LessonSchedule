#pragma once
#include <vector>
#include "../../interfaces/Publisher.h"

class SimplePublisher : public Publisher
{
public:
	virtual void notifySubscribers() const override;
	virtual void subscribe(const Observer* observer) override;
	virtual void unsubscribe(const Observer* observer) override;
protected:
	std::vector<const Observer*> observers;
};