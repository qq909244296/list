#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
	list * mylist=NULL;
	int i,err;
	
	mylist = list_create();
	if(mylist == NULL){
		printf("mylist create failture!");
	}

	datatype arr[] = {34, 5, 67, 8};

/*	for(i=0;i<(sizeof(arr)/sizeof(*arr));i++){
		if((err=list_insert_at(mylist,0,&arr[i]))!=0){
			fprintf(stderr,"-1err!");
		}
	}

*/


	for(i = 0;i<(sizeof(arr)/sizeof(*arr));i++){
		if((err = list_insert_order(mylist,&arr[i])!=0)){
			fprintf(stderr,"-1err!");

		
		}
	}
	
	datatype t = 34;
	//list_delete_at(mylist,2,&e);
	list_delete(mylist,&t);
	
	list_display(mylist);
	
	
	exit(0);
}
