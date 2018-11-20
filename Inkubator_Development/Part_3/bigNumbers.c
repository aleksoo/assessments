#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool bigNumbers(const char *inputString){
    int choice=-1;
    char *firstNumber = NULL;
    char *sign = NULL;
    char *secondNumber = NULL; // KONWERSJA Z CHAR* 
    char *tempString = (char*)malloc(strlen(inputString) * sizeof(char));
    strcpy(tempString, inputString);

    firstNumber = strtok(tempString, " ");
    sign = strtok(NULL, " ");
    secondNumber = strtok(NULL, " ");



    const char *signs[6] = {"==", "!=", ">", "<", ">=", "<="};
    for(int i = 0; i < 6; ++i){
        if(!strcmp(signs[i], sign)){
            choice = i;
            break;
        }
    }

    // strtol(*(firstNumber + i), NULL, 10)
    // strtol(*(secondNumber + i), NULL, 10)

    switch(choice){
        case 0: // ==
            if( strlen(firstNumber) != strlen(secondNumber) ){
                printf("NIE\n");
                return false;
            }
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !(*(firstNumber + i) == *(secondNumber + i)) ){
                    printf("NIE\n");
                    return false;
                }
            }
            break;

        case 1: // !=
            for(int i = 0; i < strlen(firstNumber); ++i){
                printf("%c %c\n", *(firstNumber + i), *(secondNumber + i));
                if( *(firstNumber + i) == *(secondNumber + i) ){
                    printf("NIE\n");
                    return false;
                }
            }
            break;

        case 2: // >
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !(*(firstNumber + i) > *(firstNumber + i)) ){
                    printf("NIE\n");
                    return false;
                }
            }
            break;

        case 3: // < // co do kurwy
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !(*(firstNumber + i) < *(firstNumber + i)) ){
                    printf("NIE\n");
                    return false;
                }
            }
            break;

        case 4: // >=
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !(*(firstNumber + i) >= *(firstNumber + i)) ){
                    printf("NIE\n");
                    return false;
                }
            }
            break;

        case 5: // <=
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !(*(firstNumber + i) <= *(firstNumber + i)) ){
                    printf("NIE\n");
                    return false;
                }
            }
            break;
         default: // ERROR
            break;
    }
    printf("TAK\n");
    return true;
}

void test_cases(){
    bool answer = false;

   
    
    answer = bigNumbers("10 == 10");
    assert(answer == true);

    answer = bigNumbers("10 != 10");
    assert(answer == false);

    answer = bigNumbers("100 > 10");
    assert(answer == false);

    answer = bigNumbers("10 > 10");
    assert(answer == false);    
    
    answer = bigNumbers("10 <= 10");
    assert(answer == true);

    answer = bigNumbers("10 >= 10");
    assert(answer == true); 
    
    answer = bigNumbers("100000000000000000000000000000000000 < 100000000000000000000000000000000001");
    assert(answer == true);
}


int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
