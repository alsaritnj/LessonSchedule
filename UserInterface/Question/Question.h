#pragma once
#include "../../ScheduleClasses/interfaces/ClassName.h"
#include <string>
#include <vector>

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
	void resetSelectionList(T** selectionList, const size_t& sizeOfSelectionList);


private:
	std::string _question;
	int _typeOfAnswer; 
	ClassName** _selectionList{ nullptr };
	size_t _sizeOfSelectionList;
};