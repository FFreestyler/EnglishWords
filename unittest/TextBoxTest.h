#include "TextBox.hpp"
#include <SFML/Graphics>
#include <ctest.h>
#include <iostream>
using namespace std;

class TextBoxTest : public CxxTest::Testsuite {
    TextField field;

public:
    void testTextBox(void)
    {
        // Expectation
        string exptext = "num";

        // Result
        field.txt.setString("num");

        ASSERT_STR(exptext, field.getString());
    }
};
