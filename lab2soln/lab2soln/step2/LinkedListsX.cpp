// LinkedLists.cpp
//
// THIS VERSION OF THE CODE IS INTENDED FOR THOSE CURIOUS ABOUT
// DIFFERENCES BETWEEN C AND CPP. THIS CODE IMPLEMENTS THE SAME
// FUNCTIONALITY AS THE C CODE, BUT USES C++ CLASSES.

// Code provided for ELEC278 Lab 2
// This version uses linked list to store data.

#include <stdio.h>
#include <stdlib.h>

// Node class defines the data and the allowed methods for an item of
// type Node. Class definition is minimal - the methods are defined
// completely as inline methods in the class definition, and the
// constructor is defined with initial values.

class Node {
private:
	int			value;			// Data value stored in node
	Node		*next;			// pointer to next Node in list
public:
	Node (int x, Node *nxt): value(x), next(nxt) {}
	// next three methods are "inline" methods - both the interface and
	// the implementation are specified in the class definition.
	int getvalue(void)	{return value;}
	void setvalue (int x)	{ value = x; }
	Node* getnext(void)	{return next;}
	void  setnext (Node *pn)	{next = pn;}
}; //class Node	

// LinkedList is a class that is a linked list of Nodes.  This is not
// the most versatile way to do this - in other linked list code, you
// will see the definition of a linked list template - a mechanism to
// create a linked list of any type.

class LinkedList {
private:
	// LinkedList class has pointer to first Node element, and count of
	// Nodes in list.
	Node	*head;
	int		size;
public:
	LinkedList (): head(0), size(0) {}
	~LinkedList ();
	void init ()	{head = NULL; size = 0; }
	bool isEmpty ()	{return head==NULL;}
	void addFront (int x);
	void addEnd (int x);
	void removeFront();
	void removeEnd();
	void removeValue(int x);
	void print ();
	void update ();
};//class LinkedList


void LinkedList :: addFront(int x)
// Add new Node to front of linked list. Create and initialize new Node
// structure with value and current head-of-list pointer.  Make head-of-list
// point to new node
{
    Node* newNode = new Node (x, head);
	printf ("Adding %d to front of list\n", x);
    head = newNode;
    size++;
}//LinkedList_addFront()


void LinkedList :: addEnd(int x)
// Add new Node to end of linked list
{
    Node* newNode = new Node (x, NULL);
	printf ("Adding %d to end of list\n", x);
	// start by increasing size of linked list
    size++;
	// Now comes the fun part - have to find current last Node, so it
	// can be made to point to the new node
	if (isEmpty ())	{
		// LinkedList currently empty - new node becomes first in list
		head = newNode;
	} else	{
		// Not empty - have to find last Node in current list and make
		// it point to new node.
		Node* ptr = head;
		// Traverse list until node found that doesn't point to a next one
		while(ptr->getnext()!=NULL)	{
			ptr = ptr->getnext();
			}
		// ptr points to a Node with no next Node; make this Node point to
		// new one
		ptr->setnext(newNode);
		}
	// Our work is done.
}//LinkedList :: addEnd()


void LinkedList ::removeFront()
// Remove first Node from list
{
	printf ("Remove item at front of list\n");
	if (!isEmpty ())	{
		// List is not empty, so there is a first Node to delete.
		Node *ptr = head;		// point to first node
		// Note that list will be one shorter
		size--;
		// head of list is now element after first
		head = head->getnext();
		// discard node we no longer need
		delete ptr;
		}
}//removeFront()


