#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct st_the{
	int cef;
	int exp;
};
typedef struct node_st{
	struct st_the stu;
	struct node_st *next;

}node_p;

node_p *node_create(int (*arr)[2],int g){
	node_p *menode,*cur,*mynode;
	mynode = malloc(sizeof(*mynode));
	
	cur = mynode;
	int i = 0;
	for(i=0;i<g;i++){
	
		menode = malloc(sizeof(*menode));
		menode->stu.cef = *(*(arr+i)+0);
		menode->stu.exp = *(*(arr+i)+1);
		menode->next = NULL;
		cur->next = menode;
		cur = menode;
	}
	return mynode;
	



}

void node_show(node_p *mynode){
	node_p *menode = mynode;
	for(menode = menode->next;menode != NULL;menode = menode->next){
		printf("%d  %d\n",menode->stu.cef,menode->stu.exp);
		
	}

}

void node_union(node_p *mynode1, node_p *mynode2){
	node_p *menode1 = mynode1;
	node_p *menode2 = mynode2;
	node_p *cur=mynode1;
	
	
	while(menode1->next){
		sleep(3);
		printf("menode1 %d,%d\n",menode1->next->stu.cef,menode1->next->stu.exp);
		while(menode2->next){
				printf("menode2%d,%d\n",menode2->next->stu.cef,menode2->next->stu.exp);
			if((menode1->next)->stu.exp == (menode2->next)->stu.exp){
				(menode1->next)->stu.cef = menode1->next->stu.cef +	menode2->next->stu.cef;
				if(menode1->next->stu.cef >0){
				//	menode1 = menode1->next;
					cur->next =(menode1->next);
					cur  = menode1->next;
				}
				
				menode1 = menode1->next;
				
				menode2 = menode2->next;
				break;
				
			}
			if(((menode1->next)->stu.exp) >(( menode2->next)->stu.exp)){
									
				cur->next= menode2->next;
				cur = menode2->next;
				menode2 = menode2->next;
			}	
			if(((menode1->next)->stu.exp) < ((menode2->next)->stu.exp)){
				cur->next = menode1->next;
				cur = menode1->next;
				menode1 = menode1->next;
				break;
				
			}
		}
		
				
		if(menode2->next == NULL){
			cur->next = menode1->next;
			cur  = menode1->next;
		}
	}
	

}


int main(){
	int arr1[][2] = {{2,0},{5,2},{6,4},{8,7},{8,10}};
	int arr2[][2] = {{-3,0},{-5,2},{4,5},{7,7}};
	
	int i;
	node_p *p1,*p2;
//	int *p = arr1;
//	int *q = arr2;		
	int (*p)[2];
	int (*q)[2];
	p = arr1;
	q = arr2;
/*
	for(i=0;i<5;i++){
	
		printf("%d",p[i][0]);
		printf("%d",p[i][1]);	
		printf("\n");
	}
	printf("\n");
	q = arr2;

	for(i=0;i<4;i++){
	
		printf("%d",q[i][0]);
		printf("%d",q[i][1]);	
		printf("\n");
	}*/
	p1 = node_create(p,5);
	p2 = node_create(q,4);
#if 0

	for(i=0;i<5;i++){
	
		p1 = p1->next;

		if(p1 != NULL){
			printf("%d %d \n",p1->stu.cef,p1->stu.exp);
		}
	}
	
#endif	
	node_show(p1);
	printf("\n");
	node_show(p2);
	printf("\n");
	node_union(p1,p2);
	node_show(p1);
	exit(0);


}




