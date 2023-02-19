#include <stdio.h>
#include "ll.h"

int main()  {

	LL_LIST	mylist = {0};

	char	temp[50][50];
	int	i;

	for (i=0; i <= 25; i++) {
		sprintf(temp[i],"This is #%c",i+65);
		printf("inserting: %s\n",temp[i]);	
		list_insert(&mylist, temp[i]);
	}

	printf("list_head = %s\n", list_head(&mylist));	
	for (i=0; i <=25; i++) {
	printf("%d: list_next = %s\n",i,list_next(&mylist));
	}

	printf("setting to head and deleting first 5\n");
	list_head(&mylist);
	for (i=0; i <= 4; i++) {
	printf("deleting: %s\n",(char *)list_pop(&mylist));
	}

	printf("list_head = %s\n", list_head(&mylist));
        for (i=0; i <=25; i++) {
        printf("%d: list_next = %s\n",i,list_next(&mylist));
        }
	
	printf("going to tail and putting letters back\n");
	list_tail(&mylist);
	for (i=0; i <= 4; i++)  {
		printf("reinserting: %s\n",temp[i]);
		list_insert(&mylist,temp[i]);
	}		

	printf("starting from the top\n");
	printf("list_head = %s\n", list_head(&mylist));
        for (i=0; i <=25; i++) {
        	printf("%d: list_next = %s\n",i,list_next(&mylist));
        }
	
} /* main() */

