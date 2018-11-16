#include <assert.h>
#include <iostream>
#include <string>
#include <stack>

bool braces(const std::string& bracesString);
void test_cases();
bool is_pair(const char &one, const char &two);

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}

void test_cases(){
	bool answer;

	answer = is_pair('{', '}');
	assert(answer == true);

	answer = is_pair('[', ']');
	assert(answer == true);	

	answer = is_pair('(', ')');
	assert(answer == true);	

	answer = braces("{}");
	assert(answer == true);

	answer = braces("{()}");
	assert(answer == true);

	answer = braces("{)}");
	assert(answer == false);

	answer = braces("{");
	assert(answer == false);

	std::cout << "A\n";
	answer = braces(")(");
	assert(answer == false);

	answer = braces("([)]");
	assert(answer == false);

	answer = braces("([)]]");
	assert(answer == false);	
}

bool braces(const std::string& bracesString){
	if(bracesString.size() == 1)
		return false;

	std::stack<char> bracesStack;
	char temp;
	for(char bracket : bracesString){		
		if(	bracket == '(' || bracket == '[' || bracket == '{' ){
			bracesStack.push(bracket);
		} else {
			if(bracesStack.empty())
				bracesStack.push(bracket);
			else {
				temp = bracesStack.top();
				bracesStack.pop();
				if(!is_pair(temp, bracket)) 
					return false;
			}
		}		
	}

	return true;
}

bool is_pair(const char &one, const char &two){
	if((one == '(' && two == ')')
	|| (one == '[' && two == ']') 
	|| (one == '{' && two == '}'))
		return true;
	else
		return false;
}