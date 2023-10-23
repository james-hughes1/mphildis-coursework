#include<iostream>
#include<array>
#include<string>
#include <cassert>

const std::array<std::string, 12> monthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
const std::array<std::string, 4> thStr = {"st", "nd", "rd", "th"};
const std::array<int, 12> monthLens = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
    public:
        Date(int, int, int);
        void display();
        int day();
        int month();
        int year();
        void advance();
        void back();
        void set(std::string, int);
    private:
        int m_day;
        int m_month;
        int m_year;
};

Date::Date (int d, int m, int y) {
    m_day = d;
    m_month = m;
    m_year = y;
}

void Date::display() {
    int thStrIndex = (m_day - 1) % 10;
    if ((thStrIndex > 3) | (m_day >= 11) & (m_day <= 13)) {
        thStrIndex = 3;
    }
    std::cout << m_day << thStr[thStrIndex] << " of " << monthNames[m_month-1] << ", " << m_year << std::endl;
}

int Date::day() {return m_day;}

int Date::month() {return m_month;}

int Date::year() {return m_year;}

void Date::advance() {
    m_day += 1;
    if (m_day > monthLens[m_month - 1]) {
        m_day = 1;
        m_month += 1;
    }
    if (m_month > 12) {
        m_month = 1;
        m_year += 1;
    }
}

void Date::back() {
    m_day -= 1;
    if (m_day < 1) {
        m_month -= 1;
        m_day = monthLens[m_month - 1];
    }
    if (m_month < 1) {
        m_year -= 1;
        m_month = 12;
    }
}

void Date::set(std::string var, int val) {
    if (var == "day") {
        if ((val >= 1) & (val <= monthLens[m_month - 1])) {
            m_day = val;
        }
        else {
            std::cout << "Invalid date change." << std::endl;
        }
    }
    if (var == "month") {
        if ((val >= 1) & (val <= 12) & (m_day <= monthLens[val - 1])) {
            m_month = val;
        }
        else {
            std::cout << "Invalid date change." << std::endl;
        }
    }
    if (var == "year") {
        if (val >= 0) {
            m_year = val;
        }
        else {
            std::cout << "Invalid date change (no BC years)." << std::endl;
        }
    }
}

int main(void){
    Date startOfTerm(6, 10, 2023);
    startOfTerm.advance();
    assert( startOfTerm.day() == 7 );
    assert( startOfTerm.month() == 10 );
    assert( startOfTerm.year() == 2023 );
    Date halloween(31, 10, 2023);
    halloween.advance();
    assert( halloween.day() == 1 );
    assert( halloween.month() == 11 );
    assert( halloween.year() == 2023 );
    halloween.set("day", 31); // This should cause an output
    halloween = Date(31, 10, 2023); // This should succeed
    halloween.set("month", 11); // This should cause an output
    halloween.display();
    Date startOfYear(1, 1, 2024);
    startOfYear.back();
    assert( startOfYear.day() == 31 ); // This should fail at run-time.
    assert( startOfYear.month() == 12 );
    assert( startOfYear.year() == 2023 );
    const Date endOfYear = startOfYear;
    //assert(endOfYear.day() == 31);
    //endOfYear.set("month", 10); // Should fail at *compile−time*
    //endOfYear = halloween; // Should fail at *compile−time*
}