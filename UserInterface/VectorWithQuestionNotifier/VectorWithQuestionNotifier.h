// ага че

//#pragma once
//#include "../Question/Question.h"
//#include <vector>
//#include <algorithm>
//
//template<typename T>
//class VectorWithQuestionNotifier : public std::vector<T>
//{
//public:
//	VectorWithQuestionNotifier();
//	VectorWithQuestionNotifier(const std::vector<T>& vector);
//	VectorWithQuestionNotifier(std::vector<T>&& vector);
//	void addAndNotify(const unsigned& index, T&& value);
//	void addBackAndNotify(T&& value);
//	void dellAndNotify(const unsigned& index);
//	void subscribe(Question& subscriber);
//	void unsubscribe(Question& subscriber);
//
//private:
//	void notify();
//	std::vector<Question*> subscrubers;
//};
//
//template<typename T>
//inline VectorWithQuestionNotifier<T>::VectorWithQuestionNotifier() :
//	std::vector<T>{}
//{}
//
//template<typename T>
//inline VectorWithQuestionNotifier<T>::VectorWithQuestionNotifier(const std::vector<T>& vector) :
//	std::vector<T>(vector)
//{}
//
//template<typename T>
//inline VectorWithQuestionNotifier<T>::VectorWithQuestionNotifier(std::vector<T>&& vector) :
//	std::vector<T>(vector)
//{}
//
//template<typename T>
//inline void VectorWithQuestionNotifier<T>::addAndNotify(const unsigned& index, T&& value)
//{
//	this->emplace(index, value);
//	notify();
//}
//
//template<typename T>
//inline void VectorWithQuestionNotifier<T>::addBackAndNotify(T&& value)
//{
//	this->emplace_back(value);
//	notify();
//}
//
//template<typename T>
//inline void VectorWithQuestionNotifier<T>::dellAndNotify(const unsigned& index)
//{
//	//erase(index);
//	notify();
//}
//
//template<typename T>
//inline void VectorWithQuestionNotifier<T>::subscribe(Question& subscriber)
//{
//	subscrubers.emplace_back(&subscriber);
//}
//
//template<typename T>
//inline void VectorWithQuestionNotifier<T>::unsubscribe(Question& subscriber)
//{
//	//erase(find)
//}
//
//template<typename T>
//inline void VectorWithQuestionNotifier<T>::notify()
//{
//	for (auto el : subscrubers)
//	{
//		el->refillSelectionList(*static_cast<std::vector<T>*>(this));
//	}
//}
