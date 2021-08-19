#pragma once
#include "../../ÑlassInstanceCreatorAncestor/ÑlassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Teacher/TeacherName/TeacherName.h"
#include "../../../Question/QuestionWithAnswerEnterableByUser/QuestionWithAnswerEnterableByUser.h"

class TeacherNameCreator : public ÑlassInstanceCreatorAncestor
{
public:
	TeacherNameCreator();
	void* create() const override;
	void setAnswer(const short& index, const std::string& answer) override;
	std::string nameOfCreatableClass() const;

protected:
	std::vector<std::string> answers{ 4 };
};