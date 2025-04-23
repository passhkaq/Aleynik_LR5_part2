#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Aleynik_function.h"
using namespace cute;


void testUserInputEmpty() {
    string str = "";
    bool expected = false;
    bool actual = userInput(str, 0 , 100);
    ASSERT_EQUAL(expected, actual);
}

void testUserInputLetter() {
    string str = "a";
    bool expected = false;
    bool actual = userInput(str, 0 , 100);
    ASSERT_EQUAL(expected, actual);
}

void testUserInputDigitLetterValue() {
    string str = "5a";
    bool expected = false;
    bool actual = userInput(str, 0 , 100);
    ASSERT_EQUAL(expected, actual);
}

void testAddition() {
    int a = 5;
    int b = 3;
    int expected = 8;
    int actual = addition(a, b);
    ASSERT_EQUAL(expected, actual);
}

void testSubtraction() {
    int a = 5;
    int b = 3;
    int expected = 2;
    int actual = subtraction(a, b);
    ASSERT_EQUAL(expected, actual);
}

int main() {
    suite s;
    s.push_back(CUTE(testUserInputEmpty));
    s.push_back(CUTE(testUserInputLetter));
    s.push_back(CUTE(testUserInputDigitLetterValue));
    s.push_back(CUTE(testAddition));
    s.push_back(CUTE(testSubtraction));

    ide_listener<> listener;
    makeRunner(listener)(s, "All tests");
    return 0;
}
