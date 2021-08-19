#pragma once
#include "../../ÑlassInstanceCreatorAncestor/ÑlassInstanceCreatorAncestor.h"
#include "../../../../ScheduleClasses/Subject/SimpleSubject/SimpleSubject.h"
#include "../../../VectorOfClassNameObserver/VectorWithNotifier.h"
#include "../../../Question/QuestionWithAnswerEnterableByUser/QuestionWithAnswerEnterableByUser.h"
#include "../../../Question/QuestionWithExistingAnswer/QuestionWithExistingAnswer.h"

class SimpleSubjectCreator : public ÑlassInstanceCreatorAncestor
{
public:
	SimpleSubjectCreator(VectorWithNotifier<Teacher*>& teacherList);
	void* create() const override;
	void setAnswer(const short& index, const std::string& answer) override;
	std::string nameOfCreatableClass() const;
private:
	std::string subjectName{};
	Teacher* teacher{ nullptr };
	std::string customClassName{};

	std::vector<Teacher*>& teacherList;
};