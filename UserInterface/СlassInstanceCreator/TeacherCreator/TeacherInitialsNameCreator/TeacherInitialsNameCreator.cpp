#include "TeacherInitialsNameCreator.h"

TeacherInitialsNameCreator::TeacherInitialsNameCreator() : 
	ÑlassInstanceCreatorAncestor
	({
		Question("Surname of teacher", Question::enterableByUser),
		Question("Name of teacher", Question::enterableByUser),
		Question("Patronymic of teacher", Question::enterableByUser),
		Question("Custom nama of this object", Question::enterableByUser)
	})
{
}

void* TeacherInitialsNameCreator::create() const
{
	return new TeacherInitialsName(answers[0], answers[1], answers[2], answers[3]);
}

void TeacherInitialsNameCreator::setAnswer(const short& index, void* answer)
{
	answers[index] = *static_cast<std::string*>(answer);
}

std::string TeacherInitialsNameCreator::nameOfCreatableClass() const
{
	return "TeacherInitialsName";
}
