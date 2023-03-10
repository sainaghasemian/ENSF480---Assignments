/*
* File Name: vector.h
* Assignment: Lab 3 Exercise B
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 11, 2022
*/

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <class T>
class Vector {
public: 

  class VectIter{
    friend class Vector;
  private:
    Vector *v; // points to a vector object of type T
    int index;    // represents the subscript number of the vector's
                  // array.
  public:
    VectIter(Vector& x);
 
    T& operator++();
    //PROMISES: increments the iterator's indes and return the 
    //          value of the element at the index position. If
    //          index exceeds the size of the array it will 
    //          be set to zero. Which means it will be circulated
    //          back to the first element of the vector.

    T&  operator++(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then increments the index. If
    //           index exceeds the size of the array it will 
    //           be set to zero. Which means it will be circulated
    //           back to the first element of the vector.

    T&  operator--();
    // PROMISES: decrements the iterator index, and return the
    //           the value of the element at the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    T&  operator--(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then decrements the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    T& operator *();
    // PRIMISES: returns the value of the element at the current 
    //           index position.
  };

  Vector(int sz); 
  ~Vector();

  T& operator[](int i);
  // PRIMISES: returns existing value in the ith element of 
  //           array or sets a new value to  the ith element in
  //           array. 
  
	void ascending_sort();
  // PRIMISES: sorts the vector values in ascending order. 
	
private:
  T *array;               // points to the first element of an array of T
  int size;               // size of array
  void swap(T&, T&); // swaps the values of two elements in array
};


template <>
class Vector<const char*> {
public: 

  class VectIter{
    friend class Vector;
  private:
    Vector *v; // points to a vector object of type T
    int index;    // represents the subscript number of the vector's
                  // array.
  public:
    VectIter(Vector& x);
 
    char* operator++();
    //PROMISES: increments the iterator's indes and return the 
    //          value of the element at the index position. If
    //          index exceeds the size of the array it will 
    //          be set to zero. Which means it will be circulated
    //          back to the first element of the vector.

    char*  operator++(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then increments the index. If
    //           index exceeds the size of the array it will 
    //           be set to zero. Which means it will be circulated
    //           back to the first element of the vector.

    char*  operator--();
    // PROMISES: decrements the iterator index, and return the
    //           the value of the element at the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    char*  operator--(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then decrements the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    char* operator *();
    // PRIMISES: returns the value of the element at the current 
    //           index position.
  };

  Vector(int sz); 
  ~Vector();

    char* operator[](int i);
  // PRIMISES: returns existing value in the ith element of 
  //           array or sets a new value to  the ith element in
  //           array. 
  
	void ascending_sort();
  // PRIMISES: sorts the vector values in ascending order. 
	
private:
  char** array;               // points to the first element of an array of T
  int size;               // size of array
  void swap( char *&,  char *&); // swaps the values of two elements in array
};



#endif