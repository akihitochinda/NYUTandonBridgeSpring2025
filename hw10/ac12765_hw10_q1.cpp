/*
Question 1:
Implement the function:  
string* createWordsArray(string sentence, int& outWordsArrSize)

This function gets a string sentence containing a sentence.  
When called, it should create and return a new array (of strings), that contains all the 
words in sentence. The function should also update the output parameter, 
outWordsArrSize, with the logical size of the new array that was created. 

Note: Assume that the words in the sentence are separated by a single space. 

For example, if sentence=”You can do it”, after calling  
createWordsArray(sentence, outWordsArrSize), the function should create 
and return an array that contains [”You” , ”can” , ”do” , ”it”], and update the 
value in outWordsArrSize to be 4. 

Implementation requirements: 
1.  You may want to use some of the string methods, such as find, substr, etc. 
2.  Your function should run in linear time. That is, if sentence contains n characters, 
    your function should run in 𝜃(𝑛). 
3.  Write a main() program that tests this function..
*/

#include <iostream>
#include <string>
//#include <vector>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    string sentence;
    int outWordsArrSize;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string* wordsArray = createWordsArray(sentence, outWordsArrSize);
    // [”You” , ”can” , ”do” , ”it”]
    cout << "Words in the new array (of strings): [";
    for (int i = 0; i < outWordsArrSize; i++) {
        cout << "\"" << wordsArray[i] << "\"";
        if (i < outWordsArrSize - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Logical size of the new array: " << outWordsArrSize << endl;

    delete[] wordsArray;
    
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    outWordsArrSize = 0;
    string delimiter = " ";
    
    for (int i = 0; i <= sentence.length(); i++) {
        if (i == sentence.length() || sentence[i] == delimiter[0]) {
            outWordsArrSize++;
        }
    }

    string* wordsArr = new string[outWordsArrSize];
    int index = 0;
    for (int start = 0, end = 0; end <= sentence.length(); end++) {
        if (end == sentence.length() || sentence[end] == delimiter[0]) {
            wordsArr[index++] = sentence.substr(start, end - start); // Extract the word from start to end and store it in the new array
            start = end + 1; // Move start to the next character after the delimiter
        }
    }

    return wordsArr;
}