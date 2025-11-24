/*
Question 6:
Write a program that computes the cost of a long-distance call. The cost of the call is determined according to the following rate schedule:

Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a rate of $0.40 per minute.
Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged at a rate of $0.25 per minute.
Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.
The input will consist of the day of the week, the time the call started, and the length of the call in minutes.
The output will be the cost of the call.

Notes:
1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as 13:30
2. The day of the week will be read as one of the following two character string: Mo Tu We Th Fr Sa Su
3. The number of minutes will be input as a positive integer.
*/

#include <iostream>
#include <string>
//using namespace std;

int main() {
    int hour, minute, length;
    double cost = 0.0;
    char colon;
    std::string day;

    std::cout << "Enter the day of the week (Mo Tu We Th Fr Sa Su): ";
    std::cin >> day;

    if (day != "Mo" && day != "Tu" && day != "We" && day != "Th" && day != "Fr" && day != "Sa" && day != "Su") {
        std::cout << "Invalid day of the week." << std::endl;
        return 1;
    }
    
    std::cout << "Enter the time in 24-hour format (HH:MM): ";

    std::cin >> hour >> colon >> minute;

    if (colon != ':' || std::cin.fail()) {
        std::cout << "Invalid time format." << std::endl;
        return 1;
    }

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        std::cout << "Invalid time format." << std::endl;
        return 1;
    }

    std::cout << "Enter the length of the call in minutes: ";
    std::cin >> length;

    if (length <= 0) {
        std::cout << "Invalid length of call." << std::endl;
        return 1;
    }

    if (day == "Sa" || day == "Su") {
        cost = length * 0.15;
    } else if ((hour < 8) || (18 <= hour)) {
        cost = length * 0.25;
    } else {
        cost = length * 0.40;
    }

    std::cout << "The cost of the call is: $" << cost << std::endl;

    return 0;
}