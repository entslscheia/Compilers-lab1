#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
node* construct(char n[], int lno, int f){
	//printf("construct%s\n", n);
	node *p = (node*)malloc(sizeof(node));
	memset(p->name, 0, 20);
	memcpy(p->name, n, 20);
	p->lineno = lno;
	p->flag = f;
	p->numOfChildren = 0;
	int i;
	for(i = 0; i < 10; i ++)
		p->children[i] = NULL;
	//printf("CON\n");
	return p;
}

void add_child(node **parent, node *child){
	if(child != NULL){
		(*parent)->children[(*parent)->numOfChildren] = child;
		(*parent)->numOfChildren ++;
	}
}

void print_tree(node *p, int n){
	if(p->numOfChildren != 0){
		//printf("%d\n", p->numOfChildren);		
		int i;
		for(i = 0; i < n; i ++)
			printf(" ");
		if(p->flag == 0){
			if(p->lineno != 0) printf("%s(%d)\n", p->name, p->lineno);
			else printf("%s\n", p->name);
		}
		else if(p->flag == 1){//INT
			printf("INT: ");
			printf("%d\n", p->val.type_int);
		}	
		else if(p->flag == 2){//FLOAT
			printf("FLOAT: ");
			printf("%f\n", p->val.type_float);
		}
		else if(p->flag == 3){//ID
			printf("ID: ");
			printf("%s\n", p->val.type_ID);
		}
		else if(p->flag == 4){//TYPE
			printf("TYPE: ");
			printf("%s\n", p->val.type_Type);
		}
		
		int j;
		for(j = 0; j < p->numOfChildren; j ++)
			print_tree(p->children[j], n + 1);				
       	}
	else{
		int i;
		for(i = 0; i < n; i ++)
			printf(" ");
		if(p->flag == 0){
			if(p->lineno != 0) printf("%s(%d)\n", p->name, p->lineno);
			else printf("%s\n", p->name);
		}
		else if(p->flag == 1){//INT
			printf("INT: ");
			printf("%d\n", p->val.type_int);
		}	
		else if(p->flag == 2){//FLOAT
			printf("FLOAT: ");
			printf("%f\n", p->val.type_float);
		}
		else if(p->flag == 3){//ID
			printf("ID: ");
			printf("%s\n", p->val.type_ID);
		}
		else if(p->flag == 4){//TYPE
			printf("TYPE: ");
			printf("%s\n", p->val.type_Type);
		}
	}
}
