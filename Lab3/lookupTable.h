/*
*   File Name: lookupTable.h
*   Assignment: Lab 3 Exercise C
*   Completed by: Trevor Nguyen and Zachary Lam
*   Submission Date: Sept 30, 2024 
*/

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>
#include <assert.h>

using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse trhough the list and  have acess to each
//    node. 

#include "customer.h"

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.


typedef int LT_Key; 
typedef Customer LT_Datum;

template<typename Key, typename Datum>
class LookupTable;

template<typename Key, typename Datum>
class LT_Node;

template<typename Key, typename Datum>
struct Pair 
{
  Pair(Key keyA, Datum datumA):key(keyA), datum(datumA){} 
  
  Key key;
  Datum datum;
};

template<typename Key, typename Datum>
class LT_Node {
  friend class LookupTable<Key, Datum>;
  
private:
  Pair<Key, Datum> pairM;
  LT_Node<Key, Datum> *nextM;

  // This ctor should be convenient in insert and copy operations.
  LT_Node(const Pair<Key, Datum>& pairA, LT_Node<Key, Datum>* nextA);
};

template<typename Key, typename Datum> 
class LookupTable {
 public:
  typedef Key LT_Key;
  typedef Datum LT_Datum;  

  // Nested class
  class Iterator {
    friend class LookupTable<Key, Datum>;
    LookupTable<Key, Datum>* LT;
    LT_Node<Key, Datum>* cursor;
    
  public:
    Iterator():LT(0){}
    Iterator(LookupTable<Key, Datum>& x) : LT(&x) {}
    const LT_Datum& operator *();
    const LT_Datum& operator ++();
    const LT_Datum& operator ++(int);
    int operator !();

    void step_fwd(){    
      assert(LT->cursor_ok());
      LT->step_fwd();}
  };

  LookupTable();
  LookupTable(const LookupTable<Key, Datum>& source);
  LookupTable& operator=(const LookupTable<Key, Datum>& rhs);
  ~LookupTable();

  LookupTable& begin();

  int size() const;
  // PROMISES: Returns number of keys in the table.

  int cursor_ok() const;
  // PROMISES: 
  //   Returns 1 if the cursor is attached to a key/datum pair,
  //   and 0 if the cursor is in the off-list state.

  const Key& cursor_key() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns key of key/datum pair to which cursor is attached.

  const Datum& cursor_datum() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns datum of key/datum pair to which cursor is attached.

  void insert(const Pair<Key, Datum>& pairA);
  // PROMISES:
  //   If keyA matches a key in the table, the datum for that
  //   key is set equal to datumA.
  //   If keyA does not match an existing key, keyA and datumM are
  //   used to create a new key/datum pair in the table.
  //   In either case, the cursor goes to the off-list state.

