#pragma once
#include "../../interfaces/Schedule.h"
#include "../../interfaces/DayFromSchedule.h"
#include "../../interfaces/Classroom.h"
#include <vector>
class FiveDaySchedule : public Schedule
{
public:
	FiveDaySchedule(const std::string& customClassName = "");
	FiveDaySchedule(const std::initializer_list<DayFromSchedule*>& daysFromSchedule, const std::string& customClassName = "");
	~FiveDaySchedule();

	DayFromSchedule& operator[](short int numberOfDay) override;
	void addDay(DayFromSchedule* added, const unsigned& numberOfDay);
	void addTeacher(Teacher* teacher) override;
	void addSubject(Subject* subject) override;
	void addClassroom(Classroom* classroom) override;

	const Teacher& getTeacher(const unsigned& index) const override;
	const Subject& getSubject(const unsigned& index) const override;
	const Classroom& getClassroom(const unsigned& index) const override;

	const size_t countOfTeachers();
	const size_t countOfSubjects();
	const size_t countOfClassrooms();

	void delTeacher(const unsigned& index) override;
	void delSubject(const unsigned& index) override;
	void delClassroom(const unsigned& index) override;

	std::string getNameOfDay(int numberOfDay) override;
	int getCountOfDay() override;

	std::string className() const override;
	std::string classContent() const override;

protected:
	std::vector<DayFromSchedule*> daysFromSchedule{ 5 };
	std::vector<Teacher*> teachers;
	std::vector<Subject*> subjects;
	std::vector<Classroom*> classrooms;

	inline void throwException(const bool& circumstance, const char* massage);
	template<typename T>
	inline void throwExceptionIfPtrIsNullptr(T* value);
	template<typename T>
	inline void delPtrFromVect(std::vector<T*>& vec);
	

private:
	std::vector<std::string> namesOfDays
	{
		"Monday",
		"Tuesday",
		"Wensday",
		"Thursday",
		"Friday"
	};
};

template<typename T>
inline void FiveDaySchedule::throwExceptionIfPtrIsNullptr(T* value)
{
	throwException(value == nullptr, "Value can't be nullptr");
}

template<typename T>
inline void FiveDaySchedule::delPtrFromVect(std::vector<T*>& vec)
{
	for (const auto& el : vec)
		delete el;
}
