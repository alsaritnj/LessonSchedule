#include "SimpleDayFromSchedule.h"

SimpleDayFromSchedule::SimpleDayFromSchedule(std::initializer_list<const LessonInSchedule*> lessonsInSchedule, const std::string& customClassName)
{
	_customClassName = customClassName;
	this->lessonsInSchedule.reserve(lessonsInSchedule.size());
	for (auto& el : lessonsInSchedule)
		this->lessonsInSchedule.emplace_back(el);
	std::sort(this->lessonsInSchedule.begin(), this->lessonsInSchedule.end());
}

SimpleDayFromSchedule::~SimpleDayFromSchedule()
{
	for (const auto& el : lessonsInSchedule)
		delete el;
}

const LessonInSchedule& SimpleDayFromSchedule::operator[](const unsigned int& numberOfLessonInSchedule)
{
	std::vector<LessonInSchedule*>::iterator temp = std::find_if(lessonsInSchedule.begin(), lessonsInSchedule.end(),
		[numberOfLessonInSchedule](LessonInSchedule* a)
		{
			return numberOfLessonInSchedule == a->getNumberInSchedule();
		});
	if (temp == lessonsInSchedule.end())
			throw std::exception("The lesson under the number that was passed does not exist");
	else 
		return **temp;
}

void SimpleDayFromSchedule::add(const LessonInSchedule& added)
{
	for (const auto& el : lessonsInSchedule)
		if (el->getNumberInSchedule() == added.getNumberInSchedule())
			throw(std::exception("a lesson with the same number in the schedule as you tried to add already exists"));
	lessonsInSchedule.emplace_back(added);
	std::sort(this->lessonsInSchedule.begin(), this->lessonsInSchedule.end());
}

void SimpleDayFromSchedule::del(const unsigned int& numberOfLessonInSchedule)
{
	//���
	//������� ��� �� ����� �������� ���������, ��� ��� ������� ������� �� ������� � �������, � �� �� ������ � ����������(�� ���� ������ lessoninschedule)
	//�� ��������� � �������� ��� ��� ������� �����
	if (numberOfLessonInSchedule > lessonsInSchedule.size() + 1)
		throw(std::exception("Too large number of the lesson in the schedule"));
	delete lessonsInSchedule[numberOfLessonInSchedule - 1];
	lessonsInSchedule.erase(lessonsInSchedule.begin() + (numberOfLessonInSchedule - 1));
}

unsigned SimpleDayFromSchedule::countOfLessons() const 
{ 
	return lessonsInSchedule.size(); 
}

std::string SimpleDayFromSchedule::className() const
{
	return "Simple day from schedule";
}

std::string SimpleDayFromSchedule::classContent() const
{
	std::string result;
	result = "List of lessons in schedule";
	for (size_t i = 0; i < lessonsInSchedule.size(); i++)
	{
		result += "\n" + std::to_string(i) + ". " + lessonsInSchedule[i]->classContent();
	}

	return result;
}
