#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

std::map<int, std::string> intToRoman = { {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
                                            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
                                            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"} };

std::string romanNumberals(int inputNumber){
    std::string roman;
    std::vector<int> singleDigits;
    int digitsCounter =  std::to_string(inputNumber).length();

    for(int i = digitsCounter - 1; i >= 0; --i){ // Subtracting 1 to keep index correct.
        int numberToInsert = (int)(inputNumber / pow(10, i)) % 10;
        singleDigits.insert(singleDigits.begin(), i);
    }

    
    return roman;
}

void test_cases(){
    romanNumberals(1243);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
