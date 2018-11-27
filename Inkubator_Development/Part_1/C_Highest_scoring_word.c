#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

int word_eval(const char* string){
    int score=0;
    int stringLength = strlen(string);
    for(int i = 0; i < stringLength; ++i){
        score += (int)string[i] - 96;
    }
    return score;
}

char* highest_scoring_word(const char* string){
    if( !strlen(string) )
        return "";
        
    int highestScore = 0, tempScore = 0;
    char* token = NULL;
    char* highestWord = NULL;
    char* tempString = (char*)malloc( (strlen(string) + 1) * sizeof(char));
    strncpy(tempString, string, strlen(string));

    token = strtok(tempString," ");
    highestWord = (char*)malloc( (strlen(token) + 1) * sizeof(char));
    strcpy(highestWord, token);

    while(token != NULL){
        tempScore = word_eval(token);
        if(tempScore > highestScore){
            highestWord = realloc(highestWord, sizeof(token));
            strncpy(highestWord, token, strlen(token) * sizeof(char));
            highestScore = tempScore;
        }
        token = strtok(NULL," ");
    }
    free(tempString);
    return highestWord;
}

void test_cases(){

    char* answerString = NULL;
    int answerInt;
    
    answerInt = word_eval("aaa");
    assert(answerInt == 3);

    answerInt = word_eval("ba");
    assert(answerInt == 3);

    answerInt = word_eval("caba");
    assert(answerInt == 7);

    answerInt = word_eval("");
    assert(answerInt == 0);

    answerString = highest_scoring_word("zzz bacbac");
    assert(!strcmp(answerString, "zzz"));
    free(answerString);
    
    answerString = highest_scoring_word("zz zzz zac");
    assert(!strcmp(answerString, "zzz"));
    free(answerString);
    
    answerString = highest_scoring_word("aaa c");
    assert(!strcmp(answerString, "aaa"));
    free(answerString);
}

int main(){
    test_cases();
    return 0;
}




