/*
*   File Name: dictionaryList.cpp
*   Assignment: Lab 2 Exercise A
*   Completed by: Trevor Nguyen and Zachary Lam
*   Submission Date: Sept 23, 2024 
*/

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

void DictionaryList::insert(const int& keyA, const Datum& datumA)
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
  while (cursorM != 0 && cursorM->keyM != keyA)
    cursorM = cursorM->nextM;
}


void DictionaryList::destroy()
{
  cursorM = headM;
  while (cursorM != 0)
    {
      Node *p = cursorM;
      cursorM = cursorM->nextM;
      delete p;
    }
  headM = 0;
  sizeM = 0;
  cursorM = 0;
}


void DictionaryList::copy(const DictionaryList& source)
{
    if (source.headM == 0) {
        headM = 0;
        cursorM = 0;
        sizeM = 0;
        return;
    }

    headM = new Node(source.headM->keyM, source.headM->datumM, 0);

    Node* src_node = source.headM->nextM;
    Node* dest_node = headM;

    while (src_node != 0) {
        dest_node->nextM = new Node(src_node->keyM, src_node->datumM, 0);

        if (src_node == source.cursorM) {
            cursorM = dest_node->nextM;
        }

        dest_node = dest_node->nextM;
        src_node = src_node->nextM;
    }

    sizeM = source.sizeM;

    if (source.cursorM == source.headM) {
        cursorM = headM;
    }
}

const Datum& DictionaryList::operator[](int index) const{
  if (index >= sizeM || index < 0){
    cout << "Error, cannot access data" << endl;
    exit(1);
  }
  if (headM == nullptr) {
    throw std::out_of_range("No items found in list");
  }
  Node* p = headM;
  for (int i = 0; i < index; ++i) {
    p = p->nextM;
  }
  return p->datumM; // returns the reference to Datum object


}

std::ostream& operator<<(std::ostream& os, const DictionaryList& source){
    if (source.headM == nullptr){ //checks if the list is empty
      os << "No items found in list" << std::endl;
    }
    else{
      Node* p = source.headM;
      while(p != nullptr) { // loop continues as pointer p is not nullptr
        os << p->keyM << " " << p->datumM << std::endl;
        p = p->nextM;
      }
    }
    return os;
}