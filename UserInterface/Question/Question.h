#pragma once
#include "../../ScheduleClasses/interfaces/ClassName.h"
#include "../VectorWithQuestionNotifier/VectorWithQuestionNotifier.h"
#include <string>

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
	void refillSelectionList(std::vector<T*> selectionList);

private:
	std::string _question;
	int _typeOfAnswer; 
	std::vector<ClassName*> _selectionList;
};

template<typename T>
inline Question::Question(const std::string& question, const int& typeOfAnswer, VectorWithQuestionNotifier<T*> selectionList) :
	_question(question),
	_typeOfAnswer(typeOfAnswer),
{
	refillSelectionList(selectionList);
}

#include <iostream>
template<typename T>
inline void Question::refillSelectionList(std::vector<T*> selectionList)
{
	//not productive
	_selectionList.clear();
	_selectionList.reserve(selectionList.size());
	for (auto& el : selectionList)
	{
		_selectionList.emplace_back(static_cast<ClassName*>(el));
	}
}
