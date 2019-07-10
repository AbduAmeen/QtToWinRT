#include "qttowinrt.h"

#include <ctime>
namespace QtToWinRT {
namespace Clock {
Date::Date() {
    std::time_t time1 = std::time(nullptr);
    std::tm* tm = std::localtime(&time1);

    m_year = static_cast<uint>(tm->tm_year + 1900);
    m_month = static_cast<uint>(tm->tm_mon + 1);
    m_day = static_cast<uint>(tm->tm_mday);
}

Date::Date(uint day, uint month, uint year) : m_day(day), m_month(month), m_year(year) {

}

Time::Time() {
    std::time_t time1 = std::time(nullptr);
    std::tm* tm = std::localtime(&time1);

    m_second = static_cast<uint>(tm->tm_sec);
    m_minute = static_cast<uint>(tm->tm_min);
    m_hour = static_cast<uint>(tm->tm_hour);
}
}//end Clock

}//end QtToWinRT
