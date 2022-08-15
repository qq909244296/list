#ifndef NOHEADLIST_H__
#define NOHEADLIST_H__
#define MAXSIZE 32
struct stu_inf{
	int id;
	char name[MAXSIZE];
	int math;
	int chinese;
};

typedef struct st_node{

	struct stu_inf stu;
	struct st_node *node;
}the_node;


int stu_insert(the_node **,struct stu_inf *);
int stu_display(the_node *);
//int stu_delete(the_node **);

the_node * stu_delete(the_node *);
struct stu_inf* stu_find(the_node *,int);

void stu_destory(the_node *);



#endif
