// ArrayLists.c
// This code is supplied for use with ELEC278.  It requires that the student
// add some missing pieces.

#include <stdio.h>
#include <stdlib.h>

// An ArrayList implements a "variable length" array.  In reality, there
// is a fixed quantity of memory - M integers (with indices 0..M-1) used
// to hold a quantity of data up to M items.  

typedef struct ArrayList {
	// Structure describes collection of data to describe and contain
	// a set of numbers.  The set is described by end and size, and
	// the actual data is in an array pointed to by a.
    int		end;		// records index of last location used
	int		size;		// size of the allocated array
    int		*a;			// pointer to allocated array memory
} ArrayList;

#define EMPTY	(-1)	// invalid array index used as end when empty

void init (ArrayList *l,int size)
// Initialize an ArrayList to hold an array of specified size.
{
	l->a = malloc(sizeof(int)*size);
	l->size=size;
	l->end = EMPTY;
}//init()


void addFront(ArrayList* l,int x)
// Add value in parameter x to front of list
{

/* Write your code here */
/* --- <BEGIN SNIP> --- */
	int		i;				// used to traverse array
	printf ("Adding %d to Front of list\n", x);
	if (l->end == EMPTY)	{
		// If empty, add first value
		l->a[++l->end] = x;
		return;
		}
	if (l->size <= (l->end+1))	{
		// Overflow - no room to store new value
		printf ("ERROR: Array is full (size %d  end %d)\n", l->size, l->end);
		return;
		}
	// In order to add new value at front, need to shuffle all existing
	// values one position higher in array.
	l->end++;			// new end index
	// work down from the (new) end
	for (i=l->end; i > 0; i--)	{
		// move each existing value to index one higher.
		//printf ("Shuffle from position %d to %d\n", i-1, i);
		l->a[i] = l->a[i-1];
		}
	// Finally, store new value at front of list
	l->a[0] = x;
/* --- <END SNIP> --- */
}/addfront()


void addEnd(ArrayList* l,int x)
// Add value in parameter x to rear of list
{
	// end holds index of current last value in list.
	// Add 1 to list and store value in new end location.
	// Note this works even if list initially empty. Note also
	// that we check if array already full.  (Remember, size is
	// 1 greater than last valid index, so size needs to be greater
	// than what end index will become
	printf ("Adding %d to End of list\n", x);
	if (l->size > (l->end+1))	{
    	l->end++;
    	l->a[l->end] = x;
		}
#if 0
	// Alternate way to write code.
	// Some people prefer a different way
	l->end++;				// compute new end index
	if (l->end >= l->size)	{
		// array already full
		l->end--;			// restore end index
	} else	{
		l->a[l->end] = x;	// store value at new end location
		}
#endif	
 
}//addEnd()


void removeEnd(ArrayList* l)
// Remove last value from list. In a more elaborate implementation,
// end value may be provided to the calling code. At the very least,
// code should indicate whether it actually did what was asked.
{
	printf ("Remove last value from list\n");
	if(l->end != EMPTY)	{
		// list not empty, so it is possible to remove last value
		l->a[l->end] = 0;	// not really necessary
		l->end--;			// may empty list
		}
}//removeEnd()


void removeFront(ArrayList* l)
// Remove front value from list. All remaining values need to be shuffled down.
{
/* Write your code here */
/* --- <BEGIN SNIP> --- */
	printf ("Remove first element from list\n");
	// Only works for non-empty list
	if (l->end != EMPTY)	{
		int		i;
		for (i=0; i < l->end; i++)	{
			l->a[i] = l->a[i+1];
			}
		// Not really necessary - especially if 0 is a valid value
		// Once we adjust end index, we will effectively discard what
		// was originally at that place.
		l->a [l->end] = 0;
		l->end--;
		}

#if 0
	// Alternate solution using pointers
	int		i = 0; *p = l->a; *q = p +1;
	// p points to front place, q points to second place
	while (i++ < l->end)	{
		// Get value that q points to and move q to next array element,
		// put value where p points to and move p to next array element.
		*p++ = *q++;
		}
	l->end--;
#endif
/* --- <END SNIP> --- */
}//removeFront()


void print(ArrayList *l)
// Print contents of list
{
	// Print brackets around whole list
	printf ("(");
	// Check first to see if anything to print
	if (l->end == EMPTY)	{
        printf("<EMPTY>");
	} else	{
		int		i;
		for( i=0; i<=l->end-1; i++)	{
			printf("%d - ",l->a[i]);
			}
		// No trailing dash after last one
		printf("%d",l->a[l->end]);
		}
	//finish with closing bracket and NL
	printf (")\n");
}//print()


int main ()
{
    ArrayList ll;

	printf ("ELEC278 - Lab2 Part1 arrayslist program\n");
    init(&ll,10);
	print (&ll);
    
    addFront(&ll,5);
    addFront(&ll,2);
    addEnd(&ll,4);
    addEnd(&ll,3);
    
    print(&ll);
    
    removeFront(&ll);
    removeEnd(&ll);
    print(&ll);

    removeFront(&ll);
    print(&ll);

    removeFront(&ll);
    print(&ll);

    removeFront(&ll);
    
    addFront(&ll,10);
    
    print(&ll);
    
    return 0;
}//main()
