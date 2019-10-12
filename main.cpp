#include "GenStack.h"
#include "ErrorCheck.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main(int argc, char **argv){
  ErrorCheck e;
  try{
    string file;
    cout<<"Please enter the name of the file to check: "<<endl;
    cin>>file;
    ifstream fileStream(file);
    fileStream.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
    e.setFile(file);
    e.check();
  }
  catch(std::exception const& e){
    cout << "Could not open file: " << e.what() << endl;
  }
}
