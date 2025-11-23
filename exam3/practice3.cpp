/*
11. (Hard) Big Integer Addition: Suppose that we have two text files, num1.txt and num2.txt . For
    simplicity, suppose that each file contains n lines of integers of length m .
    
    For example, num1.txt could look like this

    128336484738349374939483
    128383749204958695847474
    192384737493958495848473
    192383748395849540234210
    093847382634739203984298

    This file would constitute one large number. The case will be similar for num2.txt .

    Your task is to read the numbers into an appropriate data structure and allow for the addition of these two
    big integers and output the result to a text file. (Do this problem if you have time.)
*/

#include <iostream>
#include <fstream>
#include <list>

std::list<int> get_integer(const std::string& filename) {
    std::list<int> big_int;
    std::ifstream input(filename);
    std::string line;

    if (input.is_open()) {
        while (getline(input, line)) {
            for (auto num: line) {
                int n = num - '0';
                big_int.push_front(n);
            }
        }
    } else {
        std::cout << "Could not open file." << std::endl;
    }

    return big_int;
}

std::list<int> add_integers(const std::list<int>& l1, const std::list<int>& l2) {
    std::list<int> result;

    // our assumption is that both lists are of the same size
    int carry = 0;
    for (auto itr1 = l1.begin(), itr2 = l2.begin();
        itr1 != l1.end() && itr2 != l2.end(); itr1++, itr2++) {
        int total_val = *itr1 + *itr2 + carry;
        int insert_val = total_val % 10;
        carry = total_val / 10;
        result.push_back(insert_val);
    }

    if (carry > 0) {
        result.push_back(carry);
    }

    return result;
}

int main() {
    auto big_num1 = get_integer("num1.txt");
    auto big_num2 = get_integer("num2.txt");
    auto result = add_integers(big_num1, big_num2);

    for (auto n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}