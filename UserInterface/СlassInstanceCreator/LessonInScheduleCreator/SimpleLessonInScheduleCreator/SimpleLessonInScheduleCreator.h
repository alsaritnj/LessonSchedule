#pragma once
#include "../../ÑlassInstanceCreatorAncestor/ÑlassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/LessonInSchedule/SimpleLessonInSchedule/SimpleLessonInSchedule.h"
#include "../../../VectorOfClassNameObserver/VectorWithNotifier.h"
#include "../../../Question/QuestionWithAnswerEnterableByUser/QuestionWithAnswerEnterableByUser.h"
#include "../../../Question/QuestionWithExistingAnswer/QuestionWithExistingAnswer.h"

class SimpleLessonInScheduleCreator : public ÑlassInstanceCreatorAncestor
{
public:
	SimpleLessonInScheduleCreator(VectorWithNotifier<Subject*>& subjectList, VectorWithNotifier<Classroom*>& classroomList);
	~SimpleLessonInScheduleCreator();
	void* create() const override;
	void setAnswer(const short& index, const std::string& answer) override;
	std::string nameOfCreatableClass() const;

protected:
	Subject* subject{ nullptr };
	Classroom* classroom{ nullptr };
	short unsigned int numberInSchedule;
	std::string customClassName;

	std::vector<Subject*>& subjectList;
	std::vector<Classroom*>& classroomList;
};