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

	std::string valuesString = "15000\n";
	for(int i = 0; i < 15000 ; ++i){
		valuesString += std::to_string(i) + ' ';
	}
	inputStream << valuesString;
	inputStream.str("");
	inputStream.clear();

	answer = count_tulips(inputStream);
	assert(answer == 14995);

    
}

int count_tulips(std::stringstream& inputStream){
	
	std::array<bool, 15000> ownedTulips;
	std::fill(ownedTulips.begin(), ownedTulips.end(), 0);
	int rows, tulip, missingTulips = 0, numberOfTulips = 0;
	std::string::size_type sz;
	std::string inputString;
	
	getline(inputStream, inputString);
	std::cout << inputString << std::endl;
	rows = stoi(inputString, &sz);
	// std::cout << rows << std::endl;
	// std::srand(NULL);

	// do{		
	// 	std::cin >> rows;
	// } while( !(rows > 0 && rows < 20000) );

	// wypelnianie wartosci
	for(int i = 0; i < rows; ++i){
			getline(inputStream, inputString, ' ');
			tulip = stoi(inputString, &sz);
			if( tulip > 0 && tulip < 15000 )
				ownedTulips[tulip] = true;
	}
	
	// // int placeholderRows = rand() % 5000;
	// std::vector<int> tulipVector; 
	// for(int i = 0; i < placeholderRows; ++i){
	// 	tulipVector.push_back(rand() % 15000);
	// }

	// for(int i = 0; i < placeholderRows; ++i){
	// 	if(!ownedTulips[ tulipVector[i] ]){
	// 		ownedTulips[ tulipVector[i] ] = true;
	// 	}
	// }

	for(int i = 0; i < 15000; ++i){
		if(!ownedTulips[i])
			++missingTulips;
	}

// for(int i = 0; i < 15000; ++i){
// 	std::cout << ownedTulips[i] << ' ';
// }

	std::cout << "Liczba brakujacych tulipanow: " << missingTulips << std::endl;
	return missingTulips;
}