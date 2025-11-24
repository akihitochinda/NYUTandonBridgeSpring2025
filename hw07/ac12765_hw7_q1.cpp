/*
Question 1:
a.  Implement a function:
    int printMonthCalender(int numOfDays, int startingDay)
    This function is given two parameters:
    • numOfDays - The number of days in the month
    • startingDay – a number 1-7 that represents the day in the week of the first day
      in that month (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).
 
    The function should:
    • Print a formatted monthly calendar of that month
    • Return a number 1-7 that represents the day in the week of the last day in that
      month.

    Formatting Notes:
    • The output should include a header line with the days’ names.
    • Columns should be spaced by a Tab.

    Example: when calling printMonthCalender(31, 4)it should return 6, and should
    print:

            Mon Tue Wed Thr Fri Sat Sun
                        1   2   3   4
            5   6   7   8   9   10  11
            12  13  14  15  16  17  18
            19  20  21  22  23  24  25
            26  27  28  29  30  31

b.  A method for determining if a year is a leap year in the Gregorian calendar system is
    to check if it is divisible by 4 but not by 100, unless it is also divisible by 400.
    For example, 1896, 1904, and 2000 were leap years but 1900 was not.
    Write a function that takes in a year as input and return true if the year is a leap year,
    return false otherwise.
    Note: background on leap year https://en.wikipedia.org/wiki/Leap_year

c.  Implement a function
    void printYearCalender(int year, int startingDay)
    This function is given two parameters:
    • year – an integer that represents a year (e.g. 2016)
    • startingDay – a number 1-7 that represents the day in the week of 1/1 in that
      year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).

    The function should use the functions from sections (a) and (b) in order to print a
    formatted yearly calendar of that year.

    Formatting Note: As the header for each month you should print the months’ name
    followed by the year (e.g. March 2016).

    Example: Appendix A shows the expected output of the call
    printYearCalender(2016, 5).

d.  Write program that interacts with the user and your function in (c).

Appendix A.
The expected output of the call printYearCalender(2016, 5) is:

            January 2016
            Mon Tue Wed Thr Fri Sat Sun
                            1   2   3
            4   5   6   7   8   9   10
            11  12  13  14  15  16  17
            18  19  20  21  22  23  24
            25  26  27  28  29  30  31

            February 2016
            Mon Tue Wed Thr Fri Sat Sun
            1   2   3   4   5   6   7
            8   9   10  11  12  13  14
            15  16  17  18  19  20  21
            22  23  24  25  26  27  28
            29

            March 2016
            Mon Tue Wed Thr Fri Sat Sun
                1   2   3   4   5   6
            7   8   9   10  11  12  13
            14  15  16  17  18  19  20
            21  22  23  24  25  26  27
            28  29  30  31

            April 2016
            Mon Tue Wed Thr Fri Sat Sun
                            1   2   3
            4   5   6   7   8   9   10
            11  12  13  14  15  16  17
            18  19  20  21  22  23  24
            25  26  27  28  29  30

            May 2016
            Mon Tue Wed Thr Fri Sat Sun
                                    1
            2   3   4   5   6   7   8
            9   10  11  12  13  14  15
            16  17  18  19  20  21  22
            23  24  25  26  27  28  29
            30  31

            June 2016
            Mon Tue Wed Thr Fri Sat Sun
                    1   2   3   4   5
            6   7   8   9   10  11  12
            13  14  15  16  17  18  19
            20  21  22  23  24  25  26
            27  28  29  30

            July 2016
            Mon Tue Wed Thr Fri Sat Sun
                            1   2   3
            4   5   6   7   8   9   10
            11  12  13  14  15  16  17
            18  19  20  21  22  23  24
            25  26  27  28  29  30  31

            August 2016
            Mon Tue Wed Thr Fri Sat Sun
            1   2   3   4   5   6   7
            8   9   10  11  12  13  14
            15  16  17  18  19  20  21
            22  23  24  25  26  27  28
            29  30  31

            September 2016
            Mon Tue Wed Thr Fri Sat Sun
                        1   2   3   4
            5   6   7   8   9   10  11
            12  13  14  15  16  17  18
            19  20  21  22  23  24  25
            26  27  28  29  30

            October 2016
            Mon Tue Wed Thr Fri Sat Sun
                                1   2
            3   4   5   6   7   8   9
            10  11  12  13  14  15  16
            17  18  19  20  21  22  23
            24  25  26  27  28  29  30
            31
            
            November 2016
            Mon Tue Wed Thr Fri Sat Sun
                1   2   3   4   5   6
            7   8   9   10  11  12  13
            14  15  16  17  18  19  20
            21  22  23  24  25  26  27
            28  29  30

            December 2016
            Mon Tue Wed Thr Fri Sat Sun
                        1   2   3   4
            5   6   7   8   9   10  11
            12  13  14  15  16  17  18
            19  20  21  22  23  24  25
            26  27  28  29  30  31
*/

#include <iostream>
//using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int year, startingDay;
    std::cout << "Enter year: ";
    std::cin >> year;

    if (year < 1) {
        std::cerr << "Invalid year. Year must be a positive integer." << std::endl;
        return 1;
    }

    std::cout << "Enter starting day - a number 1-7 that represents the day in the week of the first day in the month\n";
    std::cout << "(1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).: ";
    std::cin >> startingDay;

    if (startingDay < 1 || startingDay > 7) {
        std::cerr << "Starting day must be between 1 and 7." << std::endl;
        return 1;
    }
    
    printYearCalender(year, startingDay);
    
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {

    std::cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";

    for (int i = 1; i < startingDay; i++) { // Print leading spaces for the first week
        std::cout << "\t";
    }

    for (int day = 1; day <= numOfDays; day++) {
        std::cout << day << "\t";
        if ((day + startingDay - 1) % 7 == 0) { // Check if the current day is the last day of the week
            std::cout << "\n";
        }
    }

    if ((numOfDays + startingDay - 1) % 7 != 0) { // Print a new line if the last day of the month is not the last day of the week
        std::cout << "\n";
    }

    return (startingDay + numOfDays - 1) % 7 == 0 ? 7 : (startingDay + numOfDays - 1) % 7; // Return the day of the week for the last day of the month
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printYearCalender(int year, int startingDay) {
    std::cout << "January " << year << "\n";
    startingDay = printMonthCalender(31, startingDay) % 7 + 1; // Update startingDay for the next month
    std::cout << "\n";

    std::cout << "February " << year << "\n";
    startingDay = printMonthCalender(isLeapYear(year) ? 29 : 28, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "March " << year << "\n";
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "April " << year << "\n";
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "May " << year << "\n";
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "June " << year << "\n";
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "July " << year << "\n";
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "August " << year << "\n";
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "September " << year << "\n";
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "October " << year << "\n";
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "November " << year << "\n";
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;
    std::cout << "\n";

    std::cout << "December " << year << "\n";
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;
}