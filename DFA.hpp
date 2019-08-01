#ifndef DFA_INCLUDE_HEADER
#define DFA_INCLUDE_HEADER

#include <iostream>
#include <map>

template<unsigned NumStates, unsigned NumInputSymbols>
class DFA {
  int transitions[NumStates][NumInputSymbols] = {};
  bool final[NumStates];
  std::map<char, int> symbolIndices;

public:
  int evaluate(std::string input);
  int addTransition(char symbol, unsigned fromState, unsigned toState);
  void setFinal(unsigned state);

};

template<unsigned NumStates, unsigned NumInputSymbols>
int DFA<NumStates, NumInputSymbols>::addTransition(
	char symbol, unsigned fromState, unsigned toState)
{
  int symbolIndex;

  if(fromState >= NumStates || toState >= NumStates){
    std::cout <<
      "Adding a transitions to or from a State"
      " which is greater than NumStates(" << NumStates << ")\n";
    exit(1);
  }

  if(symbolIndices.find(symbol) == symbolIndices.end()){
    symbolIndex = symbolIndices.size();
    symbolIndices.insert(std::make_pair(symbol, symbolIndex));
  } else {
    symbolIndex = symbolIndices[symbol];
  }

  if(symbolIndex >= NumInputSymbols){
    std::cout <<
      "error: There are more symbols than specified during instantiation\n";
    exit(1);
  }

  return transitions[fromState][symbolIndex] = toState;
}

template<unsigned NumStates, unsigned NumInputSymbols>
void DFA<NumStates, NumInputSymbols>::setFinal(unsigned state)
{
  if(state > NumStates){
    std::cout <<
      "error: Setting a state to \"final\""
      " which is greater than NumStates(" << NumStates << ")\n";
    exit(1);
  }
  final[state] = true;
}

/*
 * This function evaluates the DFA given an input string.
 * If evaluation ends in a final state, that state is returned
 * otherwise -1 is returned on failure
 */
template<unsigned NumStates, unsigned NumInputSymbols>
int DFA<NumStates, NumInputSymbols>::evaluate(std::string input){
  int currentState = 0;

  for(auto symbol : input){
    if(symbolIndices.find(symbol) == symbolIndices.end()){
      std::cout << "error: non specified symbol used: " << symbol << std::endl;
      return -1;
    }
    currentState = transitions[currentState][symbolIndices[symbol]];
  }

  if(final[currentState]){
    return currentState;
  }
  std::cout << "error: evaluation ended in non-final state\n";
  return -1;
}

#endif //DFA_INCLUDE_HEADER
