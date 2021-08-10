#include "NotifierForAnVectorOfClassName.h"

void NotifierForAnVectorOfClassName::subscribe(ObserverForAnVectorOfClassName& subscriber)
{
	subscribers.emplace_back(&subscriber);
}

void NotifierForAnVectorOfClassName::unsubscribe(ObserverForAnVectorOfClassName& subscriber)
{
	//doet it work?
	subscribers.erase(std::find_if(subscribers.begin(), subscribers.end(), [subscriber](ObserverForAnVectorOfClassName* cn)
		{
			return cn == &subscriber;
		}));
}