#include "TeacherInitialsNameCreator.h"

TeacherInitialsNameCreator::TeacherInitialsNameCreator() : 
	ÑlassInstanceCreatorAncestor
	({
		new QuestionWithAnswerEnterableByUser("Surname of teacher"),
		new QuestionWithAnswerEnterableByUser("Name of teacher"),
		new QuestionWithAnswerEnterableByUser("Patronymic of teacher"),
		new QuestionWithAnswerEnterableByUser("Custom nama of this object")
	})
{
}

void* TeacherInitialsNameCreator::create() const
{
	return new TeacherInitialsName(answers[0], answers[1], answers[2], answers[3]);
}

void TeacherInitialsNameCreator::setAnswer(const short& index, const std::string& answer)
{
	answers[index] = answer;
}

std::string TeacherInitialsNameCreator::nameOfCreatableClass() const
{
	return "TeacherInitialsName";
}
