#include <iostream> 
using namespace std;
extern "C" {
    #include "date.h"
}

class DateWrap { 
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
	DateWrap& operator+=(int days); 
    class NegativeDays{};
    class InvalidDate{}; 
};
DateWrap operator+(const DateWrap& date, int days);
DateWrap operator+(int days, const DateWrap& date);
ostream& operator<<(ostream& out, const DateWrap& date); 
bool operator!=(const DateWrap& date1, const DateWrap& date2);
bool operator<=(const DateWrap& date1, const DateWrap& date2);
bool operator>(const DateWrap& date1, const DateWrap& date2);
bool operator>=(const DateWrap& date1, const DateWrap& date2);

