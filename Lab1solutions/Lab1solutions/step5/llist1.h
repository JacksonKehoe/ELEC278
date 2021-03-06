/* LLIST1.H [140911]
 * Code provided for ELEC278 Lab 1 Step 5.
 */

#ifndef LLIST1_H_INCLUDED
#define LLIST1_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct _Link {
    int value;
    struct _Link *next;
} Link;

typedef struct {
    int size;
    Link *head;
} LList1;

void	insertFront(int v, LList1 *l);	/* prepend */
void	insertEnd(int v, LList1 *l);	/* append */
Link	*removeFront(LList1 *l);
void	removeEnd(LList1 *l);
Link*	extract(int v, LList1 *list);
Link*	initLink (int v);
LList1*	initList ();
int		isEmpty(LList1 *l) ;
void	printList (LList1 *l);

#endif // LLIST1_H_INCLUDED
