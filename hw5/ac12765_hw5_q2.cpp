/*
Question 2:	
Implement a number guessing	game. The program should randomly choose an integer	
between 1 and 100 (inclusive), and have the user try to guess that number.	

Implementations guidelines:
1. The user can guess at most 5 times.
2. Before each guess the program announces:
• An updated guessing-range, taking	in to account previous guesses and responses.
• The number of guesses	that the user has left.
3. If the user guessed correctly, the program should announce that, and also tell how many
guesses the user used.
4. If the user guessed wrong, and there are still guesses left, the program should tell the
user if the number (it chose) is bigger or smaller than the number that the user guessed.
5. If the user didn’t guess the number in all of the 5 tries, the program should reveal the	
number it chose.
6. Follow the execution	examples below for the exact format.
In order to generate random numbers	(of	type int), you should first call the srand
function (one time) to initialize a seed for the random number generator. Then, you	can	call	
the	rand function repeatedly to generate random integers.

Follow the syntax as demonstrated in the code below:
1. #include <iostream>
2. #include <cstdlib>
3. #include <ctime>
4. using namespace std;
5.
6. int main() {
7. int x1, x2, x3, x4;
8. 
9. srand(time(0));
10.
11. x1 = rand();
12. x2 = rand();
13. x3 = rand() % 100;
14. x4 = (rand() % 100) + 1;
15. 
16. cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
17. 
18. return 0;
19. }

Note that we first included the	cstdlib and	ctime libraries	(lines 2 and 3).	
In line 9 we called	srand(time(0)) to create the seed for the random number generator.	
Then, in lines 11-14, we created 4 random numbers: The first two were taken	from the	
entire positive range of int variables.	For	x3 and x4 we used arithmetic manipulation to
change the range. x3 would be in the range 0-99 (since these are the possible remainders	
when dividing a number by 100),	and	x4 would be	in the range of 1-100 (shifting	the	range	
0-99 by	1).
Further	reading	regarding random number	generation can be found	in the textbook	on
pages 188-189.
Your program should	interact with the user exactly as it shows in the following	two	examples:

Execution example 1:
I thought of a number between 1 and	100! Try to guess it.
Range: [1, 100], Number	of guesses left: 5	
Your guess: 15
Wrong! My number is	bigger.
Range: [16,	100], Number of	guesses	left: 4	
Your guess: 34
Wrong! My number is smaller.	
Range: [16, 33], Number	of guesses left: 3	
Your guess: 23
Congrats! You guessed my number	in 3 guesses.

Execution example 2:
I thought of a number between 1	and	100! Try to	guess it.
Range: [1, 100], Number of guesses left: 5	
Your guess: 15
Wrong! My number is bigger.
Range: [16, 100], Number of	guesses	left: 4
Your guess: 50
Wrong! My number is	smaller.
Range: [16, 49], Number	of guesses left: 3	
Your guess: 3
Wrong! My number is	bigger.
Range: [16,	49], Number	of guesses left: 2	
Your guess: 34
Wrong! My number is	smaller.
Range: [16,	33], Number	of guesses left: 1	
Your guess: 20
Out	of guesses!	My number is 25
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
//using namespace std;

int main() {
    int number, guess;
    int min = 1, max = 100;
    int attempts = 5;

    srand(time(0));
    number = (rand() % 100) + 1;

    std::cout << "I thought of a number between 1 and 100! Try to guess it." << std::endl;

    while (attempts > 0) {
        std::cout << "Range: [" << min << ", " << max << "], Number of guesses left: " << attempts << std::endl;
        std::cout << "Your guess: ";
        std::cin >> guess;

        if (guess == number) {
            std::cout << "Congrats! You guessed my number in " << (5 - attempts + 1) << " guesses." << std::endl;
            return 0;
        } else {
            attempts--;
            if (attempts == 0) {
                break;
            }
            if (guess < number) {
                std::cout << "Wrong! My number is bigger." << std::endl;
                min = guess + 1;
            } else {
                std::cout << "Wrong! My number is smaller." << std::endl;
                max = guess - 1;
            }
        }
    }

    std::cout << "Out of guesses! My number is " << number << std::endl;
    return 0;
}