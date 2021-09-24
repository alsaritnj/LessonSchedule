#include "FileSaverInString.h"
#include <iostream>
void FileSaverInString::save(std::vector<Teacher*>& teachers, std::vector<Classroom*>& classrooms, std::vector<Subject*>& subjects, Schedule* schedule) const
{
	if (path.empty())
	{
		throw std::exception("The path to save dos't select");
	}

	std::ofstream fout(path);

	fout << "teacher\n";
	writeToFileOneClassSegment(transformClassNameSubToSuper(teachers), fout, teachers, classrooms, subjects);
	fout << "classroom\n";
	writeToFileOneClassSegment(transformClassNameSubToSuper(classrooms), fout, teachers, classrooms, subjects);
	fout << "subject\n";
	writeToFileOneClassSegment(transformClassNameSubToSuper(subjects), fout, teachers, classrooms, subjects);
	//тут дописать дл€ Schedule

	fout.close();
}

void FileSaverInString::saveAs(const std::string& path, std::vector<Teacher*>& teachers, std::vector<Classroom*>& classrooms,	std::vector<Subject*>& subjects, Schedule* schedule) const
{
	this->path = path;
	save(teachers, classrooms, subjects, schedule);
}

//можно переделать к примеру на перегрузку функции или подумай еще чето тыж не тупой наверное-_-
// € там на строку выше пиздел про доху€ ненужных параметров
void FileSaverInString::writeToFileOneClassSegment(std::vector<ClassName*> classSegment, std::ofstream& fout, std::vector<Teacher*>& teachers, std::vector<Classroom*>& classrooms, std::vector<Subject*>& subjects) const
{
	std::stringstream tempStrS;
	std::string tempStr;
	std::stringstream tempStrS2;
	std::string tempStr2;
	std::string tempStr3;// а нахуй их так много. ну надо. ну тогда переделай или хот€бы переименуй. а ну или похуй, оставь
	long long addresOfClassRef;


	for (auto el : classSegment)
	{
		fout << el->className();
		tempStrS.clear();
		tempStrS << el->classContent();
		while (std::getline(tempStrS, tempStr, ' '))
		{
			if(tempStr.length() > 2 and tempStr[0] == EscSequenceToClassPtr[0] and tempStr[1] == EscSequenceToClassPtr[1] and tempStr[2] == EscSequenceToClassPtr[2])
			{
				tempStrS2.clear();
				tempStrS2 << tempStr;
				std::getline(tempStrS2, tempStr2, '_');//skip "&cl"
				std::getline(tempStrS2, tempStr2, '_');//read superclass
				std::getline(tempStrS2, tempStr3, '_');//read addres
				addresOfClassRef = std::stoll(tempStr3, nullptr, 16);
				
				// € гќ¬Ќќ ќƒ≈–
				if (tempStr2 == "teacher")
				{
					for (size_t i = 0; i < teachers.size(); i++)
					{
						tempStrS2.clear();
						tempStrS2 << teachers[i];
						getline(tempStrS2, tempStr2);
						if (addresOfClassRef == std::stoll(tempStr2, nullptr, 16))
						{
							fout << ' ' << EscSequenceToClassPtr << "_teacher_" << i;
							break;
						}
					}
					
				}
				else if (tempStr2 == "classroom")
				{
					for (size_t i = 0; i < classrooms.size(); i++)
					{
						tempStrS2.clear();
						tempStrS2 << classrooms[i];
						getline(tempStrS2, tempStr2);
						if (addresOfClassRef == std::stoll(tempStr2, nullptr, 16))
						{
							fout << ' ' << EscSequenceToClassPtr << "_classroom_" << i;
							break;
						}
					}
				}
				else if (tempStr2 == "subject")
				{
					for (size_t i = 0; i < subjects.size(); i++)
					{
						tempStrS2.clear();
						tempStrS2 << subjects[i];
						getline(tempStrS2, tempStr2);
						if (addresOfClassRef == std::stoll(tempStr2, nullptr, 16))
						{
							fout << ' ' << EscSequenceToClassPtr << "_subject_" << i;
							break;
						}
					}
				}
				continue;
			}

			fout << ' ' << tempStr;
		}
		fout << '\n';
	}
}
