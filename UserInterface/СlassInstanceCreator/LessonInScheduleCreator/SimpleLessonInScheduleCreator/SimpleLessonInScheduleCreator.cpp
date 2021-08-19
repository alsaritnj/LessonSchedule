#include "SimpleLessonInScheduleCreator.h"

SimpleLessonInScheduleCreator::SimpleLessonInScheduleCreator(VectorWithNotifier<Subject*>& subjectList, VectorWithNotifier<Classroom*>& classroomList) :
	ÑlassInstanceCreatorAncestor
	({
		new QuestionWithExistingAnswer("Subject", subjectList),
		new QuestionWithExistingAnswer("Classroom", classroomList),
		new QuestionWithAnswerEnterableByUser("NumberInSchedule"),
		new QuestionWithAnswerEnterableByUser("Custom nama of this object")
	}),
	subjectList{ subjectList },
	classroomList{ classroomList }
{}

SimpleLessonInScheduleCreator::~SimpleLessonInScheduleCreator()
{
}

void* SimpleLessonInScheduleCreator::create() const
{
	return new SimpleLessonInSchedule(*subject, *classroom, numberInSchedule, customClassName);
}

void SimpleLessonInScheduleCreator::setAnswer(const short& index, const std::string& answer)
{
	switch (index)
	{
	case 0:
	{
		subject = subjectList[std::atoi(answer.c_str())];
		break;
	}
	case 1 :
	{
		classroom = classroomList[std::atoi(answer.c_str())];
		break;
	}
	case 2:
	{
		numberInSchedule = std::atoi(answer.c_str());
		break;
	}
	case 3:
	{
		customClassName = answer;
		break;
	}
	}
}

std::string SimpleLessonInScheduleCreator::nameOfCreatableClass() const
{
	return "SimpleLessonInSchedule";
}
