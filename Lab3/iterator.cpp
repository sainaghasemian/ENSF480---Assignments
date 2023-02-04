/*
* File Name: iterator.cpp
* Assignment: Lab 3 Exercise B
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 11, 2022
*/

#include <iostream>
#include <assert.h>
#include <string.h>
#include "mystring2.h"

using namespace std;


template <class T>
class Vector 
{
  public: 

    class VectIter
    {
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

template <class Type>
Vector<Type>::Vector(int sz)
{
  size=sz;
  array = new Type[sz];
}

template <class Type>
Vector<Type>::~Vector()
{
  delete [] array;
  array = nullptr;
}

template <class Type>
Type& Vector<Type>::operator [] (int i)
{
  return array[i];
}

template <class Type>
void Vector<Type>::swap(Type& a, Type& b)
{
	Type tmp = a;
	a = b;
	b = tmp;
}

template<>
void Vector<Mystring>::ascending_sort()
{
  int min = 0;
  for(int i=0; i< size-1; i++)
  {
    min = i;
    for(int j = i + 1; j < size; j++)
    {
      int k = 0;
      bool swap = false;
      while(array[j].get_char(k) != '\0' && array[min].get_char(k) != '\0')
      {
        if(array[j].get_char(k) < array[min].get_char(k))
        {
          min = j;
          swap = true;
        }
        
        k++;
      }
      if(array[j].length() > array[min].length() && !swap)
      {
        min = j;
      }
    }

    if(min != i)
    {
      swap(array[i], array[min]);
    }
  }
}

template<>
void Vector<const char*>::ascending_sort()
{
  int min = 0;
	for(int i=0; i< size-1; i++)
  {
    min = i;
    for(int j = i + 1; j < size; j++)
    {
      if(strcmp(array[j], array[min]) < 0)
      {
        min = j;
      }
    }
    if(min != i)
    {
      swap(array[min], array[i]);
    }
  }	
}

template <class Type>
void Vector<Type>::ascending_sort()
{
  int min = 0;
	for(int i=0; i< size-1; i++)
  {
    min = i;
    for(int j = i + 1; j < size; j++)
    {
      if(array[j] < array[min])
      {
        min = j;
      }
    }
    if(min != i)
    {
      swap(array[min], array[i]);
    }
  }	
}

//ALL THE OTHER OPERATORS NEED TO BE ADDED FROM .H FILE OP++, OP--

template <class Type>
Vector<Type>::VectIter::VectIter(Vector& x)
{
  v = &x;
  index = 0;
}

template <class Type>
Type& Vector<Type>::VectIter::operator++()
{
  index++;

  if(index > v->size - 1)
  {
    index = 0;
  }

  return v -> array[index];
}


template <class Type>
Type& Vector<Type>::VectIter::operator++(int)
{
  int returnIndex = index;
  index++;

  if(index > v->size)
  {
    index = 0;
  }

  return v -> array[returnIndex];
  
}


template <class Type>
Type& Vector<Type>::VectIter::operator--()
{

  index--;

  if(index < 0)
  {
    index = v->size - 1;
  }

  return v -> array[index];
}

template <class Type>
Type& Vector<Type>::VectIter::operator--(int)
{
  int returnIndex = index;
  index--;

  if(index < 0)
  {
    index = v->size - 1;
  }

  return v -> array[returnIndex];
}


template <class Type>
Type& Vector<Type>::VectIter::operator *()
{
  return v -> array[index];
}


int main()
{

 Vector<int> x(3);
 x[0] = 999;
 x[1] = -77;
 x[2] = 88;

 Vector<int>::VectIter iter(x);

 cout << "\n\nThe first element of vector x contains: " << *iter; 

 // the code between the  #if 0 and #endif is ignored by
 // compiler. If you change it to #if 1, it will be compiled
 
#if 1
	cout << "\nTesting an <int> Vector: " << endl;
	
	cout << "\n\nTesting sort";
	x.ascending_sort();


	for (int i=0; i<3 ; i++)
		cout << endl << iter++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iter;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iter;	
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iter--;
	
	cout << endl;
	
	cout << "Testing a <Mystring> Vector: " << endl;
	Vector<Mystring> y(3);
  
	y[0] = "Bar";
	y[1] = "Foo";
	y[2] = "All";;
	
	Vector<Mystring>::VectIter iters(y);
	cout << "\n\nTesting sort";
  
	y.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iters++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iters;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iters;
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iters--;
	
	cout << endl; cout << "Testing a <char *> Vector: " << endl;
	Vector<const char*> z(3);
	z[0] = "Orange";
	z[1] = "Pear";
	z[2] = "Apple";;
	
	Vector<const char*>::VectIter iterchar(z);
	
	cout << "\n\nTesting sort";
	z.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iterchar++;
	
#endif
	cout << "\nPrgram Terminated Successfully." << endl;
	
	return 0;
}












