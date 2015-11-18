#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"skip.h"

void init_list(list_t* ptr_list)
{
	ptr_list->head = 0;
}

#if 0
void disp_list(const list_t* ptr_list)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		printf("%d\t%s\n", temp->prox,temp->place);
		temp = temp->right;
	}

	printf("\n\n");
}
#endif

void make_list(list_t* ptr_list,node_t *s,int n)
{
	node_t* temp;
	int i;
	
	for(i = 0; i<n; ++i)
	{
		temp = (node_t*)malloc(sizeof(node_t));
		
		temp -> prox = s[i].prox;
		strcpy(temp -> place,s[i].place);
	
		temp->left = 0;
		temp->right = 0;
		temp->up = 0;
		temp->down = 0;

		insert_list(ptr_list, temp);
	}

}

void insert_list(list_t* ptr_list, node_t* temp)
{
	if(ptr_list->head == 0)		//first position
	{
		ptr_list->head = temp;
		temp->right = 0;
		temp->left = 0;
	}

	else
	{
		node_t* prev = 0;
		node_t* pres = ptr_list->head;
		
		while((pres!=0) && (pres->prox <= temp->prox))
		{
			prev = pres;
			pres = pres->right;
		}

		if(prev == 0)		//add in the beginning
		{	
			temp->right = ptr_list->head;	
			ptr_list -> head -> left = temp;	
			ptr_list->head = temp;
			
		}

		else if(pres == 0)   // add at the end
		{
			prev -> right = temp;
			temp -> left = prev;		
		}
		
		else          // add in the middle
		{
			prev -> right = temp;
			temp -> left = prev;
			temp -> right =pres;
			pres -> left = temp;		
		}
	}
	
	
}


void link_list(list_t* ptr_list1, list_t* ptr_list2,int n)
{
	if(ptr_list1->head)
	{
		node_t* pres = ptr_list1->head;
		int i = 1;	//i <- position of the node
		int p[n];	// p[i] holds the value 0 or 1
		
		while(pres)
		{
			if(i%2)			// the node is at an odd position
			{
				if(pres->right)	
				{
					p[i] = binary(i);// a function that returns either 0 or 1
			
					if(i == 1 && p[i] == 0)
					{
						p[i] = 1;	
						promote(ptr_list1, ptr_list2, pres, i);				
					}
					
					else if(p[i])
					{	
						promote(ptr_list1, ptr_list2, pres, i);
					}
				}
				
				else
				{
					p[i] = 0;	//do not promote
				}
			}

			else if((i%2 == 0) && (p[i-1] == 0)) // the node is at an even position AND the previous node was not promoted
			{
				p[i] = 1;
				promote(ptr_list1, ptr_list2, pres, i);
			}
			++i;
			pres = pres->right;
			
		}
	}
}


void promote(list_t* ptr_list1, list_t* ptr_list2, node_t* pres, int i)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));

	strcpy(temp->place, pres->place);
	temp->prox = pres->prox;

	temp->down = pres;
	pres->up = temp;
	temp->right = 0;

	if(i == 1)	//if it is the first node
	{
		ptr_list2->head = temp;
	}

	else
	{

		node_t* cur = ptr_list2->head;
		while(cur->right)
		{

			cur = cur->right;
		}
		cur->right = temp;
		temp->left = cur;
	}
}

int binary(int z)
{
	srand(getpid());
	
	int i = (rand()%2);	//gives a value = 0 or 1
	return i;
}

void search(list_t *ptr1_list1,list_t *ptr_list2,char str1[],char str2[])
{
	node_t *pres = ptr1_list1 -> head;
	
	int prox1,prox2;
	
	while(pres && (strcmp (pres -> place , str1)) != 0)
	{
		pres = pres -> right; 
	}
	
	if(pres == 0)
	{
		printf("\n Invalid input \n\n");
		exit(0);	
	}
	
	else
	{
		prox1 = pres -> prox;
	}
	

	while(pres && (strcmp (pres -> place , str2)) != 0)
	{
		pres = pres -> right; 
	}
	
	if(pres == 0)
	{
		printf("\n Invalid input\n\n");
		exit(0);	
	}
	
	else
	{
		prox2 = pres -> prox;
	}
			
	pres = ptr_list2 -> head;
	node_t *prev = 0;
	node_t *next = 0;
	
	while(pres && ((pres -> prox) < prox1))
	{
		prev = pres;	
		pres = pres -> right;
		
		if((pres == 0))
		{
			pres = prev -> down;
		}
		
		else if(pres && ((pres -> prox) == prox1))
		{
			next = pres;	
			prev = pres;
		}
		
		else if(pres && ((prev -> prox) < prox1) && ((pres -> prox) > prox1))
		{
			pres = prev -> down;
			prev = pres;
		}
	}
	if(pres && ((pres -> prox) == prox1))
	{
		next = pres;
		prev = pres;		
	}
	
	while((next && ((next -> prox) <= prox2)) || (next && ((prev->prox)<prox2) && ((next->prox)>prox2)))
	{
		if(next && ((next -> prox) == prox2))
		{
			disp_places(pres,next);	
			exit(0);	
		}
		
		if(next && ((prev -> prox < prox2)) && ((next -> prox) > prox2))
		{
			pres = pres -> down;
			next = prev -> down;
			prev = next;	
		}
		
		if(next && (next -> prox) < prox2) 
		{
			prev = next;	
			next = next -> right;		
		}
		
		if(next == 0)
		{
			pres = pres -> down;
			next = prev -> down;	
			prev = next;	
		}
	}	
}

void disp_places(node_t *pres,node_t *next)
{
	while(pres != next)
	{
		printf("%s\n",pres -> place);
		pres = pres -> right;			
	}
			
	printf("%s\n",next -> place);
}

void free_list(list_t* ptr_list)
{
	node_t* pres = ptr_list->head;
	node_t* prev = 0;
	
	while(pres)
	{
		prev = pres;
		pres = pres -> right;
		free(prev);	
	}
}
