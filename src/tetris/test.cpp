#include "test.h"

string fillLine(string begin, string end) {
  int nbSupChars = COL_WIDTH - begin.length() - end.length();

  string result = begin;
  for (int i=0; i < nbSupChars; i++)
    result += FILL_CHAR;
  result += end;

  return result;
}

string fillLine(string begin) {
  return fillLine(begin, "");
}

string formatResult(int depth, string label, bool success) {
  string line;
  string result;
  string color;

  if (success) {
    color = string(COLOR_PASS);
    result = "PASS";
  }
  else {
    color = string(COLOR_FAIL);
    result = "FAIL";
  }

  for (int i=0; i<depth*2; i++)
    label = ' ' + label;
  
  line = fillLine(label, "["+result+"]").substr(0, 74);
  line += "["+ color + result + string(COLOR_RESET) +"]";

  return line;
}

/**
 *
 */
void printTestResult(string label, bool success) {
  cout << formatResult(2, label, success) << endl;
}
