#pragma once
#include "../../interface/Question.h"
#include "../../VectorOfClassNameObserver/ObserverForAnVectorOfClassName.h"
#include "../../VectorOfClassNameObserver/VectorWithNotifier.h"

class QuestionWithExistingAnswer : public Question, public ObserverForAnVectorOfClassName
{
public:
	template<typename T>
	QuestionWithExistingAnswer(const std::string& question, VectorWithNotifier<T*>& selectionList);
	std::string getQuestion() const override;

private:
	std::string question{};
};

template<typename T>
inline QuestionWithExistingAnswer::QuestionWithExistingAnswer(const std::string& question, VectorWithNotifier<T*>& selectionList) :
	question(question)
{
	selectionList.subscribe(*this);
	this->vector.reserve(selectionList.size());
	for (size_t i = 0; i < selectionList.size(); i++)
	{
		this->vector[i] = static_cast<ClassName*>(selectionList[i]);
	}
}