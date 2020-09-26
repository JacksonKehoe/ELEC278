// LLIST1.C [140911]
// Code provided for ELEC278 Lab 1 Part 5.
// Implements a single linked list.
// Based on earlier code. Improved (IMHO) by adding and clarifying
// comments, format, etc.
//
// History:
//	140911	XXX		Original
//	170910	DFA		Change comments, formatting


#include "llist1A.h"


int isEmpty (LList1 *l)
// Return false (0) or true (non-zero) depending on whether list is empty
{
    if (l != NULL)
        return (l->head == NULL);
    else
        return 1;	// list not set up - obviously empty
}//isEmpty()


Node* initNode (int v)
// Create and initialize a Node structure
{
    Node* node = malloc(sizeof(Node));	// get memory for node
	if (node != NULL)	{
    	node->value = v;
    	node->next = NULL;
		}
    return node;		// caller should check for non-NULL value
}//initNode()


LList1* initList (void)
// Create new list.  Creates list descriptor, and list with no nodes.
{
    LList1 *list = malloc(sizeof(LList1));
	if (list != NULL)	{
    	list->size = 0;
    	list->head = NULL;
		}
    return list;		// caller should check for non-NULL value
}//initList()


void printList (LList1 *l)
// Print representation of linked list, showing values of all nodes
{
	if (l != NULL)	{
		// Have list - check first if it's empty
        if (!isEmpty(l))	{
			// Nodes in list - go through all of them
			// Exercise for the student - can you express this loop control
			// using a for instead of a while?
            Node *link = l->head;
            while (link != NULL)	{
                printf("%d-->",link->value);
                link = link->next;
                }
            printf("NULL\n");
        } else	{
			printf ("EMPTY\n");
			}
    	}
}//printList()


void insertFront(int v, LList1 *lnklst)
// Insert new value at front of list.
{
	// Make sure that linked list exists.  Should probably return an error
	// if not - or maybe set up a new linked list.
    if (lnklst != NULL)	{
        /* create new node to hold new value */
        Node* newnode = initNode(v);
		// Add new node to list. Note that new node is placed at the head
		// of the list, which may or may not be empty.
        // If list not empty, new node has to point to existing list
        if (!isEmpty(lnklst))	newnode->next = lnklst->head;
		// In any case, new node becomes first node in list
		lnklst->head = newnode;
		}//endif
}//insertFront()


//*** THIS IS THE CODE THAT YOU WILL MODIFY.  SEE THE SECTIONS MARKED
//*** "fill in code here"

Node* extract(int v, LList1 *list)
// Find node with value v, and extract it from list. Return pointer to node
// found.  If no node contains v, return NULL.
{
    Node	*link1=NULL, *link2=NULL, *resNode=NULL;

	/* check if list is NULL */
    if (list != NULL) {
        if (list->head != NULL)	{
			/* something in list. */
			/* Check if first node contains value */
            if (list->head->value == v)	{
				/*** fill in code here ***/
				/* Make resNode point to first node, then remove node
				 * from list */
                resNode = list->head ;
                list->head = list->head->next ;
                list->size-- ;
            } else	{
				/* first node doesn't contain value v.
				 * Must traverse list to find it */
                link1 = list->head ;
                link2 = link1->next ;
				/* Move link1 and link2 until you find link with
				 * value v or reach end of list */
				/*** fill in code here ***/
                while ((link2 != NULL) && (link2->value!=v)) {
                    link1 = link2 ;
                    link2 = link1->next ;
                	}
				/* At this point, either value found or came to end of list.
				 * If found, link2 points to node. If not found, link2
				 * is NULL. */
				
				/* update resNode accordingly */
				/*** fill in code here ***/
				if (link2 != NULL)	{
					resNode = link2;	/* node containing value */
					/* recall that link1 points to node before link2 node */
                    link1->next = link2->next ;
                    list->size-- ;
            		}
        		}/* endif(list->head-value is/isn't = v) */
    		}/* endif(list->head not NULL) */
		}/* endif(list not NULL) */
    return resNode;
}//extract()
