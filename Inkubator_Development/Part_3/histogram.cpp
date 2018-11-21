#include <assert.h>
#include <iostream>
#include <vector>
#include <string>


void vectorTest(const std::vector<std::string>& testVector){
    for(std::string aa : testVector){
        std::cout << aa << std::endl;
    }
}

void trimWhitespace(std::string &stringToTrim){
    int length = stringToTrim.length();
    int pos = 0, lengthOfTrim = 0;
    for(int i = length - 1; i >= 0; --i)
        if(stringToTrim[i] == ' ' || stringToTrim[i] == 'o'){
            ++lengthOfTrim;
            pos = i;
        } else 
            break;
    stringToTrim.erase(pos, lengthOfTrim);
}

void diceHistogram(std::vector<int> inputValues){
    std::string finalString;
    int counter = 1;
    
    int longestLine = 0;
    for(int i = 0; i < 6; ++i){
        if(inputValues[i] > inputValues[longestLine])
            longestLine = i;
    }


    int longestLineLength = inputValues[longestLine]+1; 

    for(int i = longestLineLength; i > 0; --i){
        for(int j = 0; j < 6; ++j){
            if(inputValues[j] + 1 == i && inputValues[j] != 0){ // Adding 1 to check if it is place above last # sign

                finalString += std::to_string(inputValues[j]);
                if(inputValues[j] / 10)
                    continue;

            } else if(inputValues[j] < i)
                finalString += " ";
            else{
                finalString += "#";
            }
            finalString += " ";
        }
        trimWhitespace(finalString);
        finalString += "\n";             
    }
    finalString += "-----------\n1 2 3 4 5 6\n";
    std::cout << finalString;
}

void test_cases(){
    std::vector<int> inputValues = {3, 15, 11, 5, 1, 1};
	diceHistogram(inputValues);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
