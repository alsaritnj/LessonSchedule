#pragma once
#include "../../interface/Question.h"
#include "../../../ScheduleClasses/interfaces/ClassName.h"
#include <vector>

class QuestionWithExistingAnswer : public Question
{
public:
	template<typename T>
	QuestionWithExistingAnswer(const std::string& question, const std::vector<T*>& selectionList);
	std::string getQuestion() const override;

private:
	std::string question{};
	std::vector<ClassName*> selectionList{};
};

template<typename T>
inline QuestionWithExistingAnswer::QuestionWithExistingAnswer(const std::string& question, const std::vector<T*>& selectionList) :
	question(question)
{
	this->selectionList.reserve(selectionList.size());
	for (size_t i = 0; i < selectionList.size(); i++)
	{
		this->selectionList[i] = static_cast<ClassName*>(selectionList[i]);
	}
}
