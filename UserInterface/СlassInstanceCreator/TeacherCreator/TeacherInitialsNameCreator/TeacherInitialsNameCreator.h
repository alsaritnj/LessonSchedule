#pragma once
#include "../../�lassInstanceCreatorAncestor/�lassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Teacher/TeacherInitialsName/TeacherInitialsName.h"
#include "../../../Question/QuestionWithAnswerEnterableByUser/QuestionWithAnswerEnterableByUser.h"

class TeacherInitialsNameCreator : public �lassInstanceCreatorAncestor
{
public:
	TeacherInitialsNameCreator();
	void* create() const override;
	void setAnswer(const short& index, const std::string& answer) override;
	std::string nameOfCreatableClass() const;

protected:
	std::vector<std::string> answers{ 4 };
};