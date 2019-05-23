#define LL_VERSION 1.0

/*************************************************************************/

struct ll_node {				/* A node in a list */
	struct ll_node *next,*prev;
	void *obj;
};

struct ll_list {				/* A lista 	*/
	struct ll_node *head,*tail,*cur;
};

typedef	struct ll_node LL_NODE;
typedef struct ll_list LL_LIST;

/************************************************************************/

/* list_insert() - Insert a node after current, set current to new node */
int	list_insert(LL_LIST *list, void *obj);
/* list_next()   - Set current to next item in list, return obj */
void	*list_next(LL_LIST *list);
/* list_prev()	 - Set current to previous item in list, return obj */
void	*list_prev(LL_LIST *list);
/* list_head()	 - Set current to head of list, return obj */
void	*list_head(LL_LIST *list);
/* list_tail()	 - Set current to tail of list, return obj */
void 	*list_tail(LL_LIST *list);
/* list_pop() - Delete current from list, leaves current at old cur->next */
/*		returns delete'd nodes data 				  */
void	*list_pop(LL_LIST *list);
/* list_delete() - Delete current form list */
int	list_delete(LL_LIST *list);
/* list_current() - Return current obj from list */
void *list_current(LL_LIST *list);
