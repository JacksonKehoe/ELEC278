// MYSTRING.C
// Code provided for ELEC278 Lab 1 Step 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myString.h"


char *copyString(char *s)
// Make a copy of provided string, using malloc() and return pointer
// to copy of string.
{
	/*	your code goes here	*/
	int		len;		/* length of parameter string */
	int		i;			/* useful integer */
	char	*pnew;		/* pointer to new string */
	char	*ptemp;		/* temporary pointer */

	/* Step 1. Figure out how long parameter string is. */
	ptemp = s;			/* make copy of parameter */
	len = 0;			/* initialize length */
	/* check each character, stopping when nul terminator encountered */
	while (*ptemp != '\0')	{
		len++;
		ptemp++;
		}
	/* counted all characters in string, up to but NOT including nul */
	/* get memory big enough for characters and nul */
	pnew = (char *) malloc (len+1);

	/* Most students will not check if memory was actually obtained */
	if (pnew != NULL)	{
		/* have to copy all characters from original string to new one */
		ptemp = pnew;
		while (*s != '\0')	{
			*ptemp++ = *s++;	/* copy one character */
			}
		/* have to add nul to end of new string */
		*ptemp = '\0';
		}

	/* and we're done. Note that return value may be NULL if this
	 * code didn't obtain any memory. */
	return pnew;
}

void printString(char *s)
// Print string to console, replacing all space characters with newlines.
{
	/*	your code goes here */
	char	*ptemp;

	ptemp = s;
	while (*ptemp != '\0')	{
		if (*ptemp == ' ')	putchar ('\n');
		else				putchar (*ptemp);
		/* Experienced C programmers will write:
		 * 	putchar (*ptemp==' ' ? '\n' : *ptemp);
		 */
		ptemp++;
		}
	/* Finish by making sure we're on a new line */
	putchar ('\n');
}
