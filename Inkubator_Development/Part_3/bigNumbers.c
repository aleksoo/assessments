#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool bigNumbers(const char *inputString){
    int choice=-1;
    char *firstNumber = NULL;
    char *sign = NULL;
    char *secondNumber = NULL;
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

    switch(choice){
        case 0: // ==
            if( strlen(firstNumber) != strlen(secondNumber) ){
                printf("NIE\n");
                free(tempString);
                return false;
            }
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !( (int)*(firstNumber + i) == (int)*(secondNumber + i) ) ){
                    printf("NIE\n");
                    free(tempString);
                    return false;
                }
            }
            break;

        case 1: // !=
            if( strlen(firstNumber) == strlen(secondNumber) ){
                for(int i = 0; i < strlen(firstNumber); ++i){
                    if( (int)*(firstNumber + i) != (int)*(secondNumber + i) ){
                        printf("TAK\n");
                        free(tempString);
                        return true;
                    }
                }   
            }
            printf("NIE\n");
            free(tempString);
            return false;
            break;

        case 2: // >
            if( strlen(firstNumber) == strlen(secondNumber) ){
                for(int i = 0; i < strlen(firstNumber); ++i){
                    if( (int)*(firstNumber + i) > (int)*(secondNumber + i) ){
                        printf("TAK\n");
                        free(tempString);
                        return true;
                    }
                }
                printf("NIE\n");
                free(tempString);
                return false;
            } else{
                if( strlen(firstNumber) > strlen(secondNumber) ){
                    printf("TAK\n");
                    free(tempString);
                    return true;
                } else{
                    printf("NIE\n");
                    free(tempString);
                    return false;
                }
            }
            break;

        case 3: // < // co do kurwy
            if( strlen(firstNumber) == strlen(secondNumber) ){
                for(int i = 0; i < strlen(firstNumber); ++i){
                    if( (int)*(firstNumber + i) < (int)*(secondNumber + i) ){
                        printf("TAK\n");
                        free(tempString);
                        return true;
                    }
                }
                printf("NIE\n");
                free(tempString);
                return false;
            } else{
                if( strlen(firstNumber) < strlen(secondNumber) ){
                    printf("TAK\n");
                    free(tempString);
                    return true;
                } else{
                    printf("NIE\n");
                    free(tempString);
                    return false;
                }
            }
            break;

        case 4: // >=
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !((int)*(firstNumber + i) >= (int)*(secondNumber + i)) ){
                    printf("NIE\n");
                    free(tempString);
                    return false;
                }
            }
            printf("TAK\n");
            free(tempString);
            return true;
            break;

        case 5: // <=
            for(int i = 0; i < strlen(firstNumber); ++i){
                if( !( (int)*(firstNumber + i) <= (int)*(secondNumber + i) ) ){
                    printf("NIE\n");
                    free(tempString);
                    return false;
                }
            }
            break;
         default:
            printf("WRONG SIGN\n");
            free(tempString);
            break;
    }
    printf("TAK\n");
    free(tempString);
    return true;
}

void test_cases(){
    bool answer = false;

   
    
    answer = bigNumbers("10 == 10");
    assert(answer == true);

    answer = bigNumbers("10 != 10");
    assert(answer == false);

    answer = bigNumbers("11 != 10");
    assert(answer == true);

    answer = bigNumbers("100 > 10");
    assert(answer == true);

    answer = bigNumbers("10 > 10");
    assert(answer == false); 

    answer = bigNumbers("110 > 100");
    assert(answer == true);    

    answer = bigNumbers("10 < 10");
    assert(answer == false);  

    answer = bigNumbers("10 < 11");
    assert(answer == true); 

    answer = bigNumbers("100 < 11");
    assert(answer == false);   
    
    answer = bigNumbers("10 <= 11");
    assert(answer == true);

    answer = bigNumbers("111 >= 10");
    assert(answer == true); 
    
    answer = bigNumbers("100000000000000000000000000000000000 < 100000000000000000000000000000000001");
    assert(answer == true);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
