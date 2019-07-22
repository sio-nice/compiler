#ifndef INPUT_PARSER_HEADER
#define INPUT_PARSER_HEADER

class InputParser{
public:
	InputParser();
	virtual ~InputParser();

	void addArgument(std::string arg, bool hasParams = false, int paramCount = 1);
	std::list<Arg> parse(char* argv[], int argc);

private:
	std::list<Arg> args;

	std::vector<State> states;
	State** transitions;

	map<char, unsigned> mapInput;
	map<State, unsigned> mapStates;

};



#endif
