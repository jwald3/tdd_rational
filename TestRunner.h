#pragma once
#include <iostream>
#include <string>
#include <functional>

class TestRunner {
    public:
     static void runTest(const std::string& testName, std::function<bool()> test);
 };
 
 // needed to add paranetheses around "expected" and "actual" because "==" comes after "<<", so the evaluation
 // isn't performed by the time the "<<" resolves. Parentheses have precedence over the shift. 
 #define ASSERT_EQ(expected, actual)   \                                       
     ((expected) == (actual)) ? true : \
     (std::cout << "Assertion failed: " << (expected) << " != " << (actual) << std::endl,  false)