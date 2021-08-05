#pragma once
#include "../../ScheduleClasses/interfaces/ClassName.h"
#include <string>
#include <vector>


#include "../../ScheduleClasses/interfaces/Teacher.h"

class Question
{
public:
	static enum TypeOfAnswer
	{
		enterableByUser,
		existing
	};

	Question(const std::string& _question, const int& _typeOfAnswer);
	template<typename T>
	Question(const std::string& _question, const int& _typeOfAnswer, T** selectionList, const size_t& sizeOfSelectionList);
	Question(const Question& other);
	Question(Question&& other);
	~Question();
	std::string question() const;
	int typeOfAnswer() const;
	const ClassName* objectFromSelectionList(const unsigned& index) const;
	const size_t sizeOfSelectionList() const;
	template<typename T>
	void refillSelectionList(T** selectionList, const size_t& sizeOfSelectionList);

private:
	std::string _question;
	int _typeOfAnswer; 
	ClassName** _selectionList{ nullptr };
	size_t _sizeOfSelectionList{ 0 };
};

template<typename T>
inline Question::Question(const std::string& question, const int& typeOfAnswer, T** selectionList, const size_t& sizeOfSelectionList) :
	_question(question),
	_typeOfAnswer(typeOfAnswer),
	_sizeOfSelectionList(sizeOfSelectionList)
{
	refillSelectionList(selectionList, sizeOfSelectionList);
}

template<typename T>
inline void Question::refillSelectionList(T** selectionList, const size_t& sizeOfSelectionList)
{
	delete _selectionList;
	_selectionList = new ClassName * [sizeOfSelectionList];
	for (size_t i = 0; i < sizeOfSelectionList; i++)
	{
		_selectionList[i] = static_cast<ClassName*>(selectionList[i]);
	}	
}
