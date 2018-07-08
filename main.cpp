/****
 * Programmer: Argin Aslanian
 * Date: July 7, 2018
 * Program: String Compression
 * Purpose: Implement a method to perform basic string compression using the counts of repeated characters.
 * Example: aaaabbbcc -> a4b3c2
 * Constraints:
 *              a. If the compressed string is not smaller or equal to the original, return original string.
 *              b. Assume all characters are uppercase and lowercase ( a - z )
 */

#include <iostream>
using namespace std;

string compressString(string& str);

int main() {

    string str = "aaaaabbbcddddeeeefff";
    cout << compressString(str) << endl;

    return 0;
}

string compressString(string& str) {

    //Result string -> the return string.
    //Counter int -> the counter for each repeated character
    string result = "";
    int counter = 1;

    //Add the first letter of the string to result.
    //result += str[0];

    for (int i = 0; i < str.size(); i++) {

        //If repeated characters found, increment counter.
        //If not found, append the new character & counter to return string, reset counter to 1.

        if (i + 1 >= str.size() || str[i] != str[i+1]) {

            result += str[i] + to_string(counter);
            counter = 1;

        } else {

            counter++;

        }

    }

    //Constraint Check: If return string size is greater than original, return original string.
    return result.size() >= str.size() ? str : result;
}