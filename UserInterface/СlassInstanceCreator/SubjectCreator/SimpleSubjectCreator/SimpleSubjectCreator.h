#pragma once
#include "../../ÑlassInstanceCreatorAncestor/ÑlassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Subject/SimpleSubject/SimpleSubject.h"

class SimpleSubjectCreator : public ÑlassInstanceCreatorAncestor
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