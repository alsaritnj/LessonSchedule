#pragma once
#include "../../�lassInstanceCreatorAncestor/�lassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Subject/SimpleSubject/SimpleSubject.h"

class SimpleSubjectCreator : public �lassInstanceCreatorAncestor
{
public:
	SimpleSubjectCreator(std::vector<Teacher*>& teacherList);
	void* create() const override;
	void setAnswer(const short& index, void* answer) override;
	std::string nameOfCreatableClass() const;
private:
	std::string subjectName{};
	Teacher* teacher{ nullptr };
	std::string customClassName{};
};