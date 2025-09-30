#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
using namespace std;

Node::Node(const int& keyA, const Datum& datumA, Node *nextA)
: keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
: sizeM(0), headM(0), cursorM(0)
{
}

int DictionaryList::size() const
{
    return sizeM;
}

int DictionaryList::cursor_ok() const
{
    return cursorM != 0;
}

const int& DictionaryList::cursor_key() const
{
    assert(cursor_ok());
    return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
    assert(cursor_ok());
    return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const string& datumA)
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



// The following functions are supposed to be completed by the stuents, as part
// of the exercise B. the given code for this fucntion are just place-holders
// in order to allow successful linking when you're esting insert and remove.
// Replace them with the definitions that work.


DictionaryList::DictionaryList(const DictionaryList& source) : sizeM(source.sizeM), headM(nullptr), cursorM(nullptr)
{

    // Students should replace these messages with proper code.

    // Logic was adapted from assignments in ENSF 694 (last semester)

    if (source.headM == nullptr){ // if source is empty do nothing
        return;
    }

    // copy head node
    headM = new Node(source.headM->keyM, source.headM->datumM, nullptr);
    if (source.cursorM == source.headM) cursorM = headM; // if cursor at head, set new cursor to head

    // go through rest of list copying nodes
    Node* dstTail = headM;
    for (Node* sp = source.headM->nextM; sp != nullptr; sp = sp->nextM) {
        dstTail->nextM = new Node(sp->keyM, sp->datumM, nullptr);
        dstTail = dstTail->nextM;
        if (sp == source.cursorM) cursorM = dstTail; // set cursor to source cursor position
    }
}

DictionaryList& DictionaryList::operator=(const DictionaryList& rhs)
{

    // Students should replace these messages with proper code.

    if (this == &rhs) return *this;  // if it is the same object, do nothing

    make_empty(); // remove current contents

    // copy values from rhs to lhs
    sizeM = rhs.sizeM;
    headM = nullptr;
    cursorM = nullptr;

    if (rhs.headM == nullptr) { // rhs is empty, do nothing
        return *this; 
    }

    // copy head node
    headM = new Node(rhs.headM->keyM, rhs.headM->datumM, nullptr);
    if (rhs.cursorM == rhs.headM) {
        cursorM = headM;
    }

    // Go through rest of list, copying nodes
    Node* dstTail = headM;
    for (Node* sp = rhs.headM->nextM; sp != nullptr; sp = sp->nextM) {
        dstTail->nextM = new Node(sp->keyM, sp->datumM, nullptr);
        dstTail = dstTail->nextM;

        if (sp == rhs.cursorM) { // set cursor to same location as rhs
            cursorM = dstTail;
        }
    }

    return *this; // return the lhs (current object)
}



DictionaryList::~DictionaryList(){

    make_empty(); // just calls the make_empty() fcn

}


void DictionaryList::find(const int& keyA)
{
    // Students should replace these messages with proper code.

    cursorM = nullptr; // initially point off-list


    Node* p = headM; // start a pointer at head node
    while (p != nullptr && keyA > p->keyM) { // while not at end of list, and the key is greater than the current node's key
        p = p->nextM; // traverse
    }

    // If match is found, point to it
    if (p != nullptr && p->keyM == keyA) {
        cursorM = p;
    }
}


void DictionaryList::make_empty()
{
    // Students should replace these messages with proper code.

    Node* p = headM; // point to start of list (head node)
    while (p != nullptr) { // while the current node exists
        Node* doomed = p; // node to be deleted
        p = p->nextM; // point to next node
        delete doomed; // delete the node
    }
    headM = nullptr; // reset values
    cursorM = nullptr;
    sizeM = 0;
}