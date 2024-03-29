#pragma once
#include "../../—lassInstanceCreatorAncestor/—lassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Classroom/SimpleClassroom/SimpleClassroom.h"
#include "../../../Question/QuestionWithAnswerEnterableByUser/QuestionWithAnswerEnterableByUser.h"


class SimpleClassroomCreator : public —lassInstanceCreatorAncestor
{
public:
	SimpleClassroomCreator();
	void* create() const override;
	void setAnswer(const short& index, const std::string& answer) override;
	std::string nameOfCreatableClass() const;

protected:
	std::vector<std::string> answers{ 2 };
};