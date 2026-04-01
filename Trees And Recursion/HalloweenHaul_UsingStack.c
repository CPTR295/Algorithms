#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 255
#define TEST_CASES 5
typedef struct node
{
    int candy;
    struct node *left, *right;
    
}node;

typedef struct stack
{
    node *values[SIZE];
    int highest_used;
}stack;


node *new_house(int candy)
{
    node *house = malloc(sizeof(node));
    if(house == NULL)
    {
        fprintf(stderr,"Malloc Error");
        exit(1);
    }
    house->candy = candy;
    house->left = NULL;
    house->right = NULL;
    return house;
}

node *new_nonhouse(node *left, node *right)
{
    node *nonhouse = malloc(sizeof(node));
    if(nonhouse == NULL)
    {
        fprintf(stderr,"Malloc Error");
        exit(1);
    }
    nonhouse->left = left;
    nonhouse->right = right;
    return nonhouse;
}

stack *new_stack(void)
{
    stack *s = malloc(sizeof(stack));
    if(s==NULL)
    {
        fprintf(stderr,"Malloc Error");
        exit(1);
    }
    s->highest_used = -1;
    return s;
}

void push_stack(stack *s, node *value)
{
    s->highest_used++;
    s->values[s->highest_used]=value;
}

node *pop_stack(stack *s)
{
    node *ret = s->values[s->highest_used];
    s->highest_used--;
    return ret;
}

int is_empty_stack(stack *s)
{
    return s->highest_used == -1;
}

int tree_candy(node *tree)
{
    int total = 0;
    stack *s = new_stack();
    while(tree!=NULL)
    {
        if(tree->left && tree->right)
        {
            push_stack(s,tree->left);
            tree=tree->right;
        }
        else
        {
            total = total + tree->candy;
            if(is_empty_stack(s))
            {
                tree=NULL;
            }
            else
            {
                tree = pop_stack(s);
            }
        }
    }
    return total;
}

node *read_tree_helper(char *line, int *pos)
{
    node *tree;
    tree = malloc(sizeof(node));
    if(tree == NULL){
        fprintf(stderr,"Malloc Error");
        exit(1);
    }
    if(line[*pos]=='('){
        (*pos)++;
        tree->left = read_tree_helper(line,pos);
        (*pos)++;
        tree->right = read_tree_helper(line,pos);
        (*pos)++;
        return tree;
        
    }
    else{
        tree->left = NULL;
        tree->right = NULL;
        tree->candy = line[*pos]-'0';
        (*pos)++;
        if(line[*pos]!=')' && line[*pos]!=' ' && line[*pos]!='\0'){
            tree->candy = tree->candy*10 + line[*pos]-'0';
            (*pos)++;
        }
        return tree;
    }
    
}

node *read_tree(char *line)
{
    int pos=0;
    return read_tree_helper(line,&pos);
}

int main(void)
{
    int i,candy;
    char line[SIZE+1];
    node *tree;
    for(i=0;i<TEST_CASES;i++)
    {
        gets(line);
        tree = read_tree(line);
        candy = tree_candy(tree);
        printf("%d",candy);
    }
    return 0;
}