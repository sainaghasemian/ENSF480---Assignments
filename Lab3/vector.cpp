/*
* File Name: vector.cpp
* Assignment: Lab 3 Exercise B
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 11, 2022
*/

#include <string.h>
#include <iostream>
#include <assert.h>
#include "vector.h"
#include "mystring2.h"

template <class Type>
void Vector<Type>::ascending_sort()
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
			if(array[i] > array[j])
				swap(array[i], array[j]);
}

template <class Type>
void Vector<Type>::swap(Type& a, Type& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


template <class Type>
Type& Vector<Type>::VectIter::operator *()
{
  return v -> array[index];
}

template <class Type>
Type& Vector<Type>::operator [] (int i)
{
  return array[i];
}

//ALL THE OTHER OPERATORS NEED TO BE ADDED FROM .H FILE OP++, OP--

template <class Type>
Vector<Type>::VectIter::VectIter(Vector& x)
{
  v = &x;
  index = 0;
}

template <class Type>
Vector<Type>::Vector(int sz)
{
  size=sz;
  array = new Type[sz];
  for(int i=0; i<sz; i++)
  {
    array[i] = i+1;
  }
}

template <class Type>
Vector<Type>::~Vector()
{
  delete [] array;
  array = nullptr;
}


//NEED TO RE DO SAME THING AS ABOVE FOR CHAR*