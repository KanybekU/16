#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date {
    int month, day, year;

    int difference(const Date& other) const {
        return abs((year - other.year) * 365 + (month - other.month) * 30 + (day - other.day));
    }

    void print() const {
        cout << month << "/" << day << "/" << year << endl;
    }

    bool operator<(const Date& other) const {
        return tie(year, month, day) < tie(other.year, other.month, other.day);
    }
};

string weekdays[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

string getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int c = year / 100;
    year %= 100;
    int w = (day + 13 * (month + 1) / 5 + year + year / 4 + c / 4 - 2 * c) % 7;
    return weekdays[(w + 7) % 7];
}

bool isValidYear(int year) {
    return (1000 <= year && year <= 3000);
}

int main() {
    char separator;
    Date date1, date2;
    cout << "Enter first date (MM/DD/YYYY): ";
    cin >> date1.month >> separator >> date1.day >> separator >> date1.year;

    cout << "Enter second date (MM/DD/YYYY): ";
    cin >> date2.month >> separator >> date2.day >> separator >> date2.year;

    if (!isValidYear(date1.year) || !isValidYear(date2.year)) {
        cout << "The dates are invalid";
        return 1;
    }

    cout << (date1 < date2 ? "First date is earlier than the second date" : 
             (date1 > date2 ? "First date is later than the second date" : "Both dates are equal")) << endl;

    cout << "The day of the week for the first date is: " << getDayOfWeek(date1.day, date1.month, date1.year) << endl;
    cout << "The day of the week for the second date is: " << getDayOfWeek(date2.day, date2.month, date2.year) << endl;
    cout << "The difference in days between the two dates is: " << date1.difference(date2) << endl;

    vector<Date> dates = {date1, date2};
    sort(dates.begin(), dates.end());
    
    cout << "Sorted dates: ";
    for (const auto& d : dates) {
        d.print();
    }

    return 0;
}
