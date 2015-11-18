#ifndef SKIP_H
#define SKIP_H

struct node
{
	int prox;
	char place[30];
	struct node* left;
	struct node* right;
	struct node* up;
	struct node* down;
};
typedef struct node node_t;

struct list
{
	struct node* head;
};
typedef struct list list_t;

void init_list(list_t*);
void disp_list(const list_t*);
void make_list(list_t*,node_t *,int);
void insert_list(list_t*, node_t*);
void link_list(list_t*, list_t*,int);
void promote(list_t*, list_t*, node_t*, int);
int binary(int);
void disp_places(node_t *,node_t *);
void search(list_t *,list_t*, char[], char[]);
void free_list(list_t*);

#endif
