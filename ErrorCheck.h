#pragma once
#include <iostream>
#include <string>
using namespace std;
class ErrorCheck{
public:
  ErrorCheck();
  ~ErrorCheck();

  void setFile(string fileName);
  void check();
private:
  string fileName;
  string file;
  char topStack;
};
