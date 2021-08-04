#pragma once
#include "../../�lassInstanceCreatorAncestor/�lassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Teacher/TeacherInitialsName/TeacherInitialsName.h"

class TeacherInitialsNameCreator : public �lassInstanceCreatorAncestor
{
public:
	TeacherInitialsNameCreator();
	void* create() const override;
	void setAnswer(const short& index, void* answer) override;
	std::string nameOfCreatableClass() const;

protected:
	std::vector<std::string> answers{ 4 };
};