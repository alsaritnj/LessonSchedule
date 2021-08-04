#include "SimpleSubjectCreator.h"

SimpleSubjectCreator::SimpleSubjectCreator(std::vector<Teacher*>& teacherList) :
	ÑlassInstanceCreatorAncestor
	({
		Question("Subject name", Question::enterableByUser),
		Question("Teacher in this subject", Question::existing, transformArrayOfPtrToArrayOfPtrOnClassName(teacherList.data(), teacherList.size()),teacherList.size()),
		Question("Custom nama of this object", Question::enterableByUser)
	})
{
}

void* SimpleSubjectCreator::create() const
{
	return static_cast<void*>(new SimpleSubject(subjectName, *teacher, customClassName));
}

void SimpleSubjectCreator::setAnswer(const short& index, void* answer)
{
	switch (index)
	{
	case 0 :
	{
		subjectName = *static_cast<std::string*>(answer);
		break;
	}
	case 1:
	{
		teacher = static_cast<Teacher*>(answer);
		break;
	}
	case 2:
	{
		customClassName = *static_cast<std::string*>(answer);
		break;
	}
	}
}

std::string SimpleSubjectCreator::nameOfCreatableClass() const
{
	return "SimpleSubject";
}
