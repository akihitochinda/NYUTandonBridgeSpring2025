/*
Question 4:
Traditional password entry schemes are susceptible to "shoulder surfing" in which an attacker 
watches an unsuspecting user enter their password or PIN number and uses it later to gain 
access to the account. One way to combat this problem is with a randomized challenge
response system. In these systems the user enters different information every time, based on a 
secret in response to a randomly generated challenge.  
Consider the following scheme, in which the password consists of a five-digit PIN number (00000 
to 99999). Each digit is assigned a random number that is 1, 2, or 3. The user enters the random 
numbers that correspond to their PIN instead of their actual PIN numbers.  

For example, consider an actual PIN number of 12345. To authenticate the user would be 
presented with a screen such as:  
PIN:  0 1 2 3 4 5 6 7 8 9  
NUM:  3 2 3 1 1 3 2 2 1 3  
The user would enter 23113 instead of 12345. This doesn’t divulge the password even if an 
attacker intercepts the entry because 23113 could correspond to other PIN numbers, such as 
69440 or 70439.  
The next time the user logs in, a different sequence of random numbers would be generated, 
such as:  
PIN:  0 1 2 3 4 5 6 7 8 9  
NUM:  1 1 2 3 1 2 2 3 3 3  

Write a program to simulate the authentication process. Store an actual 5-digit PIN number in 
your program (make one up, and store it as a constant). The program should use an array to 
assign random numbers to the digits from 0 to 9. Output the random digits to the screen, input 
the response from the user, and output whether or not the user’s response correctly matches 
the PIN number. 

Assuming that the actual PIN number is 12345, your program should interact with the user 
exactly as it shows in the following examples (2 different executions of the program): 
Please enter your PIN according	to the following mapping:		
PIN: 0 1 2 3 4 5 6 7 8 9
NUM: 3 2 3 1 1 3 2 2 1 3
23113
Your PIN is correct	

Please enter your PIN according	to the following mapping:		
PIN: 0 1 2 3 4 5 6 7 8 9
NUM: 1 1 2 3 1 2 2 3 3 3
23113	
Your PIN is	not	correct

Note: Think how to break down your implementation to functions. 
*/

#include <iostream>
//using namespace std;

const int PIN_LENGTH = 5;
const int NUM_DIGITS = 10;
const int ACTUAL_PIN[PIN_LENGTH] = {1, 2, 3, 4, 5};
const int MIN_RANDOM = 1;
const int MAX_RANDOM = 3;

void generateRandomMapping(int mapping[NUM_DIGITS]);
void displayMapping(const int mapping[NUM_DIGITS]);
bool authenticateUser(const int mapping[NUM_DIGITS]);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    int mapping[NUM_DIGITS];

    generateRandomMapping(mapping);
    authenticateUser(mapping);

    return 0;
}

void generateRandomMapping(int mapping[NUM_DIGITS]) {
    for (int i = 0; i < NUM_DIGITS; i++) {
        mapping[i] = MIN_RANDOM + rand() % (MAX_RANDOM - MIN_RANDOM + 1);
    }
}

void displayMapping(const int mapping[NUM_DIGITS]) {
    std::cout << "PIN: ";
    for (int i = 0; i < NUM_DIGITS; i++) {
        std::cout << i << " ";
    }
    std::cout << "\nNUM: ";
    for (int i = 0; i < NUM_DIGITS; i++) {
        std::cout << mapping[i] << " ";
    }
    std::cout << std::endl;
}

bool authenticateUser(const int mapping[NUM_DIGITS]) {

    std::cout << "Please enter your PIN according to the following mapping:\n";
    displayMapping(mapping);
    
    std::string userInput;
    std::cin >> userInput;

    int userPin[PIN_LENGTH];
    int encryptedPin[PIN_LENGTH];

    for (int i = 0; i < PIN_LENGTH; i++) {
        userPin[i] = userInput[i] - '0'; // Convert character to integer
        encryptedPin[i] = mapping[ACTUAL_PIN[i]]; // Get the corresponding random number / ACTUAL_PIN[0] is 1, so mapping[1] is used
    }

    for (int i = 0; i < PIN_LENGTH; i++) {
        if (userPin[i] != encryptedPin[i]) {
            std::cout << "Your PIN is not correct" << std::endl;
            return false;
        }
    }

    std::cout << "Your PIN is correct" << std::endl;
    return true;
}