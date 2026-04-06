#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SEQ 1000000

typedef struct segtree_node{
    int left,right;
    int max_sum,max_element;

}segtree_node;

typedef struct node_info{
    int max_sum,max_element;

}node_info;

int max(int a,int b)
{
    return (a>b)?a:b;
}

node_info fill_segtree(segtree_node segtree[],int node,int seq[])
{
    node_info left_info,right_info;
    if(segtree[node].left==segtree[node].right)
    {
        segtree[node].max_sum=-1;
        segtree[node].max_element=seq[segtree[node].left];
        return (node_info){segtree[node].max_sum,segtree[node].max_element};
    }
    left_info=fill_segtree(segtree,2*node,seq);
    right_info=fill_segtree(segtree,2*node+1,seq);
    segtree[node].max_element=max(left_info.max_element,right_info.max_element);

    if(left_info.max_sum==-1 && right_info.max_sum==-1){
        segtree[node].max_sum=left_info.max_element+right_info.max_element;
    }
    else if(left_info.max_sum==-1)
    {
        segtree[node].max_sum=max(left_info.max_element+right_info.max_element,right_info.max_sum);
    }
    else if(right_info.max_sum==-1)
    {
        segtree[node].max_sum=max(left_info.max_sum,left_info.max_element+right_info.max_element);
    }
    else
    {
        segtree[node].max_sum=max(left_info.max_element+right_info.max_element,max(left_info.max_sum,right_info.max_sum));
    }

    return (node_info){segtree[node].max_sum,segtree[node].max_element};
}

node_info query_segtree(segtree_node segtree[],int node, int seq[],int left,int right) 
{
    node_info left_info,right_info,ret_info;
    if(segtree[node].left>right || segtree[node].right<left)
    {
        return (node_info){-1,-1};
    }

    if(segtree[node].left>=left && segtree[node].right<=right)
    {
        return (node_info){segtree[node].max_sum,segtree[node].max_element};
    }

    left_info=query_segtree(segtree,2*node,seq,left,right);
    right_info=query_segtree(segtree,2*node+1,seq,left,right);

    if(left_info.max_element==-1)
    {
        return right_info;
    }
    if(right_info.max_element==-1)
    {
        return left_info;
    }

    ret_info.max_element=max(left_info.max_element,right_info.max_element);
    if(left_info.max_sum==-1 && right_info.max_sum==-1){
        ret_info.max_sum=left_info.max_element+right_info.max_element;
        return ret_info;
    
    }
    else if(left_info.max_sum==-1)
    {
        ret_info.max_sum=max(left_info.max_element+right_info.max_element,right_info.max_sum);
        return ret_info;
    }
    else if(right_info.max_sum==-1)
    {
        ret_info.max_sum=max(left_info.max_sum,left_info.max_element+right_info.max_element);
        return ret_info;
    }
    else
    {
        ret_info.max_sum=max(left_info.max_element+right_info.max_element,max(left_info.max_sum,right_info.max_sum));
        return ret_info;
    }
}

node_info update_segtree(segtree_node segtree[],int node,int seq[],int index){
    segtree_node left_node,right_node;
    node_info left_info,right_info;

    if(segtree[node].left==segtree[node].right){
        segtree[node].max_element=seq[index];
        return (node_info){segtree[node].max_sum,segtree[node].max_element};
    }

    left_node = segtree[2*node];
    right_node = segtree[2*node+1];

    if(index<=left_node.right){
        left_info=update_segtree(segtree,2*node,seq,index);
        right_info=(node_info){right_node.max_sum,right_node.max_element};
    }
    else
    {
        left_info=(node_info){left_node.max_sum,left_node.max_element};
        right_info=update_segtree(segtree,2*node+1,seq,index);
    }

    segtree[node].max_sum=max(left_info.max_sum,right_info.max_sum);
    if(left_info.max_sum==-1 && right_info.max_sum==-1){
        segtree[node].max_sum=left_info.max_element+right_info.max_element;
    }
    else if(left_info.max_sum==-1)
    {
        segtree[node].max_sum=max(left_info.max_element+right_info.max_element,right_info.max_sum);
    }
    else if(right_info.max_sum==-1)
    {
        segtree[node].max_sum=max(left_info.max_sum,left_info.max_element+right_info.max_element);
    }
    else
    {
        segtree[node].max_sum=max(left_info.max_element+right_info.max_element,max(left_info.max_sum,right_info.max_sum));
    }
    return (node_info){segtree[node].max_sum,segtree[node].max_element};
}

void init_segtree(segtree_node segtree[], int node,int left, int right)
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

int main(void)
{
    static segtree_node segtree[4*MAX_SEQ];
    static int seq[MAX_SEQ];
    int num_seq,num_ops,i,x,y,op;
    char c;
    scanf("%d",&num_seq);
    for(i=0;i<num_seq;i++)
    {
        scanf("%d",&seq[i]);
    }
    init_segtree(segtree,1,0,num_seq-1);
    fill_segtree(segtree,1,seq);
    scanf("%d",&num_ops);
    for(i=0;i<num_ops;i++){
        scanf(" %c%d%d",&c,&x,&y);
        if(c=='U'){
            seq[x]=y;
            update_segtree(segtree,1,seq,x);
        }
        else{
            printf("%d\n",query_segtree(segtree,1,seq,x,y).max_sum);
        }
    }
    return 0;
    
}