/*
   Linked List Library
   Steve Rubin <ser@tch.org>

*/


#include <stdio.h>
#include "ll.h"

/*********************************************************************/

void *list_head(LL_LIST *list) {
	list->cur = list->head;
	return(list->cur->obj);
} /* list_head() */

/*********************************************************************/

void *list_tail(LL_LIST *list) {
	list->cur = list->tail;
	return(list->cur->obj);
} /* list_tail() */

/*********************************************************************/

void *list_pop(LL_LIST *list) {
	LL_NODE *cur;
	void *obj;
	cur = list->cur;
	obj = cur->obj;
	list_delete(list);
	return(obj);
} /* list_pop() */

/*********************************************************************/

void *list_current(LL_LIST *list) {
	return(list->cur->obj);
} /* list_current() */

int list_delete(LL_LIST *list) {
	LL_NODE *old;
	if (list->cur->next == NULL) list->tail = list->cur->prev;
	else list->cur->next->prev = list->cur->prev;
	if (list->cur->prev == NULL) list->head = list->cur->next;
	else list->cur->prev->next = list->cur->next;
	old = list->cur;
	if (old->next == NULL) {
		list->cur = old->prev;
		free(old);
		return(0);
	}
	else list->cur = old->next;
	free(old);
	return(1);
} /* list_pop() */

/*********************************************************************/

int list_insert(LL_LIST *list, void *obj) {
	LL_NODE	*new;

 	if ( (new=calloc(1,sizeof(LL_NODE))) == NULL) {	
		return(0);
	}

	new->obj = obj;					/* move ptr to obj */

	if (list->cur == NULL) {			
		list->cur = new;
		list->cur->next = NULL;
		list->cur->prev = NULL;
		list->head = NULL;
		list->tail = NULL;
	} /* if(list->cur)	*/
	else {
		new->next = list->cur->next;
		new->prev = list->cur;
		list->cur->next	= new;
	} /* else */
	list->cur = new;
	if (list->cur->prev == NULL) list->head = list->cur;
	if (list->cur->next == NULL) list->tail = list->cur;


	return(1);					/* ok? */
} /* list_instert() */

/*********************************************************************/

void *list_next(LL_LIST *list) {
	if (list->cur->next == NULL) 
		return(0);
	list->cur = list->cur->next;			/* neeeeext victim */
	return(list->cur->obj);
} /* list_next() */

/*********************************************************************/

void *list_prev(LL_LIST *list) {
	if (list->cur->prev == NULL) 
		return(0);
	list->cur = list->cur->next;
	return(list->cur->obj);	
} /* list_prev() */

/*********************************************************************/

