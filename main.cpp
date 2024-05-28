#include <iostream>
#include <cmath>
using namespace std;

struct date {
    int month, day, year;
    //This comparison operator is used to compare two dates according to year, month and day.
    bool operator<(const date& second) const {
    if (year!=second.year)
        return year<second.year;
    if (month!=second.month)
        return month<second.month;
    return day<second.day;
}


int calculateDifference(const date& second) const {
        // This function should calculate the difference in days between two dates and return the result. 
        int days = year * 365 + (year / 4) - (year / 100) + (year / 400);
        for (int m = 1; m < month; ++m) {
            if (m == 2) {
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    days+= 29; // Leap year
                else
                    days+= 28;
            } else if (m == 4 || m == 6 || m == 9 || m == 11)
                days+= 30;
            else
                days+= 31;
        }
        days += day;

        int dayss = second.year * 365 + (second.year / 4) - (second.year / 100) + (second.year / 400);
        for (int m = 1; m <second.month; ++m) {
            if (m == 2) {
                if (second.year % 4 == 0 && (second.year % 100 != 0 || second.year % 400 == 0))
                    dayss += 29; // Leap year
                else
                    dayss += 28;
            } else if (m == 4 || m == 6 || m == 9 || m == 11)
                dayss += 30;
            else
                dayss += 31;
        }
        dayss+=second.day;
        return abs(days - dayss);
    } 

};
//This function should calculate and return the day of the week for a date
string weekday[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

string getdayofweek(int day, int month, int year) {
    int mon;
    if (month > 2)
        mon = month; // for March to December month code is same as month
    else {
        mon = (12 + month); // for Jan and Feb, month code will be 13 and 14
        year--; // decrease year for month Jan and Feb
    }
    int y = year % 100;
    int c = year / 100;
    int w = (day + (13 * (mon + 1)) / 5 + y + (y / 4) + (c / 4) + (5 * c));//// Calculates the day of the week using Zeller's Congruence formula.
    w = w % 7;//// Make sure the result is between 0 and 6 (Sunday to Saturday) by taking the remainder when divided by 7.
    return weekday[w];
}
bool isValidYear(int year) {
    return (1000 <= year && year <= 3000);//// Check if the year is between 1000 and 3000
}


int main() {
    char t;
    date date1, date2;
    cout << "Enter first date (MM/DD/YYYY): ";
    cin >> date1.month >> t >> date1.day >> t >> date1.year;

    cout << "Enter second date (MM/DD/YYYY): ";
    cin >> date2.month >> t >> date2.day >> t >> date2.year;

    if (isValidYear(date1.year) && isValidYear(date2.year)) {
        if (date1 < date2) {
            cout << "First date is earlier than the second date";
        } else if (date2 < date1) {
            cout << "First date is later than the second date";
        } else {
            cout << "Both dates are equal";
        }
        cout << "\nThe day of the week for the first date is: " << getdayofweek(date1.day, date1.month, date1.year);
        cout << "\nThe day of the week for the second date is: " << getdayofweek(date2.day, date2.month, date2.year);
        cout << "\nThe difference in days between the two dates is: " << date1.calculateDifference(date2);
    } else {
        cout << "The dates are invalid";
    }

    return 0;
}
