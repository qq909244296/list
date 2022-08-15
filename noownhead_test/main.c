#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct list{
	int data;
	struct list  *next;

}simple_list;

simple_list* list_create(){
	simple_list *mylist,*cur,*me;
	
	int i = 1;
	int n = 8;
	me = malloc(sizeof(*me));
	me->data = i;
	me->next = me;
	cur = me;
	
	for(i = 2;i <= n; i++){
		mylist = malloc(sizeof(*mylist));
		mylist->data = i;
		mylist->next = me;
		cur->next = mylist;
		cur = mylist;
	
	}
	return me;
}
void list_show(simple_list *list){
	simple_list *cur = list;
	
	for(cur; list != cur->next; cur = cur->next){
		printf("%d",cur->data);

	}
	printf("%d",cur->data);
	printf("\n");

}

void list_kill(simple_list **list, int n){
	simple_list *cur,*me;

	me = *list;
	int i =0;
	while(me->next != me){
		
		while(i < n-2){
			
			me = me->next;
			i++;
			cur = me;
			if(me == me->next){
				printf("%d\n",me->data);
				break;
			}
		}

		if(me == me->next){
			printf("%d\n",me->data);
			break;

		}
		me = me->next;
		cur->next = me->next;
		printf("%d\n",me->data);
		free(me);
		me = cur->next;
		i = 0;
		
		
	
	}
	printf("%pwww\n",me);
	printf("%phhhh\n",list);
	*list = cur;		
	printf("the end!\n");
}


int main(){
	simple_list *list;
	simple_list *list2;
	list = list_create();
	list_show(list);
	list_kill(&list,3);
	if(list == NULL){
		printf("NULL\n");
	}
	printf("%puuu\n",list);
	printf("%d\n",list->data);
	list_show(list);
	exit(0);
}
