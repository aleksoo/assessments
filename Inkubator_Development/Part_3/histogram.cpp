#include <assert.h>
#include <iostream>
#include <vector>
#include <string>

void trimWhitespace(std::string &stringToTrim){
    int length = stringToTrim.length();
    int pos = 0, lengthOfTrim = 0;

    for(int i = length - 1; i >= 0; --i) // Subtracting 1 to get index usable in array.
        if(stringToTrim[i] == ' ' || stringToTrim[i] == 'x'){ ////// USUNAC X JEZELI JUZ NIE BEDE MUSIAL TESTOWAC
            ++lengthOfTrim;
            pos = i;
        } else 
            break;
    if(pos)
        stringToTrim.erase(pos, lengthOfTrim);
}

void diceHistogram(std::vector<int> inputValues){
    std::string finalString; 

    int longestLine = 0;
    for(int i = 0; i < 6; ++i)
        if(inputValues[i] > inputValues[longestLine])
            longestLine = i;
    int longestLineLength = inputValues[longestLine]+1; // Adding 1 to make enough space for additional number above hash sign.

    for(int i = longestLineLength; i > 0; --i){
        for(int j = 0; j < 6; ++j){
            if(inputValues[j] + 1 == i && inputValues[j] != 0){ // Adding 1 to check if it is place above last # sign.
                finalString += std::to_string(inputValues[j]);
                if(inputValues[j] / 10) // 
                    continue;
            } else if(inputValues[j] < i)
                finalString += "x";
            else
                finalString += "#";
            finalString += "x";
        }
        trimWhitespace(finalString);
        finalString += "\n";             
    }
    finalString += "-----------\n1 2 3 4 5 6\n";
    std::cout << finalString; // tu poprawic zeby zwracalo
}

void test_cases(){
    std::vector<int> inputValues = {3, 15, 11, 5, 1, 1};
	diceHistogram(inputValues);

    inputValues = {0, 0, 0, 0, 0, 0};
	diceHistogram(inputValues);

    inputValues = {10, 10, 10, 10, 10, 10};
	diceHistogram(inputValues);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
