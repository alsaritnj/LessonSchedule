#pragma once
#include <string>
#include <vector>
#include "../../ScheduleClasses/interfaces/Teacher.h"
#include "../../ScheduleClasses/interfaces/Classroom.h"
#include "../../ScheduleClasses/interfaces/Subject.h"
#include "../../ScheduleClasses/interfaces/Schedule.h"

class FileSaver
{
public:
	virtual void save(std::vector<Teacher*>&, std::vector<Classroom*>&, std::vector<Subject*>&, Schedule*) const = 0;
	virtual void saveAs(const std::string&, std::vector<Teacher*>&, std::vector<Classroom*>&, std::vector<Subject*>&, Schedule*) const = 0;
};