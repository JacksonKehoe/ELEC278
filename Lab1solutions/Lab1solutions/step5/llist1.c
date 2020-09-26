/* LLIST1.C [140911]
 * Code provided for ELEC278 Lab 1 Step 5
 */

#include "llist1.h"

void insertFront(int v, LList1 *l)
{
    if (l != NULL)	{
        /* create new link */
        Link* link = initLink(v);

        /* has at least one element */
        if (!isEmpty(l))
        {
            link->next = l->head;
            l->head = link;
        }
        else
        {
            l->head = link;
        }
    }
}

/** 
  * Extract Element from list with value v and return it
  * return NULL if no link exists with value v
  */
Link* extract(int v, LList1 *list)
{
    Link	*link1=NULL, *link2=NULL, *resLink=NULL;

	/* check if list is NULL */
    if (list != NULL) {
        if (list->head != NULL)	{
			/* something in list. */
			/* Check if first node contains value */
            if (list->head->value == v)	{
				/*** fill in code here ***/
				/* Make resLink point to first node, then remove node
				 * from list */
                resLink = list->head ;
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
				
				/* update resLink accordingly */
				/*** fill in code here ***/
				if (link2 != NULL)	{
					resLink = link2;	/* node containing value */
					/* recall that link1 points to node before link2 node */
                    link1->next = link2->next ;
                    list->size-- ;
            		}
        		}/* endif(list->head-value is/isn't = v) */
    		}/* endif(list->head not NULL) */
		}/* endif(list not NULL) */
    return resLink;
}


int isEmpty (LList1 *l)
{
    if (l != NULL)
        return (l->head == NULL);
    else
        return 0; //0 is true in C
}

Link* initLink (int v)
{
    Link* link = malloc(sizeof(Link));
    link->value = v;
    link->next = NULL;
    return link;
}

LList1* initList ()
{
    LList1 *list = malloc(sizeof(LList1));
    list->size = 0;
    list->head = NULL;
    return list;
}

void printList (LList1 *l)
{
    if (l != NULL)
    {
        if (!isEmpty(l))
        {
            Link *link = l->head;
            while (link != NULL)
            {
                printf("%d-->",link->value);
                link = link->next;
            }
            printf("NULL\n");
        }
    }
}


