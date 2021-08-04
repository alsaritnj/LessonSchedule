#pragma once
#include "../../�lassInstanceCreatorAncestor/�lassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Teacher/TeacherName/TeacherName.h"

class TeacherNameCreator : public �lassInstanceCreatorAncestor
{
public:
	TeacherNameCreator();
	void* create() const override;
	void setAnswer(const short& index, void* answer) override;
	std::string nameOfCreatableClass() const;

protected:
	std::vector<std::string> answers{ 4 };
};