#pragma once
#include "../../interfaces/Schedule.h"
#include "../../interfaces/DayFromSchedule.h"
#include "../../interfaces/Classroom.h"
#include "../../DayFromSchedule/SimpleDayFromSchedule/SimpleDayFromSchedule.h"
#include <vector>
class FiveDaySchedule : public Schedule
{
public:
	FiveDaySchedule(const std::string& customClassName = "");
	~FiveDaySchedule();

	const DayFromSchedule& operator[](const unsigned int& numberOfDay) const;
	DayFromSchedule& operator[](const unsigned int& numberOfDay);
	void addLessonInTheDay(const int& numberOfDay, LessonInSchedule* lesson) override;
	void delLessonFromTheDay(const int& numberOfDay, const int& numberOfLessonInSchedule) override;
	int getCountOfDay() override;

	std::string className() const override;
	std::string classContent() const override;

protected:
	std::vector<DayFromSchedule*> days
	{/*it seems to me that we will not use any other days except Simple, 
	 so there are no methods for changing the subtype of the day and we
	 declare everything hard here... YAGNI(i hope)*/
		new SimpleDayFromSchedule("Monday"),
		new SimpleDayFromSchedule("Tuesday"),
		new SimpleDayFromSchedule("Wednesday"),
		new SimpleDayFromSchedule("Thursday"),
		new SimpleDayFromSchedule("Friday")		
	};
};