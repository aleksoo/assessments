#include <assert.h>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm> // transform
#include <map>

std::vector<std::string> directions(const std::vector<std::string> & inputDirections){
    std::map<std::string, std::string> mapDirections = { {"NORTH", "SOUTH"}, {"EAST", "WEST"}, {"SOUTH", "NORTH"}, {"WEST", "EAST"} };

    std::vector<std::string> stringDirections = inputDirections;
    std::vector<std::string> directions; 

    std::string singleDirection;
    for(std::string singleDirection : stringDirections){
        if(singleDirection == "")
            continue;
        std::transform(singleDirection.begin(), singleDirection.end(),singleDirection.begin(), ::toupper);
        if(directions.size()){ 
            if(directions.back() == mapDirections[singleDirection]){
                directions.pop_back();
            } else {
                directions.push_back(singleDirection);
            }
        } else {
            directions.push_back(singleDirection);
        }        
    }
    
    return directions;
}

void test_cases(){
    std::vector<std::string> inputDirections;
    std::vector<std::string> answerString;
    std::vector<std::string> answerCompare;


    inputDirections = { {"North"}, {"South"}, {"South"}, {"East"}, {"West"}, {"North"}, {"West"} };
    answerString = directions(inputDirections);
    answerCompare = {"WEST"};
    assert(answerString == answerCompare);	

    inputDirections = { {"NORTH"}, {"SOUTH"}, {"SOUTH"}, {"EAST"}, {"WEST"}, {"NORTH"}, {"WEST"} };
    answerString = directions(inputDirections);
    answerCompare = {"WEST"};
    assert(answerString == answerCompare);	

    // inputDirections = { \"North\", \"South\", \"South\", \"East\", \"West\", \"North\", \"West\" }";
    // answerString = directions(inputDirections);
    // answerCompare = {"WEST"};
    // assert(answerString == answerCompare);		

    inputDirections = { {"North"}, {"South"}, {"South"},  {"North"} };
    answerString = directions(inputDirections);
    answerCompare = {};
    assert(answerString == answerCompare);	

    inputDirections = { {"North"}, {"West"}, {"East"}, {"East"}, {"South"}, {"North"}, {"West"}, {"West"}, {"South"} };
    answerString = directions(inputDirections);
    answerCompare = { {"NORTH"}, {"WEST"}, {"SOUTH"}};
    assert(answerString == answerCompare);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
