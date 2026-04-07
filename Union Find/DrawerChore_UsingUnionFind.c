#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DRAWERS 10000

int find(int drawer, int parent[]){
    int set = drawer,temp;
    while(parent[set]!=set)
        set=parent[set];
    while(parent[drawer]!=set){
        temp=parent[drawer];
        parent[drawer]=set;
        drawer=temp;
    }
    return set;
}

void union_sets(int drawer1, int drawer2, int parent[])
{
    int set1, set2;
    set1=find(drawer1,parent);
    set2=find(drawer2,parent);
    parent[set1]=set2;
    if(set1==set2)
        parent[set2]=0;
    printf("LADICA\n");

}

int main(void)
{
    static int parent[MAX_DRAWERS];
    int num_drawers,num_items,i,drawera,drawerb;
    scanf("%d%d",&num_items,&num_drawers);
    for(i=1;i<=num_drawers;i++){
        parent[i]=i;
    }
    for(i=1;i<=num_items;i++){
        scanf("%d%d",&drawera,&drawerb);
        
        if(find(drawera,parent)==drawera)
            union_sets(drawera,drawerb,parent);
        else if(find(drawerb,parent)==drawerb)
            union_sets(drawerb,drawera,parent);
        else if(find(drawera,parent)>0)
            union_sets(drawera,drawerb,parent);
        else if(find(drawerb,parent)>0)
            union_sets(drawerb,drawera,parent);
        else
            printf("SMECE\n");
    }
    return 0;
}