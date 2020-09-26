// LinkedLists.c
// Code provided for ELEC278 Lab 2
// This version uses a linked list to store the data in the set

#include <stdio.h>
#include <stdlib.h>


// Node (or element) in list holds value and pointer to next element
typedef struct Node {
	int			value;
	struct Node	*next;
} Node;


Node *createNode (int x, Node *nxt)
// Create new Node and initialize its value and next pointer
{
	Node *pNode = (Node *)malloc (sizeof(Node));
	if (pNode != NULL)	{
		pNode->value = x;
		pNode->next = nxt;
		}
	return pNode;
}//createNode()


// LinkedList structure has pointer to first element, and count of
// elements in list.
typedef struct LinkedList {
	Node	*head;
	int		size;
} LinkedList;


int isEmpty(LinkedList *l)
// Check if LinkedList is empty. It is empty if head pointer is NULL
{
	return (l->head == NULL);
}//isEmpty()


void init(LinkedList *l)
// Initialize LinkedList structure
{
    l->head = NULL;
    l->size = 0;
}//init()


void addFront(LinkedList* l,int x)
// Add new Node to front of linked list. Create and initialize new Node
// structure with value and current head-of-list pointer.  Make head-of-list
// point to new node
{
    Node* newNode = createNode (x, l->head);
	printf ("Adding %d to front of list\n", x);
    l->head = newNode;
    l->size++;
}//addFront()


void addEnd(LinkedList* l,int x)
// Add new Node to end of linked list
{
    Node* newNode = createNode (x, NULL);
	printf ("Adding %d to end of list\n", x);
	// start by increasing size of linked list
    l->size++;
	// Now comes the fun part - have to find current last Node, so it
	// can be made to point to the new node
	if (isEmpty (l))	{
		// LinkedList currently empty - new node becomes first in list
		l->head = newNode;
	} else	{
		// Not empty - have to find last Node in current list and make
		// it point to new node.
		Node* ptr = l->head;
		// Traverse list until node found that doesn't point to a next one
		while(ptr->next!=NULL)	{
			ptr = ptr->next;
			}
		// ptr points to a Node with no next Node; make this Node point to
		// new one
		ptr->next = newNode;
		}
	// Our work is done.
}//addEnd()


void removeFront(LinkedList* l)
// Remove first Node from list
{
	printf ("Remove item at front of list\n");
	if (!isEmpty (l))	{
		// List is not empty, so there is a first Node to delete.
		Node *ptr = l->head;		// point to first node
		// Note that list will be one shorter
		l->size--;
		// head of list is now element after first
		l->head = l->head->next;
		// discard node we no longer need
		free(ptr);
		}
}//removeFront()


void removeEnd(LinkedList* l)
// Remove last Node from list
{
	printf ("Remove item at end of list\n");
	// First determine if any work to do
	if (!isEmpty (l))	{
		// Special case - if there is only one Node
		if (l->size==1)	{
			removeFront(l);
		} else	{
			// More than 1. Note how this code requires that a Node
			// be found that points to a last Node (one with a NULL
			// next pointer, and that doesn't work for the list with
			// only 1 Node.  Fun exercise for the student - think about 
			// how to redesign data and code so that all cases can
			// be handled with one piece of code.
			Node* ptr = l->head;
			Node* delPtr;

			// As long as the Node we're pointing to isn't the end of
			// the list, move to next Node
			while(ptr->next->next)	{
				ptr = ptr->next;
				}
			delPtr = ptr->next;
			ptr->next = NULL;
			free(delPtr);
			l->size--;
			}
		}
}//removeEnd()



void destroy(LinkedList* l)
// Delete entire linked list - basically by repeatedly deleting first Node
{
	while(!isEmpty(l))	{
		removeFront(l);
		}
}//destroy()


void removeValue(LinkedList* l,int x)
// Remove first Node in list whose value is x
{
	printf ("Find first %d in list and remove it\n", x);
/* Write your code here */
/* --- <BEGIN SNIP> --- */
	if (isEmpty(l))	return;
	// If first Node has value, remove first node
	if (l->head->value == x)
		removeFront (l);
	else	{
		// Wasn't in first position - traverse until we find one.  We have
		// to keep track of both the node that holds the value and the one
		// prior to it, so we can easily delete the node containing the value.
		Node *prev = l->head;			// points to first Node
		Node *curr = prev->next;		// points to second
		// As long as we have a current node, check it for value
		while (curr != NULL)	{
			if (curr->value == x)	{
				// current node has value we're looking for
				// Previous node needs to point to the one after the current
				// node (to remove th ecurrent node from the list) then the
				// current node needs to be freed.
				prev->next = curr->next;
				l->size--;
				free (curr);
				// basically, that's it
				break;
				}
			// Not found yet - advance both pointers
			prev = curr;
			curr = curr->next;
			}
		}
/* --- <END SNIP> --- */
}//removeValue()


void print(LinkedList *l)
{
    Node* ptr = l->head;
	printf("(");
    if(!ptr)	{
        printf("<EMPTY>");
    } else	{
    	while(ptr->next){
        	printf("%d -> ",ptr->value);
        	ptr = ptr->next;
			}
    	printf("%d",ptr->value);
		}
	printf(") [%d]\n",l->size);
}//print()


void update(LinkedList* l)
// Find smallest value in linked list and subtract that value from each value
{
	printf ("Subtract smallest value from all values in list\n");
/* Write your code here */
/* --- <BEGIN SNIP> --- */
	if (!isEmpty(l))	{
		Node	*ptr = l->head;
		int		min = l->head->value;	// it is a starting point
		// Alternately,
		// int	min = MAXINT;			// smallest value must be smaller!
		// Traverse list, looking for smaller values than what we have so far
		while (ptr != NULL)	{
			if (ptr->value < min)
				// found one even smaller
				min = ptr->value;
			ptr = ptr->next;
			}
		// At this point, we have checked all list elements and found smallest
		// value.  Subtract value found from each list element.
		for (ptr = l->head; ptr != NULL; ptr = ptr->next)	{
			ptr->value -= min;
			}
		}
/* --- <END SNIP> --- */
}//update()


int main ()
{
    LinkedList ll;
	printf ("ELEC278 Lab 2 Part 2 - LinkedLists\n");
    init(&ll);
	print (&ll);
    
    addFront(&ll,5);
    addFront(&ll,2);
    addEnd(&ll,4);
    addEnd(&ll,3);
    
    print(&ll);
    
    update(&ll);
    print(&ll);
    
    removeValue(&ll,0);
    print(&ll);

    removeValue(&ll,2);
    //removeFront(&ll);
    //removeEnd(&ll);
    print(&ll);

    //removeFront(&ll);
    removeValue(&ll,3);
    print(&ll);

    removeValue(&ll,1);
    print(&ll);
    return 0;
}//main()
