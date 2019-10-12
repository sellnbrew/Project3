#pragma once
#include <iostream>
#include <string>
//#include "EmptyStackException.h"
using namespace std;

template <class T>
class GenStack{
public:
  GenStack(); //constructor
  GenStack(int maxStack); //overloaded constructor
  ~GenStack();  //destructor

  void push(T d);
  T pop();
  T peak(); //aka top()
  void enlarge(int size);

//helper functions
  bool isFull();
  bool isEmpty();

private:
  int size;
  int top;

  T *myArray; //points to memory address
  //intialize array, points the first element in the array, helps us find the size of the array
};

template <class T>
GenStack<T>::GenStack(){    //default constructor
  //initialization of default values
  myArray = new T[256];
  size = 256;
  top=-1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize]; //array is in the heap
  size = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){
  delete myArray;
}

template <class T>
void GenStack<T>::push(T d){
  //need to check error/boundary check
  //make sure there's room in it before you push
  if(isFull()){
      //call a new array and double size
      enlarge(size);

  }
  myArray[++top] = d;

}

template <class T>
void GenStack<T>::enlarge(int size){
  T* newArray = new T[2*size];
  for(int i =0; i<size; ++i){
    newArray[i] = myArray[i];
  }
  delete myArray;
  myArray = newArray;
}

template <class T>
T GenStack<T>::pop(){
  //error checking, make sure its not empty
  if(isEmpty()){
    //throw EmptyStackException();
    throw "Empty Stack";
  }
  return myArray[top--]; //returns and removes
}

template <class T>
T GenStack<T>::peak(){
  //check if empty
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull(){
  return (top==size-1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return(top== -1);
}
