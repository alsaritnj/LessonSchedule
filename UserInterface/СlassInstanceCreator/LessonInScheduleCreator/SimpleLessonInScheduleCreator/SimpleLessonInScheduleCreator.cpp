#include "SimpleLessonInScheduleCreator.h"

SimpleLessonInScheduleCreator::SimpleLessonInScheduleCreator(std::vector<Subject*>& subjectList, std::vector<Classroom*>& classroomList) :
	ÑlassInstanceCreatorAncestor
	({
		Question("Subject", Question::existing, subjectList.data(), subjectList.size()),
		Question("Classroom", Question::existing, classroomList.data(), classroomList.size()),
		Question("NumberInSchedule", Question::enterableByUser),
		Question("Custom nama of this object", Question::enterableByUser)
	})
{}
#include <iostream>//dell
SimpleLessonInScheduleCreator::~SimpleLessonInScheduleCreator()//dell
{
	std::cout << "~SimpleLessonInScheduleCreator" << std::endl;
}

void* SimpleLessonInScheduleCreator::create() const
{
	return new SimpleLessonInSchedule(*subject, *classroom, numberInSchedule, customClassName);
}

void SimpleLessonInScheduleCreator::setAnswer(const short& index, void* answer)
{
	switch (index)
	{
	case 0:
	{
		subject = static_cast<Subject*>(answer);
		break;
	}
	case 1 :
	{
		classroom = static_cast<Classroom*>(answer);
		break;
	}
	case 2:
	{
		numberInSchedule = std::atoi(static_cast<std::string*>(answer)->c_str());
		break;
	}
	case 3:
	{
		customClassName = *static_cast<std::string*>(answer);
		break;
	}
	}
}

std::string SimpleLessonInScheduleCreator::nameOfCreatableClass() const
{
	return "SimpleLessonInSchedule";
}
