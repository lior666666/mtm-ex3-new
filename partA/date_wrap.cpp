#include "date_wrap.h"
//#1
DateWrap::DateWrap(int day, int month, int year)
 // not sure if this is the right way..
{
    date = dateCreate(day, month, year);
    if(date == NULL)
    {
        throw InvalidDate(); 
    }
}  

DateWrap::~DateWrap()
{
    dateDestroy(this->date);
}

//#3
ostream& operator<<(ostream& out, const DateWrap& date)
{
    out << date.day() << '/' << date.month() << '/' << date.year(); 
    return out;
}

//#5
DateWrap DateWrap::operator++(int)
{
    DateWrap temp_date = DateWrap(*this);
    dateTick(date);
    return temp_date; 
}

//#7 
DateWrap operator+(const DateWrap& date, int days)
{  
   DateWrap temp_date = DateWrap(date);
   temp_date += days;
   return temp_date; 
}
DateWrap operator+(int days, const DateWrap& date)
{
   operator+(date, days);
}



