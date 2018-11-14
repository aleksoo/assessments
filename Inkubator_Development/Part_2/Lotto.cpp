#include <array>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/** 
* Function returns an array of 5 elements.
* Those 5 elements are created randomly in the range 1 - 49.
* Numbers can't repeat.
*/
std::array<int, 5> Lotto_drawing()
{
    std::array<int, 5> newArray;
	int counter=0;
    
    srand(time(NULL));

    while(true){
        newArray[counter] = rand() % 49 + 1;
        for(int i=0; i<counter; ++i){
            while(newArray[counter]==newArray[i]){
                newArray[counter] = rand() % 49 + 1;
                i=0;
            }
        } 
        ++counter;

        if(counter>=5) break; 
    }

    for(int i=0; i<5; ++i){
            std::cout << newArray[i] << std::endl;
    }

    return newArray;
}

/* Please create test cases for this program. test_cases() function can return void, bool or int. */
bool test_cases()
{
    std::array<int, 5> newArray = Lotto_drawing();

    // Rozmiar
    if(newArray.size() != 5) return false;

    // Przedzial 1-49
    for(int i=0; i<5; ++i){
            if( !(newArray[i] > 1) && !(newArray[i] < 49) ) return false;
    }

    // Powtorzenia
    for(int j=0; j<4; ++j){
        for(int i=j+1; i<5; ++i){
            if(newArray[j]==newArray[i]) return false;
        }
    }

    return true;
}


int main()
{
    if(test_cases()){
        std::cout << "Test passed\n";
    } else{
        std::cout << "Test failed\n";
    }
}

