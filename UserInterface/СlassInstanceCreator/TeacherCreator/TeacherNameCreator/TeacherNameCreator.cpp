#include "TeacherNameCreator.h"

TeacherNameCreator::TeacherNameCreator() :
	ÑlassInstanceCreatorAncestor
	({
		Question("Surname of teacher", Question::enterableByUser),
		Question("Name of teacher", Question::enterableByUser),
		Question("Patronymic of teacher", Question::enterableByUser),
		Question("Custom nama of this object", Question::enterableByUser)
	})
{
}

void* TeacherNameCreator::create() const
{
	return new TeacherName(answers[0], answers[1], answers[2], answers[3]);
}

void TeacherNameCreator::setAnswer(const short& index, void* answer)
{
	answers[index] = *static_cast<std::string*>(answer);
}

std::string TeacherNameCreator::nameOfCreatableClass() const
{
	return "TeacherName";
}
