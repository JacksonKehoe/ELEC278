// LLIST1A.H [140911]
// Code provided for ELEC278 Lab 1 Step 5.
// This code provides additional comments that the reader may find
// helpful when understanding this code.
// History:
//	140911	XXX		Original
//	170910	DFA		Updated version

#ifndef LLIST1_H_INCLUDED
#define LLIST1_H_INCLUDED
// Previous two lines are a device used to make sure that a header file
// is not processed more than once.  If the preprocessor symbol
// LLIST1_H_INCLUDED is not yet defined, then the rest of the file is
// processed by the preprocessor.  If it is already defined, then the
// rest of this file is skipped.  Modern compilers provide other techniques
// to ensure once-only processing, but the technique used here always works.

#include <stdlib.h>
#include <stdio.h>

// Often, linked lists are described as being made up of nodes. The original
// version of this code called the individual items Links, and then called
// the linked list LList1.  So a LList was made up of List items.  Using a
// different name tends to help focus on whether you are thinking about the
// whole list or just one of the items in the list.

typedef struct _Node {
    int value;
    struct _Node *next;
} Node;

typedef struct {
    int size;
    Node *head;
} LList1;

void	insertFront(int v, LList1 *l);	/* prepend */
void	insertEnd(int v, LList1 *l);	/* append */
Node	*removeFront(LList1 *l);
void	removeEnd(LList1 *l);
Node*	extract(int v, LList1 *list);
Node*	initLink (int v);
LList1*	initList ();
int		isEmpty(LList1 *l) ;
void	printList (LList1 *l);

#endif // LLIST1_H_INCLUDED
