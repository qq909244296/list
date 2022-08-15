#include <stdlib.h>
#include <stdio.h>
#include "list.h"




list *list_create(){
	list* mylist;

	mylist = malloc(sizeof(*mylist));




	if(mylist == NULL){
	
		printf("create mylist failure!");
		exit(1);
	}

	mylist->next = NULL;
	return mylist;
}
int list_insert_at(list* me ,int i, datatype* data){
	list *node=me,*mynode;
	int j =0;
	if(i<0){
		return -1;
	}



	for(j=0;j>i;j++){
		node = me->next;
	
	}

	if(node == NULL){
	
	
		printf("[%d]",__LINE__);
		return -2;
	
	}
	
	mynode = malloc(sizeof(*mynode));
	mynode->data = *data;
	mynode->next = node->next;
	node->next = mynode;
	return 0;
	


}
int list_insert_order(list*me,datatype* data){
	list *q = me,*p;

	while(q->next&&*data>((q->next)->data)){
		q = q->next;
	}
	if(q == NULL){
		return -1;
	}
	p = malloc(sizeof(*p));
	if(p == NULL){
		return -1;
	}
	p->data = *data;
	p->next = q->next;

	q->next = p;
	return 0;

}
int list_delete_at(list*me,int i,datatype* data){
	list *q = me,*p;
	int j = 0;
/*	for(j = 0; j<i;j++){
		q  = q->next;
	}
*/
	while(j<i&&p){
		q = q->next;
		j++;
	}
	p = malloc(sizeof(*p));
	p = q->next;
	*data = p->data;
	q->next = p->next;
	free(p);
	p = NULL;


	return 0;
}
int list_delete(list*me,datatype *data){
	list *p=me,*q;
	while(p&&p->next->data != *data){
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
}
void list_destory(list*me){

}
void list_display(list *me){
	list *mylist=me->next;
	int i;
	while(mylist!=NULL){
		printf("%d------\n",mylist->data);
		mylist = mylist->next;
	
	}
	printf("\n");


	
/*	for(i=0;i<sizeof(me)/sizeof(*me);i++){
		mylist->next = me->next;
		printf("%d",mylist->data);
		me->next = me->next;
	printf("\n");
	return ;
	}
*/


}
