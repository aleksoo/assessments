#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

void test_cases();
char* highest_scoring_word(const char* string);
int word_eval(const char* string);
char* stringToLow(const char* string);


int main(){
    test_cases();
    return 0;
}

void test_cases(){

    char* answerString = stringToLow("AAaaAA");
    assert(!strcmp(answerString, "aaaaaa"));

    answerString = stringToLow("Z");
    assert(!strcmp(answerString, "z"));

    answerString = stringToLow("");
    assert(!strcmp(answerString, ""));
    
    int answerInt = word_eval("aaa");
    assert(answerInt == 3);

    answerInt = word_eval("bA");
    assert(answerInt == 3);

    answerInt = word_eval("cAb");
    assert(answerInt == 6);

    answerInt = word_eval("");
    assert(answerInt == 0);

    answerString = highest_scoring_word("zzz bacbac");
    assert(!strcmp(answerString, "zzz"));

    answerString = highest_scoring_word("zZ ZZZ zac");
    assert(!strcmp(answerString, "ZZZ"));

    answerString = highest_scoring_word("aaa c");
    assert(!strcmp(answerString, "aaa"));

    answerString = highest_scoring_word("");
    assert(!strcmp(answerString, ""));


}

char* highest_scoring_word(const char* string){
    if(!strlen(string))
        return "";
    int highestScore = 0, tempScore = 0;
    char* token;
    char* highestWord;
    char* tempString = (char*)malloc( strlen(string) * sizeof(char) );
    strcpy(tempString, string);

    
    stringToLow(tempString);

    token = strtok(tempString," ,."); 
    highestWord = (char*)malloc( strlen(token) * sizeof(char) );
    strcpy(highestWord, token);

    while(token!=NULL){
        tempScore = word_eval(token);
        if(tempScore > highestScore){
            highestWord = realloc(highestWord, sizeof(token));
            strcpy(highestWord, token);
            highestScore = tempScore;
        }
        token = strtok(NULL," ,.");
    }

        return highestWord;
}

int word_eval(const char* string){
    int score=0;

    char* lowerString = (char*)malloc(strlen(string)*sizeof(char));
    lowerString = stringToLow(string);


    for(int i=0; i < strlen(string); ++i){
        score+=(int)lowerString[i]-96;
    }

    return score;
}

char* stringToLow(const char* string){
    char* lowerString = (char*)malloc(strlen(string)*sizeof(char));
    for(int i=0; i < strlen(string); ++i){
        lowerString[i]=tolower(string[i]);
    }
    return lowerString;
}