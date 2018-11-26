#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *howSorted(int *inputArray, int sizeOfArray){
    int lastNumber = inputArray[0];
    int counter = 1;
    while(lastNumber == inputArray[counter]){
        if(counter < sizeOfArray){
            lastNumber = inputArray[counter]; 
            ++counter;                      
        } else {
            return "no";
        }
                    
    } 
    if(lastNumber < inputArray[counter]){
        for(int i = counter; i < sizeOfArray; ++i){
            if(lastNumber > inputArray[i]){
                return "no";
            }
            lastNumber = inputArray[i];
        }
        return "yes, ascending";
    } else if(lastNumber > inputArray[1]){
        for(int i = counter; i < sizeOfArray; ++i){
            if(lastNumber < inputArray[i]){
                return "no";
            }
            lastNumber = inputArray[i];
        }
        return "yes, descending";
    }
    return "no";
}

void test_cases(){
    bool answer = false;
    int sizeOfArray = 0;
    int *inputArray = NULL;

    sizeOfArray = 4;
    inputArray = malloc(sizeOfArray * sizeof(int*));
    inputArray[0] = 0;
    inputArray[1] = 1;
    inputArray[2] = 1;
    inputArray[3] = 1;

    answer = !strcmp("yes, ascending", howSorted(inputArray, sizeOfArray));
    assert(answer == true);
    free(inputArray);

    sizeOfArray = 5;
    inputArray = malloc(sizeOfArray * sizeof(int*));    
    for(int i = 0; i < sizeOfArray; ++i){
        inputArray[i] = i + 1;
    }
    answer = !strcmp("yes, ascending", howSorted(inputArray, sizeOfArray));
    assert(answer == true);
    free(inputArray);

    sizeOfArray = 7;
    inputArray = malloc(sizeOfArray * sizeof(int*));    
    for(int i = 0; i < sizeOfArray ; ++i){
        inputArray[i] = sizeOfArray - i;
    }
    answer = !strcmp("yes, descending", howSorted(inputArray, sizeOfArray));
    assert(answer == true);
    free(inputArray);

    sizeOfArray = 7;
    inputArray = malloc(sizeOfArray * sizeof(int*));    
    for(int i = 0; i < sizeOfArray ; ++i){
        inputArray[i] = sizeOfArray - i;
    }
    inputArray[3] = 100;
    answer = !strcmp("no", howSorted(inputArray, sizeOfArray));
    assert(answer == true);
    free(inputArray);
}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
