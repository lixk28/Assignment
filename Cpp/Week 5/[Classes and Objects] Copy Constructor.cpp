#include <iostream>
using namespace std;

class Date {
	public:
		Date(int newYear, int newMonth, int newDay);
		int getYear() const;
		void setYear(int newYear);
		int getMonth() const;
		void setMonth(int);
		int getDay() const;
		void setDay(int);

	private:
		int year;
		int month;
		int day;
};

Date::Date(int newYear, int newMonth, int newDay)
{
    year = newYear;
    month = newMonth;
    day = newDay;
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

void Date::setYear(int newYear) { year = newYear; }
void Date::setMonth(int newMonth) { month = newMonth; }
void Date::setDay(int newDay) { day = newDay; }


class Person {
	public:
		Person(int _id, int year, int month, int day);
		Person(const Person &); // copy constructor
		~Person();
		int getId() const;
		Date * getBirthDate() const;

	private:
		int id;
		Date *birthDate;
};

Person::Person(int _id, int year, int month, int day)
{
    id = _id;
    birthDate = new Date(year, month ,day);
}

Person::Person(const Person &p)
{
    id = p.id;
    birthDate = new Date(p.birthDate->getYear(), p.birthDate->getMonth(), p.birthDate->getDay());
}

Person::~Person()
{
    delete birthDate;
}

int Person::getId() const
{
    return id;
}

Date* Person::getBirthDate() const
{
    return birthDate;
}