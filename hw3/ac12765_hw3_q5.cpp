/*
Question 5:
Body mass index (BMI) is a number calculated from a person's weight and height using the following formula: weight/height². Where weight is in kilograms and height is in meters.

According to the Centers for Disease Control and Prevention, the BMI is a fairly reliable indicator of body fatness for most people. BMI does not measure body fat directly, but research has shown that BMI correlates to direct measures of body fat, such as underwater weighing and dual-energy X-ray absorptiometry.

The following table gives the weight status in respect to the BMI value:
BMI Range	Weight Status
Below 18.5	Underweight
[18.5, 25)	Normal
[25, 30)	Overweight
30 and above	Obese

Write a program that prompts for weight (in pounds) and height (in inches) of a person, and prints the weight status of that person.

Your program should interact with the user exactly as it shows in the following example:
Please enter wight (in pounds): 
Please enter height (in inches):
The wight status is: Normal

Note: 1 pound = 0.453592 kilograms and 1 inch = 0.0254 meters.
*/

#include <iostream>
//using namespace std;

int main() {
    double weight, height, bmi;
    std::cout << "Please enter weight (in pounds): ";
    std::cin >> weight;
    std::cout << "Please enter height (in inches): ";
    std::cin >> height;

    weight = weight * 0.453592; // kilograms
    height = height * 0.0254; // meters

    bmi = weight / (height * height);

    if (bmi < 18.5) {
        std::cout << "The weight status is: Underweight" << std::endl;
    } else if (bmi < 25) {
        std::cout << "The weight status is: Normal" << std::endl;
    } else if (bmi < 30) {
        std::cout << "The weight status is: Overweight" << std::endl;
    } else {
        std::cout << "The weight status is: Obese" << std::endl;
    }

    return 0;
}