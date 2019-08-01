#include <iostream>
#include "InputParser.hpp"

/******* INPUT PARSER *******/

void InputParser::addArgument(std::string arg, int paramCount)
{
	if(arg.at(0) != '-'){
		std::cout << "error: Command line options must start "
			     " with \"-\"\n";
		exit(1);
	}
	ArgType newArg(argTypes.size(), arg, paramCount);
	for(auto i : argTypes){
		if(i != newArg) continue;
		std::cout << "error: Argument "
			  << arg
			  << " re-entered into parser\n";
		exit(1);
	}
	argTypes.push_back(newArg);
}


void InputParser::constructDFA()
{
	State start(0, "start");
	for (auto i : argTypes){
		for (char c : i.command) {
			if (mapInput.find(c) == mapInput.end()){
				mapInput[c] = mapInput.size();
			}
		}
	}

}




/******* ARG TYPE *******/

InputParser::ArgType::ArgType(int id, std::string name, int params)
	: id(id), command(name), params(params)
{

}
