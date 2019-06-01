// starZ.cpp   A demonstration of ASCII Art printing C characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);

// Write starZ per specifictions at 
// https://foo.cs.ucsb.edu/16wiki/index.php/F14:Labs:lab04
// and so that internal tests pass, and submit.cs system tests pass

string stringofNchars(int numchar){
	string result = "";
	for (int i=1; i<=numchar; i++){
		result+= "*";
	}
	result += "\n";
	return result;

}

string blank_and_star (int numC, char whatC){
	string result = "";
	for (int i=1; i<=numC; i++) {
		result += whatC;
	}
	return result;
}


string starZ(int width)
{
  string result="";

  if( width < 3)
	  return result;
  // TODO: remove this line, replace with correct code
  for (int i=width-2; i>=1; i--){
	  result += blank_and_star(i,' ') + blank_and_star(1,'*') + blank_and_star((width-i-1),' ') + "\n";
  }
  return stringofNchars(width) + result + stringofNchars(width);
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starZ3Expected = 
    "***\n"
    " * \n"
    "***\n";
  
  assertEquals(starZ3Expected,starZ(3),"starZ(3)");

  string starZ4Expected = 
    "****\n"
    "  * \n"
    " *  \n"
    "****\n";
  
  assertEquals(starZ4Expected,starZ(4),"starZ(4)");

  assertEquals("",starZ(0),"starZ(0)");
  assertEquals("",starZ(2),"starZ(2)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[])
{

  // TODO: Add check for parameter
  // and code to print usage message
  if (argc != 2){
	  cerr << "Usage: " << argv[0] << " width" << endl;
  exit(1);
  }

  // TODO: Add code to get width from cmd line arg
  // code that checks if it is -1; if so, call runTests()
  // then exit.
  int width = stoi(argv[1]);
  
  if(width == -1){
  runTests();
  exit(0);
  }

  // TODO: Add code that calls the starZ function and prints
  // the result on cout (without an extra newline)
cout << starZ(width);
  return 0;
}
