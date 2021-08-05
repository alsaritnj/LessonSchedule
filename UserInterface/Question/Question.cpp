#include "Question.h"

Question::Question(const std::string& question, const int& typeOfAnswer) :
	_question(question),
	_typeOfAnswer(typeOfAnswer)
{}
Question::Question(const Question& other) :
	_question(other._question),
	_typeOfAnswer(other._typeOfAnswer),
	_sizeOfSelectionList(other._sizeOfSelectionList),
	_selectionList(other._selectionList == nullptr ? nullptr : new ClassName * [other._sizeOfSelectionList])
{
	
	if (other._selectionList != nullptr)
	{
		for (size_t i = 0; i < _sizeOfSelectionList; i++)
		{
			this->_selectionList[i] = other._selectionList[i];
		}
	}
}

Question::Question(Question&& other)
{
	//доделай
}

Question::~Question()
{
	//we do not dispose of concrete ClassName objects and therefore do not delete them 
	delete _selectionList;
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
	return _sizeOfSelectionList;
}