void LinkedList :: removeEnd()
// Remove last Node from list
{
	printf ("Remove item at end of list\n");
	// First determine if any work to do
	if (!isEmpty ())	{
		// Special case - if there is only one Node
		if (size==1)	{
			removeFront();
		} else	{
			// More than 1. Note how this code requires that a Node
			// be found that points to a last Node (one with a NULL
			// next pointer, and that doesn't work for the list with
			// only 1 Node.  Fun exercise for the student - think about 
			// how to redesign data and code so that all cases can
			// be handled with one piece of code.
			Node* ptr = head;
			Node* delPtr;

			// As long as the Node we're pointing to isn't the end of
			// the list, move to next Node
			while(ptr->getnext()->getnext())	{
				ptr = ptr->getnext();
				}
			delPtr = ptr->getnext();
			ptr->setnext(NULL);
			delete delPtr;
			size--;
			}
		}
}//removeEnd()


LinkedList :: ~LinkedList ()
// Destructor - repeatedly delete all nodes
{
	while(!isEmpty())	{
		removeFront();
		}
}//destroy()


void LinkedList :: removeValue(int x)
// Remove first Node in list whose value is x
{
	printf ("Find first %d in list and remove it\n", x);
/* Write your code here */
/* --- <BEGIN SNIP> --- */
	if (isEmpty())	return;
	// If first Node has value, remove first node
	if (head->getvalue() == x)
		removeFront ();
	else	{
		// Wasn't in first position - traverse until we find one.  We have
		// to keep track of both node that holds value and one prior to it,
		// so we can easily delete node containing value.
		Node *prev = head;			// points to first Node
		Node *curr = prev->getnext();		// points to second
		// As long as we have a current node, check it for value
		while (curr != NULL)	{
			if (curr->getvalue() == x)	{
				// Current node has value we're looking for.
				// Previous node needs to point to one after current node
				// (to remove current node from list) then current node
				// needs to be freed.
				prev->setnext(curr->getnext());
				size--;
				delete curr;
				// basically, that's it
				break;
				}
			// Not found yet - advance both pointers
			prev = curr;
			curr = curr->getnext();
			}
		}
/* --- <END SNIP> --- */
}//removeValue()


void LinkedList :: print()
{
    Node* ptr = head;
	printf("(");
    if(!ptr)	{
        printf("<EMPTY>");
    } else	{
    	while(ptr->getnext() != NULL){
        	printf("%d -> ",ptr->getvalue());
        	ptr = ptr->getnext();
			}
    	printf("%d",ptr->getvalue());
		}
	printf(") [%d]\n", size);
}//print()


void LinkedList :: update()
// Find smallest value in linked list and subtract that value from each value
{
	printf ("Subtract smallest value from all values in list\n");
/* Write your code here */
/* --- <BEGIN SNIP> --- */
	if (!isEmpty())	{
		Node	*ptr = head;
		int		min = ptr->getvalue();	// it is a starting point
		// Alternately,
		// int	min = MAXINT;			// smallest value must be smaller!
		// Traverse list, looking for smaller values than what we have so far
		while (ptr != NULL)	{
			if (ptr->getvalue() < min)
				// found one even smaller
				min = ptr->getvalue();
			ptr = ptr->getnext();
			}
		// At this point, we have checked all list elements and found smallest
		// value.  Subtract value found from each list element.
		for (ptr = head; ptr != NULL; ptr = ptr->getnext())	{
			int val = ptr->getvalue() - min;
			ptr->setvalue(val);
			// Alternately:
			// ptr->setvalue(ptr->getvalue()-min);
			}
		}
/* --- <END SNIP> --- */
}//update()


int main ()
{
    LinkedList ll;
	printf ("ELEC278 Lab 2 Part 2 - LinkedLists\n");
    ll.init();
	ll.print ();
    
    ll.addFront(5);
    ll.addFront(2);
    ll.addEnd(4);
    ll.addEnd(3);
    
    ll.print();
    
    ll.update();
    ll.print();
    
    ll.removeValue(0);
    ll.print();

    ll.removeValue(2);
    //ll.removeFront();
    //ll.removeEnd();
    ll.print();

    //ll.removeFront();
    ll.removeValue(3);
    ll.print();

    ll.removeValue(1);
    ll.print();
    return 0;
}//main()
