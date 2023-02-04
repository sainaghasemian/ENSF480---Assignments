/*
* File Name: dictionaryList.cpp
* Assignment: Lab 2 Exercise A
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

// lookuptable.cpp


#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?                                                                                  
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
	
  // Overwrite datum at head?                                                                               
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
	
  // Have to search ...                                                                                     
  else {
      
    //POINT ONE
		
    // if key is found in list, just overwrite data;                                                        
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}
		
    //OK, find place to insert new node ...                                                                 
    Node *p = headM ->nextM;
    Node *prev = headM;
		
    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}
		
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
	
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    } 
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key& keyA)
{
  cursorM = headM;

  while(cursorM->keyM != keyA)
  {
    if(cursorM->nextM == nullptr)
    {
      cursorM = nullptr;
      break;
    }
    cursorM = cursorM->nextM;
  }
}


void DictionaryList::destroy()
{
  cursorM = headM;

  while(cursorM != nullptr) 
  {
    Node *next = cursorM;
    cursorM = next->nextM;
    delete cursorM;
  }
  
  headM = nullptr;
}


void DictionaryList::copy(const DictionaryList& source)
{
  if (this == &source) return;

  headM = 0;
  sizeM = 0;
  cursorM = 0;
  Node *temp = source.headM;
   
  while(temp != nullptr)
  {
      insert(temp->keyM, temp->datumM);
      temp = temp->nextM;
  }

  if(source.cursorM != nullptr) 
  {
    find(source.cursorM->keyM); 
  }

}

 const Mystring& DictionaryList::operator[] (const int index)
  {
    go_to_first();

    int i = 0;
    while(i < index)
    {
      step_fwd();
      i++;
    }

    return cursor_datum();
  }

  ostream& operator<<(ostream& os, DictionaryList& dl)
  {
    os.clear();

    //cout<< dl.size();
    char* output = new char[dl.size() * 10];

    //char* output;

    dl.go_to_first();

    int i = 0; //i is index of the output char array
    int k = 0;
    while(dl.cursor_ok())
    {
      int j = 0; //j is index of the keyString
      
      string keyString = to_string(dl.cursor_key());

      while(keyString[j] != '\0') //while loop adds Key to output char array
      {
        output[i] = keyString[j];
        i++;
        j++;
      }

      output[i++] = ' ';
      output[i++] = ' ';

      j = 0;
      while(dl.cursor_datum().get_char(j) != '\0') //while loop adds Datum to output char array
      {
        output[i] = dl.cursor_datum().get_char(j);
        i++;
        j++;
      }
    
      if(k < dl.size() - 1)
      {
        output[i++] = '\n';
      }

      k++;

      dl.step_fwd();
      
    }

    return os<<output;
  }


