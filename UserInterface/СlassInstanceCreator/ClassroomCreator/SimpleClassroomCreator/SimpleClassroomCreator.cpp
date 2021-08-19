#include "SimpleClassroomCreator.h"

SimpleClassroomCreator::SimpleClassroomCreator() : 
	ÑlassInstanceCreatorAncestor
	({
		new QuestionWithAnswerEnterableByUser("Number or name of classroom"),
		new QuestionWithAnswerEnterableByUser("Custom name of this object")
	})
{
}

void* SimpleClassroomCreator::create() const
{
	return new SimpleClassroom(answers[0], answers[1]);
}

void SimpleClassroomCreator::setAnswer(const short& index, const std::string& answer)
{
	answers[index] = answer;
}

std::string SimpleClassroomCreator::nameOfCreatableClass() const
{
	return "SimpleClassroom";
}

