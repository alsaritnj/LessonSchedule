#pragma once
#include "../../ÑlassInstanceCreatorAncestor/ÑlassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/LessonInSchedule/SimpleLessonInSchedule/SimpleLessonInSchedule.h"

class SimpleLessonInScheduleCreator : public ÑlassInstanceCreatorAncestor
{
public:
	SimpleLessonInScheduleCreator(VectorWithQuestionNotifier<Subject*>& subjectList, VectorWithQuestionNotifier<Classroom*>& classroomList);
	~SimpleLessonInScheduleCreator();
	void* create() const override;
	void setAnswer(const short& index, void* answer) override;
	std::string nameOfCreatableClass() const;

protected:
	Subject* subject{ nullptr };
	Classroom* classroom{ nullptr };
	short unsigned int numberInSchedule;
	std::string customClassName;
};