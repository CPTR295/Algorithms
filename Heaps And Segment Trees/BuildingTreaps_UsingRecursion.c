#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODES 50000
#define LABEL_LENGTH 16

typedef struct treap_node {
    char * label;
    int priority;
}treap_node;

char * read_label(int size)
{
    char *str;
    int ch;
    int len=0;
    str = malloc(size);
    if(str==NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getchar())!=EOF && (ch!='/')){
        str[len++]=ch;
        if(len==size){
            size*=2;
            char *str = realloc(str,size);
            if(str==NULL)
            {
                fprintf(stderr,"Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    str[len]='\0';
    return str;
}

int compare(const void *a,const void *b)
{
    treap_node *node_a=(treap_node *)a;
    treap_node *node_b=(treap_node *)b;
    return strcmp(node_a->label,node_b->label);
}

int max_priority_index(treap_node treap_nodes[], int left, int right)
{
    int i;
    int max_index = left;
    for(i=left+1;i<=right;i++)
    {
        if(treap_nodes[i].priority>treap_nodes[max_index].priority)
        {
            max_index=i;
        }
    }
    return max_index;
    
}

void solve(treap_node treap_nodes[], int left, int right)
{
    int root_index;
    treap_node root;
    if(left>right)
    {
        return;
    }
    root_index=max_priority_index(treap_nodes,left,right);
    root=treap_nodes[root_index];
    printf("(");
    solve(treap_nodes,left,root_index-1);
    printf("%s/%d",root.label,root.priority);
    solve(treap_nodes,root_index+1,right);
    printf(")");
}

int main(void)
{
    static treap_node treap_nodes[MAX_NODES];
    int num_nodes,i;
    scanf("%d",&num_nodes);
    for(i=0;i<num_nodes;i++)
    {
        treap_nodes[i].label=read_label(LABEL_LENGTH);
        scanf("%d",&treap_nodes[i].priority);
    }
    qsort(treap_nodes,num_nodes,sizeof(treap_node),compare);
    solve(treap_nodes,0,num_nodes-1);
    
}