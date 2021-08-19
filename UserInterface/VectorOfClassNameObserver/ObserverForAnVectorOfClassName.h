#pragma once
#include "../../ScheduleClasses/interfaces/ClassName.h"
#include <vector>

class ObserverForAnVectorOfClassName
{
public:
	template<typename T>
	void update(std::vector<T> vector);

protected:
	std::vector<ClassName*> vector;

};

template<typename T>
inline void ObserverForAnVectorOfClassName::update(std::vector<T> vector)
{
	this->vector.clear();
	this->vector.reserve(vector.size());
	for (auto& el : vector)
	{
		this->vector.emplace_back(el);
	}
}
