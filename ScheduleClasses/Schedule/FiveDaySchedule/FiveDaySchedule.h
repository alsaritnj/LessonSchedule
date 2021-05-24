#pragma once
#include "../../interfaces/Schedule.h"
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
class FiveDaySchedule : public Schedule
{
public:
<<<<<<< HEAD:Schedule/FiveDaySchedule/FiveDaySchedule.h
=======
	FiveDaySchedule();
	FiveDaySchedule(const std::initializer_list<DayFromSchedule*>& daysFromSchedule);
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/Schedule/FiveDaySchedule/FiveDaySchedule.h
	~FiveDaySchedule();

	DayFromSchedule& operator[](short int numberOfDay) override;
	void addDay(DayFromSchedule* added, const unsigned& numberOfDay);
	void addTeacher(Teacher* teacher) override;
	void addSubject(Subject* subject) override;
	void addClassroom(Classroom* classroom) override;
<<<<<<< HEAD:Schedule/FiveDaySchedule/FiveDaySchedule.h
	Teacher& getTeacher(const unsigned& index) override;
	Subject& getSubject(const unsigned& index) override;
	Classroom& getClassroom(const unsigned& index) override;
	void delTeacher(const unsigned& index);
	void delSubject(const unsigned& index);
	void delClassroom(const unsigned& index);
=======
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
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/Schedule/FiveDaySchedule/FiveDaySchedule.h

protected:
	std::vector<DayFromSchedule*> daysFromSchedule{ 5 };
	std::vector<Teacher*> teachers;
	std::vector<Subject*> subjects;
	std::vector<Classroom*> classrooms;

	inline void throwException(const bool& circumstance, const char* massage);
	template<typename T>
	inline void throwExceptionIfPtrIsNullptr(T* value);
<<<<<<< HEAD:Schedule/FiveDaySchedule/FiveDaySchedule.h
	template<typename T>
	inline void delPtrFromVect(std::vector<T*>& vec);
	
=======

private:
	std::vector<std::string> namesOfDays
	{
		"Monday",
		"Tuesday",
		"Wensday",
		"Thursday",
		"Friday"
	};
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/Schedule/FiveDaySchedule/FiveDaySchedule.h
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
