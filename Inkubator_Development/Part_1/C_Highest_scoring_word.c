#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

void test_cases();
char* highest_scoring_word(const char* string);
int word_eval(const char* string);


int main(){
    test_cases();
    return 0;
}

void test_cases(){

    char* answerString;
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

char* highest_scoring_word(const char* string){
    if( !strlen(string) )
        return "";
        
    int highestScore = 0, tempScore = 0;
    char* token;
    char* highestWord;
    char* tempString = (char*)malloc(strlen(string) * sizeof(char));
    strcpy(tempString, string);

    token = strtok(tempString," ,."); 
    highestWord = (char*)malloc(strlen(token) * sizeof(char));
    strncpy(highestWord, token, strlen(token) * sizeof(char));

    while(token != NULL){
        tempScore = word_eval(token);
        if(tempScore > highestScore){
            highestWord = realloc(highestWord, sizeof(token));
            strncpy(highestWord, token, strlen(token) * sizeof(char));
            highestScore = tempScore;
        }
        token = strtok(NULL," ,.");
    }
    free(token);
    free(tempString);
    return highestWord;
}

int word_eval(const char* string){
    int score=0;

    for(int i = 0; i < strlen(string); ++i){
        // In ASCII table "a" has index 97, so to get values a=1, b=2, ..., I need to subtract 96.
        score += (int)string[i] - 96;
    }
    return score;
}

