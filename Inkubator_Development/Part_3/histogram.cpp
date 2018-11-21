#include <assert.h>
#include <iostream>
#include <vector>
#include <string>

void vectorTest(const std::vector<std::string>& testVector){
    for(std::string aa : testVector){
        std::cout << aa << std::endl;
    }
}

void diceHistogram(std::vector<int> inputValues){
    std::vector<std::string> footer; // kazdy powinien miec dlugosc 3
    std::string finalString;
    int counter = 1;
    for(int i = 0; i < 11; ++i){
        std::string tempString;
        if(!(i % 2))
            tempString += std::to_string(counter++) + "-";
        else
            tempString += " -";
        footer.push_back(tempString);
    }

    std::vector<std::string> histogram;
    for(int i = 0; i < 6; ++i){
        std::string tempString;
        if(inputValues[i] > 0){
            for(int j = 0; j < inputValues[i]; ++j){
                tempString += "#";
                // if(j == inputValues[i] - 1) // TO WAZNE, ZEBY DODAWALO NA KONIEC, BO JUZ MIALEM DOBRZE Z TYM 21 NA KONIEC, CHYBA MUSZE ZWIEKSZYC WIELKOSC STRINGA
                //     tempString += " " + std::to_string(inputValues[i]);
            }
        }
        histogram.push_back(tempString);
    }
    //vectorTest(histogram);
    
    int longestLine = 0; // sciezka, ktora jest najdluzsza, inaczej - liczba najczesciej wylosowana
    for(int i = 0; i < 6; ++i){
        if(inputValues[i] > inputValues[longestLine])
            longestLine = i;
    }



    // //int longestLineLength = histogram[longestLine].size();

    // Subtracting 2 to compensate top number
    int longestLineLength = inputValues[longestLine]; 

    // std::cout << std::endl << "longestLineLength: " << longestLineLength;
    // std::cout << std::endl << "inputValues[longestLine]: " << inputValues[longestLine];
    
    for(int i = longestLineLength; i >= 0; --i){
        for(int j = 0; j < 6; ++j){
            if(i == inputValues[j] && inputValues[j] != 0)
                std::cout << inputValues[j];
            
            else{            
                if(histogram[j].size() > i)
                    std::cout << histogram[j][i];
                else    
                    std::cout << "x";
                std::cout << "o";
            }
        }
        //tutaj dodawac znak na koniec \n
        std::cout << std::endl;
    }

    // footer
    for(int i = 2; i >= 0; --i){
        for(int j = 0; j < 11; ++j)
            std::cout << footer[j][i];
            std::cout << std::endl;
    }

    // std::cout << std::endl << "longestLine: " << longestLine;
    // std::cout << std::endl << "longestLineLength: " << longestLineLength;
    // std::cout << std::endl;
}

void test_cases(){
    std::vector<int> inputValues = {3, 12, 8, 5, 0, 1};
	diceHistogram(inputValues);

}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