  void remove(const Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursor goes to the off-list state.

  void find(const Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the cursor is attached
  //   to the corresponding key/datum pair.
  //   If keyA does not match an existing key, the cursor is put in
  //   the off-list state.

  void go_to_first();
  // PROMISES: If size() > 0, cursor is moved to the first key/datum pair
  //   in the table.

  void step_fwd();
  // REQUIRES: cursor_ok()
  // PROMISES: 
  //   If cursor is at the last key/datum pair in the list, cursor
  //   goes to the off-list state.
  //   Otherwise the cursor moves forward from one pair to the next.

  void make_empty() ;
  // PROMISES: size() == 0.
  template<typename K, typename D>
  friend  ostream& operator << (ostream& os, const LookupTable<K, D>& lt);

 private:
  int sizeM;
  LT_Node<Key, Datum>* cursorM;
  LT_Node<Key, Datum>* headM;

  void destroy();
  // Deallocate all nodes, set headM to zero.
  
  void copy(const LookupTable<Key, Datum>& source);
  // Establishes *this as a copy of source.  Cursor of *this will
  // point to the twin of whatever the source's cursor points to.
};

#endif

template<typename Key, typename Datum>
LookupTable<Key, Datum>& LookupTable<Key, Datum>::begin() {
    cursorM = headM;
    return *this;
}

template<typename Key, typename Datum>
LT_Node<Key, Datum>::LT_Node(const Pair<Key, Datum>& pairA, LT_Node<Key, Datum> *nextA)
  : pairM(pairA), nextM(nextA)
{
}

template<typename Key, typename Datum>
LookupTable<Key, Datum>::LookupTable() : cursorM(nullptr), headM(nullptr), sizeM(0) {}

template<typename Key, typename Datum>
LookupTable<Key, Datum>::LookupTable(const LookupTable<Key, Datum>& source) : cursorM(nullptr), headM(nullptr), sizeM(0) {
    copy(source);
    // Copy constructor implementation
}

template<typename Key, typename Datum> 
LookupTable<Key, Datum>& LookupTable<Key, Datum>::operator=(const LookupTable<Key, Datum>& rhs) {
    if (this != &rhs) {
        destroy();
        copy(rhs);
        // Assignment operator implementation
    }
    return *this;
}


template<typename Key, typename Datum>
LookupTable<Key, Datum>::~LookupTable() {
    destroy();
    // Destructor implementation
}

template<typename Key, typename Datum>
int LookupTable<Key, Datum>::size() const {
    return sizeM;
}

template<typename Key, typename Datum>
int LookupTable<Key, Datum>::cursor_ok() const {
    return cursorM != nullptr;
}

template<typename Key, typename Datum>
const Key& LookupTable<Key, Datum>::cursor_key() const {
    assert(cursor_ok());
    return cursorM->pairM.key;
}


template<typename Key, typename Datum> 
const Datum& LookupTable<Key, Datum>::cursor_datum() const {
    assert(cursor_ok());
    return cursorM->pairM.datum;
}
template<typename Key, typename Datum>
void LookupTable<Key, Datum>::insert(const Pair<Key, Datum>& pairA)
{
  // Add new node at head?
  if (headM == 0 || pairA.key < headM->pairM.key) {
    headM = new LT_Node<Key, Datum>(pairA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;

  // Have to search ...

  else {
    LT_Node<Key, Datum>* before= headM;
    LT_Node<Key, Datum>* after=headM->nextM;

    while(after!=NULL && (pairA.key > after->pairM.key))
      {
	before=after;
	after=after->nextM;
      }
    
    if(after!=NULL && pairA.key == after->pairM.key)
      {
	  after->pairM.datum = pairA.datum;
      }
    else
      {
	before->nextM = new LT_Node<Key, Datum> (pairA, before->nextM);
	sizeM++;
      }
  }
}

template<typename Key, typename Datum>
void LookupTable<Key, Datum>::remove(const Key& keyA)
{

  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node<Key, Datum>* doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else {
    LT_Node<Key, Datum>      *before = headM;
    LT_Node<Key, Datum> *maybe_doomed = headM->nextM;
    while(maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }      
  } 
  delete doomed_node;           // Does nothing if doomed_node == 0.
}

template<typename Key, typename Datum> 
void LookupTable<Key, Datum>::find(const Key& keyA) {
  LT_Node<Key, Datum> *ptr=headM;
  while (ptr != NULL && ptr->pairM.key != keyA)
    {
     ptr=ptr->nextM;
    }

   cursorM = ptr;
}

template<typename Key, typename Datum>
void LookupTable<Key, Datum>::go_to_first() {
  cursorM = headM;
}

template<typename Key, typename Datum>
void LookupTable<Key, Datum>::step_fwd() {
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

template<typename Key, typename Datum>
void LookupTable<Key, Datum>::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template<typename Key, typename Datum>
void LookupTable<Key, Datum>::destroy()
{

  LT_Node<Key, Datum> *ptr = headM;
  while (ptr!=NULL)
    {
      headM=headM->nextM;
      delete ptr;
      ptr=headM;

    }
  cursorM = NULL;
  sizeM=0;
}

template<typename Key, typename Datum>
void LookupTable<Key, Datum>::copy(const LookupTable<Key, Datum>& source)
{

  headM=0;
  cursorM =0;

  if(source.headM ==0)
    return;
 
  for(LT_Node<Key, Datum> *p = source.headM; p != 0; p=p->nextM)
    {
      insert(Pair (p->pairM.key, p->pairM.datum));
      if(source.cursorM == p)
	find(p->pairM.key);
    }

}

template<typename Key, typename Datum>
ostream& operator <<(ostream& os, const LookupTable<Key, Datum>& lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}

template<typename Key, typename Datum> 
const Datum& LookupTable<Key, Datum>::Iterator::operator*() {
    assert(LT->cursor_ok());
    return LT->cursor_datum();
}


template<typename Key, typename Datum> 
const Datum& LookupTable<Key, Datum>::Iterator::operator++() {
    step_fwd();
    return LT->cursor_datum();
}


template<typename Key, typename Datum> 
const Datum& LookupTable<Key, Datum>::Iterator::operator++(int) {
    const Datum& temp = LT->cursor_datum();
    step_fwd();
    return temp;
}


template<typename Key, typename Datum> 
int LookupTable<Key, Datum>::Iterator::operator!() {
    return !LT->cursor_ok();
}

