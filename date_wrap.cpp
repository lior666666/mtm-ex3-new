#include "date_wrap.h"

//#1
DateWrap::DateWrap(int day, int month, int year)
{
    this->date = dateCreate(day, month, year);
    if(this->date == NULL)
    {
        throw InvalidDate(); 
    }
}

//#2
DateWrap::DateWrap(const DateWrap& date_wrap)
{
    this->date = dateCopy(date_wrap.date);
    if(this->date == NULL)
    {
        throw AllocationFailed(); 
    }
}

//#3
DateWrap::~DateWrap()
{
    dateDestroy(this->date);
}

//#4
DateWrap& DateWrap::operator=(const DateWrap& date_wrap)
{
    if(this == &date_wrap) {
		return *this;
	}
    Date copy_date = dateCopy(date_wrap.date);
    if(copy_date == NULL)
    {
        throw AllocationFailed(); // return to this point
    }
	dateDestroy(this->date);
	this->date = copy_date;
	return *this;
}

//#5
int DateWrap::day() const
{
    int day = 1;
    int month = 1;
    int year = 1;
    int* day_pointer = &day;
    int* month_pointer = &month;
    int* year_pointer = &year;
    dateGet(this->date, day_pointer, month_pointer, year_pointer);
    return *day_pointer;
}

//#6
int DateWrap::month() const
{
    int day = 1;
    int month = 1;
    int year = 1;
    int* day_pointer = &day;
    int* month_pointer = &month;
    int* year_pointer = &year;
    dateGet(this->date, day_pointer, month_pointer, year_pointer);
    return *month_pointer;
}

//#7
int DateWrap::year() const
{
    int day = 1;
    int month = 1;
    int year = 1;
    int* day_pointer = &day;
    int* month_pointer = &month;
    int* year_pointer = &year;
    dateGet(this->date, day_pointer, month_pointer, year_pointer);
    return *year_pointer;
}

//#8
ostream& operator<<(ostream& out, const DateWrap& date_wrap)
{
    out << date_wrap.day() << '/' << date_wrap.month() << '/' << date_wrap.year(); 
    return out;
}

//#9
bool operator==(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
{
	return dateCompare(date_wrap1.date, date_wrap2.date) == 0;
}

//#10
bool operator!=(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
{
    return !(date_wrap1 == date_wrap2);
}

//#11
bool operator<(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
{
    return dateCompare(date_wrap1.date, date_wrap2.date) < 0;
}

//#12
bool operator>=(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
{
    return !(date_wrap1 < date_wrap2);
}

//#13
bool operator>(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
{
    return date_wrap2 < date_wrap1;
}

//#14
bool operator<=(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
{
    return !(date_wrap1 > date_wrap2);
}

//#15
DateWrap DateWrap::operator++(int)
{
    DateWrap original_date = DateWrap(*this);
    dateTick(this->date);
    return original_date;
}

//#16
DateWrap& operator+=(DateWrap& date_wrap, int days)
{
    if(days < 0)
    {
        throw NegativeDays();
    }
    while (days != 0)
    {
        date_wrap++;
        days--;
    }
    return date_wrap;
}

//#17 
DateWrap operator+(const DateWrap& date_wrap, int days)
{  
   DateWrap temp_date = DateWrap(date_wrap);
   temp_date += days;
   return temp_date; 
}

//#18 
DateWrap operator+(int days, const DateWrap& date_wrap)
{
   operator+(date_wrap, days);
}



