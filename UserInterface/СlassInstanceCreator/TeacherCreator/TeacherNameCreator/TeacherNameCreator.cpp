#include "TeacherNameCreator.h"

TeacherNameCreator::TeacherNameCreator() :
	ÑlassInstanceCreatorAncestor
	({
		new QuestionWithAnswerEnterableByUser("Surname of teacher"),
		new QuestionWithAnswerEnterableByUser("Name of teacher"),
		new QuestionWithAnswerEnterableByUser("Patronymic of teacher"),
		new QuestionWithAnswerEnterableByUser("Custom nama of this object")
	})
{
}

void* TeacherNameCreator::create() const
{
	return new TeacherName(answers[0], answers[1], answers[2], answers[3]);
}

void TeacherNameCreator::setAnswer(const short& index, const std::string& answer)
{
	answers[index] = answer;
}

std::string TeacherNameCreator::nameOfCreatableClass() const
{
	return "TeacherName";
}
