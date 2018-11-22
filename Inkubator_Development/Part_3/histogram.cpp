#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

void trimWhitespace(std::string &stringToTrim){
    int length = stringToTrim.length();
    int pos = 0, lengthOfTrim = 0;

    for(int i = length - 1; i >= 0; --i) // Subtracting 1 to get index usable in array.
        if(stringToTrim[i] == ' '){ 
            ++lengthOfTrim;
            pos = i;
        } else 
            break;
    if(pos)
        stringToTrim.erase(pos, lengthOfTrim);
}

std::string diceHistogram(std::vector<int> inputValues){
    std::string finalString; 

    if(!std::accumulate(inputValues.begin(), inputValues.end(), 0)){
        finalString += "-----------\n1 2 3 4 5 6\n";
        return finalString;
    }

    int longestLine = 0;
    for(int i = 0; i < 6; ++i)
        if(inputValues[i] > inputValues[longestLine])
            longestLine = i;
    int longestLineLength = inputValues[longestLine]+1; // Adding 1 to make enough space for additional number above hash sign.

    for(int i = longestLineLength; i > 0; --i){
        for(int j = 0; j < 6; ++j){
            if(inputValues[j] + 1 == i && inputValues[j] != 0){ // Adding 1 to check if it is place above last # sign.
                finalString += std::to_string(inputValues[j]);
                if(inputValues[j] / 10)
                    continue;
            } else if(inputValues[j] < i)
                finalString += " ";
            else
                finalString += "#";
            finalString += " ";
        }
        trimWhitespace(finalString);
        finalString += "\n";             
    }
    finalString += "-----------\n1 2 3 4 5 6\n";
    return finalString;
}

void test_cases(){
    std::string result; 
    std::vector<int> inputValues;
    std::string testString;

    inputValues = {7, 3, 10, 1, 0, 5};
    testString = "    10\n"
                 "    #\n"
                 "    #\n"
                 "7   #\n"
                 "#   #\n"
                 "#   #     5\n"
                 "#   #     #\n"
                 "# 3 #     #\n"
                 "# # #     #\n"
                 "# # # 1   #\n"
                 "# # # #   #\n"
                 "-----------\n"
                 "1 2 3 4 5 6\n";
    result = diceHistogram(inputValues);
	assert(result.compare(testString) == 0);

    inputValues = { 9, 10, 7, 7, 14, 9 };
    testString = "        14\n"
                 "        #\n"
                 "        #\n"
                 "        #\n"
                 "  10    #\n"
                 "9 #     # 9\n"
                 "# #     # #\n"
                 "# # 7 7 # #\n"
                 "# # # # # #\n"
                 "# # # # # #\n"
                 "# # # # # #\n"
                 "# # # # # #\n"
                 "# # # # # #\n"
                 "# # # # # #\n"
                 "# # # # # #\n"
                 "-----------\n"
                 "1 2 3 4 5 6\n";
    result = diceHistogram(inputValues);
	assert(result.compare(testString) == 0);

    inputValues = { 0, 0, 0, 0, 0, 0};
    testString = "-----------\n"
                 "1 2 3 4 5 6\n";
    result = diceHistogram(inputValues);
	assert(result.compare(testString) == 0);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
