#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>



std::string romanNumberals(int inputNumber){
    static std::map<int, std::string> intToRoman = { {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
                                            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
                                            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"} };
    std::string roman;
    std::vector<int> singleDigits;
    int digitsCounter =  std::to_string(inputNumber).length();

    while(inputNumber > 0)
        for(auto iter = intToRoman.rbegin(); iter != intToRoman.rend(); ++iter){
            if(inputNumber / iter->first){
                roman += iter->second;    
                inputNumber -= iter->first;
                break;
            } 
        }
    return roman;
}

void test_cases(){
    std::string test = romanNumberals(1000);
    assert(test == "M");
 
    test = romanNumberals(1990);
    assert(test == "MCMXC");
 
    test = romanNumberals(2008);
    assert(test == "MMVIII");
 
    test = romanNumberals(1666);
    assert(test == "MDCLXVI");
 
    test = romanNumberals(1);
    assert(test == "I");
 
    test = romanNumberals(0);
    assert(test == "");
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
