#include "catch.hpp"
#include "DFA.hpp"

TEST_CASE("Simple DFA Test", "[DFA]"){
	DFA<3,2> _aa_{};
	_aa_.setFinal(2);
	_aa_.addTransition('b', 0, 0);
	_aa_.addTransition('a', 0, 1);
	_aa_.addTransition('b', 1, 0);
	_aa_.addTransition('a', 1, 2);
	_aa_.addTransition('b', 2, 2);
	_aa_.addTransition('a', 2, 2);

	REQUIRE( _aa_.evaluate("aa") ==  2);
	REQUIRE( _aa_.evaluate("ab") == -1);
	REQUIRE( _aa_.evaluate("baab") == 2);
	REQUIRE( _aa_.evaluate("aabbb") == 2);
	REQUIRE( _aa_.evaluate("ababaa") == 2);
	REQUIRE( _aa_.evaluate("abc") == -1);
	REQUIRE( _aa_.evaluate("abab") == -1);
}
