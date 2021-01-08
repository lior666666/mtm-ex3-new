#include <iostream> 
#include "exceptions.h"
extern "C" {
    #include "date.h"
}
namespace mtm{
    class DateWrap : public mtm::Exception{ 
        Date date;
    public:
        DateWrap(int day, int month, int year);
        DateWrap(const DateWrap& date);
        ~DateWrap();
        DateWrap& operator=(const DateWrap&);
        int day() const;
        int month() const;
        int year() const;
        friend bool operator==(const DateWrap& date1, const DateWrap& date2);
        friend bool operator<(const DateWrap& date1, const DateWrap& date2);
        DateWrap operator++(int);
        void ThrowNegetiveDays();
    };
    DateWrap& operator+=(DateWrap& date, int days); 
    DateWrap operator+(const DateWrap& date, int days);
    DateWrap operator+(int days, const DateWrap& date);
    std::ostream& operator<<(std::ostream& out, const DateWrap& date); 
    bool operator!=(const DateWrap& date1, const DateWrap& date2);
    bool operator<=(const DateWrap& date1, const DateWrap& date2);
    bool operator>(const DateWrap& date1, const DateWrap& date2);
    bool operator>=(const DateWrap& date1, const DateWrap& date2);
}
