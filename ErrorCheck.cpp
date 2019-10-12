#include "ErrorCheck.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ErrorCheck::ErrorCheck(){

}
ErrorCheck::~ErrorCheck(){
}
void ErrorCheck::setFile(string fileName){
  this->fileName = fileName;
}
void ErrorCheck::check(){
  GenStack <char> myStack;
  string line;

  ifstream file;
  file.open(fileName);
  int count=0;
  while(file){
    count++;
    getline(file, line);
    for(char c: line){
      if(c=='{'||c=='['||c=='('){
        myStack.push(c);
      }
      else if(c=='}'||c==']'||c==')'){
        if(myStack.isEmpty()==0){
          topStack = myStack.peak();
          if(topStack !='{'&& c=='}'){
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
          else{
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
    if(myStack.isEmpty()==1){
      cout<<"No errors detected"<<endl;
      myStack.~GenStack();
      exit(0);
    }
    else if(myStack.isEmpty()==0){
      cout<<"Error: reached end of file closer expected"<<endl;
      myStack.~GenStack();
      exit(0);
    }
  }
