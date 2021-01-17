#include "date_wrap.h"

const char DATE_SIGN = '/';
const int DEFAULT_POSITIVE_NUMBER = 1;

namespace mtm
{
    DateWrap::DateWrap(int day, int month, int year)
    {
        date = dateCreate(day, month, year);
        if(date == NULL)
        {
            throw InvalidDate();
        }
    }

    DateWrap::DateWrap(const DateWrap& date_wrap)
    {
        date = dateCopy(date_wrap.date);
    }

    DateWrap::~DateWrap()
    {
        dateDestroy(date);
    }

    DateWrap& DateWrap::operator=(const DateWrap& date_wrap)
    {
        if(this == &date_wrap) {
            return *this;
        }
        Date copy_date = dateCopy(date_wrap.date);
        dateDestroy(date);
        date = copy_date;
        return *this;
    }

    int DateWrap::day() const
    {
        int day = DEFAULT_POSITIVE_NUMBER;
        int month = DEFAULT_POSITIVE_NUMBER;
        int year = DEFAULT_POSITIVE_NUMBER;
        int* day_pointer = &day;
        int* month_pointer = &month;
        int* year_pointer = &year;
        dateGet(date, day_pointer, month_pointer, year_pointer);
        return *day_pointer;
    }

    int DateWrap::month() const
    {
        int day = DEFAULT_POSITIVE_NUMBER;
        int month = DEFAULT_POSITIVE_NUMBER;
        int year = DEFAULT_POSITIVE_NUMBER;
        int* day_pointer = &day;
        int* month_pointer = &month;
        int* year_pointer = &year;
        dateGet(date, day_pointer, month_pointer, year_pointer);
        return *month_pointer;
    }

    int DateWrap::year() const
    {
        int day = DEFAULT_POSITIVE_NUMBER;
        int month = DEFAULT_POSITIVE_NUMBER;
        int year = DEFAULT_POSITIVE_NUMBER;
        int* day_pointer = &day;
        int* month_pointer = &month;
        int* year_pointer = &year;
        dateGet(date, day_pointer, month_pointer, year_pointer);
        return *year_pointer;
    }

    std::ostream& operator<<(std::ostream& out, const DateWrap& date_wrap)
    {
        out << date_wrap.day() << DATE_SIGN << date_wrap.month() << DATE_SIGN << date_wrap.year(); 
        return out;
    }

    bool operator==(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
    {
        return dateCompare(date_wrap1.date, date_wrap2.date) == 0;
    }

    bool operator!=(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
    {
        return !(date_wrap1 == date_wrap2);
    }

    bool operator<(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
    {
        return dateCompare(date_wrap1.date, date_wrap2.date) < 0;
    }

    bool operator>=(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
    {
        return !(date_wrap1 < date_wrap2);
    }

    bool operator>(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
    {
        return date_wrap2 < date_wrap1;
    }

    bool operator<=(const DateWrap& date_wrap1, const DateWrap& date_wrap2)
    {
        return !(date_wrap1 > date_wrap2);
    }

    DateWrap DateWrap::operator++(int)
    {
        DateWrap original_date = DateWrap(*this);
        dateTick(date);
        return original_date;
    }

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

    DateWrap operator+(const DateWrap& date_wrap, int days)
    {  
        DateWrap temp_date = DateWrap(date_wrap);
        temp_date += days;
        return temp_date; 
    }

    DateWrap operator+(int days, const DateWrap& date_wrap)
    {
        return operator+(date_wrap, days);
    }
}