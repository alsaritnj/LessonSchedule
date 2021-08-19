#include "SimpleSubjectCreator.h"

SimpleSubjectCreator::SimpleSubjectCreator(VectorWithNotifier<Teacher*>& teacherList) :
	ÑlassInstanceCreatorAncestor
	({
		new QuestionWithAnswerEnterableByUser("Subject name"),
		new QuestionWithExistingAnswer("Teacher in this subject", teacherList),
		new QuestionWithAnswerEnterableByUser("Custom nama of this object")
	}),
	teacherList{ teacherList }
{
}

void* SimpleSubjectCreator::create() const
{
	return static_cast<void*>(new SimpleSubject(subjectName, *teacher, customClassName));
}

void SimpleSubjectCreator::setAnswer(const short& index, const std::string& answer)
{
	switch (index)
	{
	case 0 :
	{
		subjectName = answer;
		break;
	}
	case 1:
	{
		teacher = teacherList[std::atoi(answer.c_str())];
		break;
	}
	case 2:
	{
		customClassName = answer;
		break;
	}
	}
}

std::string SimpleSubjectCreator::nameOfCreatableClass() const
{
	return "SimpleSubject";
}
