#pragma once
#include "../../�lassInstanceCreatorAncestor/�lassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Classroom/SimpleClassroom/SimpleClassroom.h"


class SimpleClassroomCreator : public �lassInstanceCreatorAncestor
{
public:
	SimpleClassroomCreator();
	void* create() const override;
	void setAnswer(const short& index, void* answer) override;
	std::string nameOfCreatableClass() const;

protected:
	std::vector<std::string> answers{ 2 };
};