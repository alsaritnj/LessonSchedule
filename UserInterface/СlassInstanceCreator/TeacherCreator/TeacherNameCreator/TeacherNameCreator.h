#pragma once
#include "../../�lassInstanceCreatorAncestor/�lassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Teacher/TeacherName/TeacherName.h"
#include "../../../Question/QuestionWithAnswerEnterableByUser/QuestionWithAnswerEnterableByUser.h"

class TeacherNameCreator : public �lassInstanceCreatorAncestor
{
public:
	TeacherNameCreator();
	void* create() const override;
	void setAnswer(const short& index, const std::string& answer) override;
	std::string nameOfCreatableClass() const;

protected:
	std::vector<std::string> answers{ 4 };
};