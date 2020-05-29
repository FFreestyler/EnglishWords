#include "TextBox.hpp"
#include <cxxtest/TestSuite.h>
#include <iostream>
using namespace std;

void testTextBox(void)
{
  //Expectation
  string exptext = "num";

  //Testing
  TextField field;
  field.txt.setString("num");

  TS_ASSERT_EQUALS(exptext,field.getString());
}
