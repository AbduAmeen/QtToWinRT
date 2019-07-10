#ifndef QTTOWINRT_H
#define QTTOWINRT_H

#include <sys/types.h>
#include <utility>
#include <string>

namespace QtToWinRT {
namespace Clock {
class Date {
public:
    Date();
    Date(uint day, uint month, uint year);

    inline uint GetDay() { return m_day; }
    inline uint GetMonth() { return m_month; }
    inline uint GetYear() { return m_year; }
    inline void SetDay(uint day) { m_day = day; }
    inline void SetMonth(uint month) { m_month = month; }
    inline void SetYear(uint year) { m_year = year; }

    //Date& operator = (const Date& date) { m_day = date.GetDay(); m_month = date.GetMonth(); m_year = date.GetYear(); return *this;};
private:
    uint m_day;
    uint m_month;
    uint m_year;
};

class Time {
    Time();
    Time(uint hour, uint minute);
    Time(uint hour, uint minute, uint second);
    //in military time
    inline uint GetHour() { return m_hour; }
    inline uint GetMinute() { return m_minute; }
    inline uint GetSecond() { return m_second; }
    inline void SetHour(uint hour) { m_hour = hour; }
    inline void SetMinute(uint minute) { m_minute = minute; }
    inline void SetSecond(uint second) { m_second = second; }
private:
    uint m_hour;
    uint m_minute;
    uint m_second;
};

class DateTime : public Date, public Time {
public:
    inline Time GetTime() { return m_time; }
    inline Date GetDate() { return m_date; }
private:
    Date m_date;
    Time m_time;
};
}//end Clock

namespace Network {
struct NetworkPacket {
    std::string message;
    Clock::DateTime datetime;
};
}// end Network


}//end QtToWinRT
#endif // QTTOWINRT_H
