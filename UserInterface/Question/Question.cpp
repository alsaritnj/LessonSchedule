#include "Question.h"

Question::Question(const std::string& question, const int& typeOfAnswer) :
	_question(question),
	_typeOfAnswer(typeOfAnswer)
{}
Question::Question(const Question& other) :
	_question(other._question),
	_typeOfAnswer(other._typeOfAnswer),
	_selectionList(other._selectionList)
{
}

Question::Question(Question&& other)
{
	//доделай
}

Question::~Question()
{
	//доделайть
}

std::string Question::question() const
{
	return _question;
}

int Question::typeOfAnswer() const
{
	return _typeOfAnswer;
}

const ClassName* Question::objectFromSelectionList(const unsigned& index) const
{
	return const_cast<const ClassName*>(_selectionList[index]);
}

const size_t Question::sizeOfSelectionList() const
{
	return _selectionList.size();
}