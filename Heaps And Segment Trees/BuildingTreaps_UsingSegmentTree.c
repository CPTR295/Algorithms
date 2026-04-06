#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODES 50000
#define LABEL_LENGTH 16

typedef struct segtree_node {
    int left, right;
    int max_index;
} segtree_node;

typedef struct treap_node {
    char * label;
    int priority;
}treap_node;

void init_seqtree(segtree_node segtree[], int node,int left, int right)
{
    int mid;
    segtree[node].left=left;
    segtree[node].right=right;
    if(left==right)
        return;
    mid=(left+right)/2;
    init_seqtree(segtree,2*node,left,mid);
    init_seqtree(segtree,2*node+1,mid+1,right); 
}

int fill_segtree(segtree_node segtree[], int node, treap_node treap_nodes[])
{
    int left_max,right_max;
    if(segtree[node].left==segtree[node].right){
        segtree[node].max_index=segtree[node].left;
        return segtree[node].max_index;
    }
    left_max=fill_segtree(segtree,2*node,treap_nodes);
    right_max=fill_segtree(segtree,2*node+1,treap_nodes);

    if(treap_nodes[left_max].priority>treap_nodes[right_max].priority)
        segtree[node].max_index=left_max;
    else
        segtree[node].max_index=right_max;
    return segtree[node].max_index;
}

int query_segtree(segtree_node segtree[] ,int node, treap_node treap_nodes[], int left, int right )
{
    int left_max,right_max;
    if(right<segtree[node].left || left>segtree[node].right)
        return -1;
    
    if(left<=segtree[node].left && right>=segtree[node].right)
        return segtree[node].max_index;

    left_max=query_segtree(segtree,2*node,treap_nodes,left,right);
    right_max=query_segtree(segtree,2*node+1,treap_nodes,left,right);
    if(left_max==-1)
        return right_max;
    if(right_max==-1)
        return left_max;
    if(treap_nodes[left_max].priority>treap_nodes[right_max].priority)
        return left_max;
    return right_max;
    
    
}

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

void solve(treap_node treap_nodes[], int left , int right,segtree_node segtree[]){
    int root_index;
    treap_node root;
    if(left>right)
    {
        return;
    }
    root_index=query_segtree(segtree,1,treap_nodes,left,right);
    root=treap_nodes[root_index];
    printf("(");
    solve(treap_nodes,left,root_index-1,segtree);
    printf("%s/%d",root.label,root.priority);
    solve(treap_nodes,root_index+1,right,segtree);
    printf(")");    
}

int main(void)
{
    static treap_node treap_nodes[MAX_NODES];   
    static segtree_node segtree[4*MAX_NODES];
    int num_nodes,i;
    scanf("%d",&num_nodes);
    for(i=0;i<num_nodes;i++)
    {
        treap_nodes[i].label=read_label(LABEL_LENGTH);
        scanf("%d",&treap_nodes[i].priority);
    }
    qsort(treap_nodes,num_nodes,sizeof(treap_node),compare);
    init_seqtree(segtree,1,0,num_nodes-1);
    fill_segtree(segtree,1,treap_nodes);
    solve(treap_nodes, 0,num_nodes-1,segtree);
    return 0;
}