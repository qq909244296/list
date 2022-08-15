#ifndef LIST_H__
#define LIST_H__

typedef int datatype;

typedef struct thelist{
	datatype data;
	struct thelist* next;


}list;



list *list_create();
int list_insert_at(list* ,int i, datatype* data);
int list_insert_order(list*,datatype* data);
int list_delete_at(list*,int i,datatype *);
int list_delete(list*,datatype*);
void list_destory(list*);

void list_display(list*);


#endif
