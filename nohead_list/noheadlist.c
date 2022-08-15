#include <stdio.h>
#include <stdlib.h>
#include "noheadlist.h"


int stu_insert(the_node **node,struct stu_inf *stu){
	the_node *mynode;
	mynode = malloc(sizeof(*mynode));
	mynode->stu = *stu;
	
	mynode->node = *node;
	*node = mynode;
	return 0;
}
int stu_display(the_node *node){
	the_node *mynode=node;
	for(mynode;mynode!=NULL;mynode= mynode->node){	
		printf("%d %s %d %d\n",mynode->stu.id,mynode->stu.name,
		mynode->stu.math,mynode->stu.chinese);
	}
	printf("\n");
}
the_node* stu_delete(the_node *menode){
	the_node *mynode;
	mynode = menode;
	menode = mynode->node;

	free(mynode);
	return menode;
}


/*int stu_delete(the_node **menode){
	the_node *mynode;
	mynode = *menode;
	*menode = mynode->node;

	return 0;
}
*/
struct stu_inf *stu_find(the_node *stu,int num){
	the_node *mynode;
	for(mynode=stu;mynode!=NULL;mynode = mynode->node){
		if(mynode->stu.id == num){
			return &(mynode->stu);
		}
	}



}

void stu_destory(the_node *menode){
	the_node *mynode;

	for(mynode = menode;mynode!=NULL;mynode = menode){
		menode = mynode->node;
		free(mynode);
		

	}


}
