#include "QuestionWithExistingAnswer.h"

std::string QuestionWithExistingAnswer::getQuestion() const
{
	/*
	* можно сделать более производительно, если сделать поле, в котором будет эта срока
	* когда нужно(к примеру, если selectionList был обновлен) этот метод будет перезаписывать строку
	*/
	std::string tempString = "Choose one of the object:";
	for (size_t i = 0; i < vector.size(); i++)
	{
		//fuck the efficiency :(
		tempString += "\n" + std::to_string(i) + ". " + vector[i]->className() + " " + vector[i]->customClassName();
	}
	return tempString;
}
