#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_
#include "exceptions.h"
extern "C" {
    #include "date.h"
}
namespace mtm{
    class DateWrap{ 
        Date date;
    public:
        /**
        * DateWrap: default empty constructor. 
        */
        DateWrap() = default;

        DateWrap(int day, int month, int year);

        /**
        * DateWrap: copy constructor. 
        * @param date - the DateWrap to copy.
        */
        DateWrap(const DateWrap& date);

        /**
        * ~DateWrap: destructor. Free the date.
        */
        ~DateWrap();

        /**
        * operator=: assignment operator. Takes the data from the given DateWrap to the current one.
        * @param date_wrap - the DateWrap to assign.
        */
        DateWrap& operator=(const DateWrap&);

        int day() const;

        int month() const;

        int year() const;

        friend bool operator==(const DateWrap& date1, const DateWrap& date2);

        friend bool operator<(const DateWrap& date1, const DateWrap& date2);

        friend DateWrap& operator+=(DateWrap& date, int days);

        DateWrap operator++(int);
    };

    DateWrap operator+(const DateWrap& date, int days);

    DateWrap operator+(int days, const DateWrap& date);

    std::ostream& operator<<(std::ostream& out, const DateWrap& date); 

    bool operator!=(const DateWrap& date1, const DateWrap& date2);

    bool operator<=(const DateWrap& date1, const DateWrap& date2);

    bool operator>(const DateWrap& date1, const DateWrap& date2);
    
    bool operator>=(const DateWrap& date1, const DateWrap& date2);
}
#endif