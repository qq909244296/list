#include <stdlib.h>
#include <stdio.h>
#include "noheadlist.h"

int main(){

	the_node *mynode = NULL;
	struct stu_inf stu;
	int i = 7;

	for(i = 0; i < 7; i++){
		stu.id = i;
		snprintf(stu.name,MAXSIZE,"STU%d",i);
		stu.math = rand() % 100;
		stu.chinese = rand() % 100;
		
		stu_insert(&mynode,&stu);
	
	}
//	mynode = stu_delete(mynode);

	int t=3;
	struct stu_inf *stu_i;
	stu_i = stu_find(mynode,t);
	stu_display(mynode);

	stu_destory(mynode);
	//printf("%d %s %d %d\n",stu_i->id,stu_i->name,stu_i->math,stu_i->chinese);
	
//	stu_display(mynode);
	exit(0);
}
