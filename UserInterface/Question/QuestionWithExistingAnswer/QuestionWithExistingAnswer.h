#pragma once
#include "../../interface/Question.h"
#include "../../VectorOfClassNameObserver/ObserverForAnVectorOfClassName.h"

class QuestionWithExistingAnswer : public Question, public ObserverForAnVectorOfClassName
{
public:
	template<typename T>
	QuestionWithExistingAnswer(const std::string& question, const std::vector<T*>& selectionList);
	std::string getQuestion() const override;

private:
	std::string question{};
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
