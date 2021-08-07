// читай в источнике *ссылка на IQuestion*
#pragma once
#include "../../ScheduleClasses/interfaces/ClassName.h"
//#include "../VectorWithQuestionNotifier/VectorWithQuestionNotifier.h" так да переделай 2й раз пишу
#include <string>

template<typename T>
class VectorWithQuestionNotifier;// сука мудак лнивый нет я не ленивый я задолбался стоять на месте

class Question
{
public:
	static enum TypeOfAnswer
	{
		enterableByUser,
		existing
	};

	Question(const std::string& question, const int& typeOfAnswer);
	template<typename T>
	Question(const std::string& qestion, const int& typeOfAnswer, VectorWithQuestionNotifier<T*>& selectionList);
	Question(const Question& other);
	Question(Question&& other);
	~Question();
	std::string question() const;
	int typeOfAnswer() const;
	const ClassName* objectFromSelectionList(const unsigned& index) const;
	const size_t sizeOfSelectionList() const;
	template<typename T>
	void refillSelectionList(VectorWithQuestionNotifier<T*>& selectionList);

private:
	std::string _question;
	int _typeOfAnswer; 
	VectorWithQuestionNotifier<ClassName*>& _selectionList;
};

template<typename T>
inline Question::Question(const std::string& qestion, const int& typeOfAnswer, VectorWithQuestionNotifier<T*>& selectionList) :
	_question(question),
	_typeOfAnswer(typeOfAnswer),
{
	refillSelectionList(selectionList);
}

template<typename T>
inline void Question::refillSelectionList(VectorWithQuestionNotifier<T*>& selectionList)
{
	//not productive
	_selectionList.clear();
	_selectionList.reserve(selectionList.size());
	for (auto& el : selectionList)
	{
		_selectionList.emplace_back(static_cast<ClassName*>(el));
	}
}









//ну ты понял уже да? нет даун.
#include <vector>
#include <algorithm>

template<typename T>
class VectorWithQuestionNotifier : public std::vector<T>
{
public:
	VectorWithQuestionNotifier();
	VectorWithQuestionNotifier(const std::vector<T>& vector);
	VectorWithQuestionNotifier(std::vector<T>&& vector);
	void addAndNotify(const unsigned& index, T&& value);
	void addBackAndNotify(T&& value);
	void dellAndNotify(const unsigned& index);
	void subscribe(Question& subscriber);
	void unsubscribe(Question& subscriber);

private:
	void notify();
	std::vector<Question*> subscrubers;
};

template<typename T>
inline VectorWithQuestionNotifier<T>::VectorWithQuestionNotifier() :
	std::vector<T>{}
{}

template<typename T>
inline VectorWithQuestionNotifier<T>::VectorWithQuestionNotifier(const std::vector<T>& vector) :
	std::vector<T>(vector)
{}

template<typename T>
inline VectorWithQuestionNotifier<T>::VectorWithQuestionNotifier(std::vector<T>&& vector) :
	std::vector<T>(vector)
{}

template<typename T>
inline void VectorWithQuestionNotifier<T>::addAndNotify(const unsigned& index, T&& value)
{
	this->emplace(index, value);
	notify();
}

template<typename T>
inline void VectorWithQuestionNotifier<T>::addBackAndNotify(T&& value)
{
	this->emplace_back(value);
	notify();
}

template<typename T>
inline void VectorWithQuestionNotifier<T>::dellAndNotify(const unsigned& index)
{
	//erase(index);
	notify();
}

template<typename T>
inline void VectorWithQuestionNotifier<T>::subscribe(Question& subscriber)
{
	subscrubers.emplace_back(&subscriber);
}

template<typename T>
inline void VectorWithQuestionNotifier<T>::unsubscribe(Question& subscriber)
{
	//erase(find)
}

template<typename T>
inline void VectorWithQuestionNotifier<T>::notify()
{
	for (auto el : subscrubers)
	{
		el->refillSelectionList(*static_cast<std::vector<T>*>(this));
	}
}
