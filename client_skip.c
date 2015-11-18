#include<stdio.h>
#include<stdlib.h>
#include"skip.h"

int main()
{
	int i;
	list_t one;
	list_t two, three, four, five,six,seven,eight;
	char str1[30], str2[30];
	
	int n = 650;
	
	init_list(&one);

	node_t s[n];

	FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;
	fp = fopen("/home/apoorva/algorithms/project/SkipList/input.txt","r");
	
	for(i=0;i<n;i++)
		fscanf(fp,"%d%s",&s[i].prox,s[i].place);
	
	make_list(&one,s,n);

	init_list(&two);
	init_list(&three);
	init_list(&four);
	init_list(&five);
	init_list(&six);
	init_list(&seven);
	init_list(&eight);

	fp1 = fopen("/home/apoorva/algorithms/project/SkipList/one.txt","w");
	
	node_t *temp = one.head;

	while(temp != 0)
	{
		fprintf(fp1,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}

	link_list(&one,&two,n);
	
	fp2 = fopen("/home/apoorva/algorithms/project/SkipList/two.txt","w");
	
	temp = two.head;

	while(temp != 0)
	{
		fprintf(fp2,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}

	link_list(&two,&three,n);
	
	fp3 = fopen("/home/apoorva/algorithms/project/SkipList/three.txt","w");
	
	temp = three.head;

	while(temp != 0)
	{
		fprintf(fp3,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}


	link_list(&three, &four,n);
	
	fp4 = fopen("/home/apoorva/algorithms/project/SkipList/four.txt","w");
	
	temp = four.head;

	while(temp != 0)
	{
		fprintf(fp4,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}

	link_list(&four, &five,n);
	
	fp5 = fopen("/home/apoorva/algorithms/project/SkipList/five.txt","w");
	
	temp = five.head;

	while(temp != 0)
	{
		fprintf(fp5,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}

	
	link_list(&five, &six,n);
	
	fp6 = fopen("/home/apoorva/algorithms/project/SkipList/six.txt","w");
	
	temp = six.head;

	while(temp != 0)
	{
		fprintf(fp6,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}
	
	link_list(&six, &seven,n);
	
	fp7 = fopen("/home/apoorva/algorithms/project/SkipList/seven.txt","w");
	
	temp = seven.head;

	while(temp != 0)
	{
		fprintf(fp7,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}
	
	link_list(&seven, &eight,n);
	
	fp8 = fopen("/home/apoorva/algorithms/project/SkipList/eight.txt","w");
	
	temp = eight.head;

	while(temp != 0)
	{
		fprintf(fp8,"%d\t%s\n",temp -> prox,temp -> place);	
		temp = temp->right;
	}



	printf("\nEnter 2 places:");
	scanf("%s%s", str1, str2);
	
	printf("\n\nThe shortest path between the two places\n\n");
	search(&one,&eight,str1,str2);
	
        free_list(&one);
	free_list(&two);
	free_list(&three);
	free_list(&four);
	free_list(&five);
	free_list(&six);
	free_list(&seven);
	free_list(&eight);

	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	fclose(fp6);
	fclose(fp7);
	fclose(fp8);

	return 0;
}
