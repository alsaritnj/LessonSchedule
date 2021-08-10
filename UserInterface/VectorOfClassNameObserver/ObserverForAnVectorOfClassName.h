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
	this->vector.reserve(vector.size());
	for (size_t i = 0; i < vector.size(); i++)
	{
		this->vector[i] = static_cast<ClassName*>(vector[i]);
	}
}
