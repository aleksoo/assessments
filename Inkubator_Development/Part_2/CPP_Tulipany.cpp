#include <assert.h>
#include <iostream>
#include <array>
#include <cstdlib>
#include <vector>
#include <sstream>

void test_cases();
int count_tulips(std::stringstream& inputStream);

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}

void test_cases(){
	int answer = 0;
	std::stringstream inputStream;

	inputStream << "8\n3 6 2 2 4 6 3 7";
	answer = count_tulips(inputStream);
	assert(answer == 14995);
	inputStream.str("");
	inputStream.clear();

	inputStream << "2\n1 15000";
	answer = count_tulips(inputStream);
	assert(answer == 14998);
	inputStream.str("");
	inputStream.clear();

	inputStream << "1\n15001";
	answer = count_tulips(inputStream);
	assert(answer == 15000);
	inputStream.str("");
	inputStream.clear();

	std::string valuesString = "15000\n";
	for(int i = 1; i <= 15000 ; ++i){
		valuesString += std::to_string(i) + ' ';
	}
	inputStream << valuesString;
	answer = count_tulips(inputStream);
	assert(answer == 0);
	inputStream.str("");
	inputStream.clear();    
}

int count_tulips(std::stringstream& inputStream){	
	std::array<bool, 15000> ownedTulips;
	std::fill(ownedTulips.begin(), ownedTulips.end(), 0);
	int rows = 0, tulip = 0, missingTulips = 0, numberOfTulips = 0;
	std::string::size_type sz;
	std::string inputString;
	
	getline(inputStream, inputString);
	rows = stoi(inputString);

	if(rows == 0)
		return 15000;

	for(int i = 0; i < rows; ++i){
			getline(inputStream, inputString, ' ');
			tulip = stoi(inputString, &sz);
			if( tulip > 0 && tulip <= 15000 )
				ownedTulips[tulip] = true;
	}

	for(int i = 1; i <= 15000; ++i){
		if( !ownedTulips[i] )
			++missingTulips;
	}

	return missingTulips;
}