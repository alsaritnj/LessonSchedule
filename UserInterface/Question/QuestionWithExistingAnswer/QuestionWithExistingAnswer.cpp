#include "QuestionWithExistingAnswer.h"

std::string QuestionWithExistingAnswer::getQuestion() const
{
	/*
	* ����� ������� ����� ���������������, ���� ������� ����, � ������� ����� ��� �����
	* ����� �����(� �������, ���� selectionList ��� ��������) ���� ����� ����� �������������� ������
	*/
	std::string tempString = "Choose one of the object:";
	for (size_t i = 0; i < selectionList.size(); i++)
	{
		//fuck the efficiency :(
		tempString += "\n" + std::to_string(i) + ". " + selectionList[i]->className() + " " + selectionList[i]->customClassName();
	}
	return tempString;
}
