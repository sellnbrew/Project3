#include "ErrorCheck.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ErrorCheck::ErrorCheck(){//nothin in here?

}
ErrorCheck::~ErrorCheck(){
}
void ErrorCheck::setFile(string fileName){//sets file name
  this->fileName = fileName;
}
void ErrorCheck::check(){//error checking
  GenStack <char> myStack;
  string line;
  ifstream file;
  file.open(fileName);
  int count=0;
  while(file){
    count++;
    getline(file, line);//get line of file
    for(char c: line){//itterates through each char of file
      if(c=='{'||c=='['||c=='('){
        myStack.push(c);//pushes openers
      }
      else if(c=='}'||c==']'||c==')'){
        if(myStack.isEmpty()==0){
          topStack = myStack.peak();
          if(topStack !='{'&& c=='}'){//checks if closer and compairs to last item in stack
            cout<<"Error expected } at line: "<<count<<endl;
            myStack.~GenStack();
            exit(0);
          }
          else if(topStack !='['&& c==']'){
            cout<<"Error expected ] at line: "<<count<<endl;
            myStack.~GenStack();
            exit(0);
          }
          else if(topStack !='('&& c==')'){
            cout<<"Error expected ) at line: "<<count<<endl;
            myStack.~GenStack();
            exit(0);
          }
          else{//if it lines up then it removes item from stack
            myStack.pop();
            continue;
          }
        }
        else{
          cout<<"Error closer with no opener at line: "<<count<<endl;
          myStack.~GenStack();
          exit(0);
          }
        }
      }
    }
    if(myStack.isEmpty()==1){//if empty no errors
      cout<<"No errors detected"<<endl;
      myStack.~GenStack();
      exit(0);
    }
    else if(myStack.isEmpty()==0){//if not empty its missing a closer
      cout<<"Error: reached end of file closer expected"<<endl;
      myStack.~GenStack();
      exit(0);
    }
  }
