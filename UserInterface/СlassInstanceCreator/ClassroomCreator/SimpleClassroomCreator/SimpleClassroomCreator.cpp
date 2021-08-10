#include "SimpleClassroomCreator.h"

SimpleClassroomCreator::SimpleClassroomCreator() : 
	—lassInstanceCreatorAncestor
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

void SimpleClassroomCreator::setAnswer(const short& index, void* answer)
{
	answers[index] = *static_cast<std::string*>(answer);
}

std::string SimpleClassroomCreator::nameOfCreatableClass() const
{
	return "SimpleClassroom";
}

