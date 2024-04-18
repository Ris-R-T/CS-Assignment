#include <iostream>
#include <stdexcept>
using namespace std;

class Date {
    int day;
    int month;
    int year;

    int convertExtraDaysToMonths(int days) {
        int months = 0;
        while (days > daysInMonth(months + 1, year)) {
            months++;
            days -= daysInMonth(months, year);
        }
        return months;
    }

    
    int toDays() const {
        int days = day;
        for (int i = 1; i < month; i++) {
            days += daysInMonth(i, year);
        }
        days += (year) * 365 + (year) / 4; // Add leap years
        return days;
    }

public:
    Date(int d, int m = 0, int y = 0) {
        if (d < 0 || m < 0 || y < 0) {
            throw invalid_argument("Invalid date");
        }
        day = d % daysInMonth(m, y);
        month = m % 12 + convertExtraDaysToMonths(d);
        year = y + m/12;
    }

    static int daysInMonth(int month, int year) {
        switch (month) {
            case 2:
                return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            default:
                return 30;
        }
    }
    int getDay() const {
        return day;
    }
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }

    Date operator+(int days) const {
        return Date(days + day, month, year) ;
    }
    
    int operator-(const Date& other) const {
        return toDays() - other.toDays();
    }


    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
    bool operator!=(const Date& other) const {
        return !(*this == other);
    }
    bool operator<(const Date& other) const {
        if (year < other.year)
            return true;
        if (year > other.year)
            return false;
        if (month < other.month)
            return true;
        if (month > other.month)
            return false;
        return day < other.day;
    }
    bool operator>(const Date& other) const {
        return other < *this;
    }
    bool operator<=(const Date& other) const {
        return !(*this > other);
    }
    bool operator>=(const Date& other) const {
        return !(*this < other);
    }
};

ostream& operator<<(ostream& os, const Date& date) {
    return os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
}

int main() {
    try {
    Date date1(1,1,2000);
    Date date2(2,1,2000);
    Date date3(2,1,2001);
    Date date4(1,1,2000);


    cout << boolalpha;
    cout << "Equals: "  << (date1 == date4) << endl; // true
    cout << "Not Equals: " << (date1 != date4) << endl; // false
    cout <<  "Smaller Than: " << (date1 < date2) << endl;
    cout << "Greater Than: " << (date1 > date3) << endl;
    cout << "Smaller or Equal To: " << (date1 <= date4) << endl; // true
    cout << "Greater or Equal To: " <<  (date1 >= date2) << endl; // true

    cout << (date1 + 3) << endl; // 101/1/2000

    cout << "Difference of Days in between: " << (date2 - date1) << " Days" << endl; // -1
    cout << "Difference Of Days in between: " << (date3 - date2) << " Days" << endl; // -1





    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    return 0;
}

