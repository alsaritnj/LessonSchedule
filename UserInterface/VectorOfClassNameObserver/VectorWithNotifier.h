#pragma once
#include "NotifierForAnVectorOfClassName.h"

template<typename T>
class VectorWithNotifier : public std::vector<T>, public NotifierForAnVectorOfClassName
{
public:
	VectorWithNotifier();
	VectorWithNotifier(const std::vector<T>& vector);
	VectorWithNotifier(std::vector<T>&& vector);
	void addAndNotify(const unsigned& index, T&& value);
	void addBackAndNotify(T&& value);
	void delAndNotify(const unsigned& index);

protected:
	void notify();

};


template<typename T>
inline VectorWithNotifier<T>::VectorWithNotifier() : std::vector<T>{}
{
}

template<typename T>
inline VectorWithNotifier<T>::VectorWithNotifier(const std::vector<T>& vector) : std::vector<T>{ vector }
{
}

template<typename T>
inline VectorWithNotifier<T>::VectorWithNotifier(std::vector<T>&& vector) : std::vector<T>{ vector }
{
}

template<typename T>
inline void VectorWithNotifier<T>::addAndNotify(const unsigned& index, T&& value)
{
	this->emplace(index, value);
	notify();
}

template<typename T>
inline void VectorWithNotifier<T>::addBackAndNotify(T&& value)
{
	this->emplace_back(value);
	notify();
}

template<typename T>
inline void VectorWithNotifier<T>::delAndNotify(const unsigned& index)
{
	this->erase(this->begin() + index);
	notify();
}

template<typename T>
inline void VectorWithNotifier<T>::notify()
{
	for (auto& el : subscribers)
	{
		el->update(*this);
	}
}
