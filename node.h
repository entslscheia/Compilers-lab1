#ifndef _NODE_H_
#define _NODE_H_
typedef struct Node{
        char name[20];
        int lineno;
        int flag;//1 stands for INT, 2 stands for FLOAT, 3 stands for ID, 4 stands for TYPE, 0 stands for others
        union{
        	int type_int;
        	float type_float;
        	char type_ID[20];
                char type_Type[20];
        }val;
        int numOfChildren;
        struct Node* children[10];
}node;

node* construct(char [], int, int);
void add_child(node **, node *);
void print_tree(node *, int);

#endif
