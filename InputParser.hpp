#ifndef INPUT_PARSER_HEADER
#define INPUT_PARSER_HEADER

#include <list>
#include <vector>
#include <map>

class InputParser{
public:

	class ArgType {
	public:
		int id;
		int params;
		std::string command;
	public:
		explicit ArgType(int id, std::string name, int params = 0);
		bool operator != (ArgType& other){
			return true;
		}
	};
	class Arg {};

	InputParser();
	virtual ~InputParser();

	void addArgument(std::string arg, int paramCount = 0);
	std::list<Arg> parse(char* argv[], int argc);

	/*
	 * A class which holds one command line argument
	 * and possible parameters of that argument
	 */

private:

	/* A class representing one state of a DFA */
	class State {
		int id;
		std::string name;
	public:
		State(int id, std::string name) : id(id), name(name) {}
	};

	/* An accepting state of a DFA */
	class Accept : public State {
	public:
		Arg createArgument();
	};

	std::list<Arg> args;
	std::list<ArgType> argTypes;

	std::vector<State> states;
	State** transitions;

	std::map<char, unsigned> mapInput;
	std::map<State, unsigned> mapStates;

	void constructDFA();
	State& transition(const State& current, char input);
};



#endif  //INPUT_PARSER_HEADER
