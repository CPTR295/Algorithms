#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100000

typedef struct snowflake_node
{
    int snowflake[6];
    struct snowflake_node *next;
}snowflake_node;

int code(int snowflake[6])
{
    return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] + snowflake[4] + snowflake[5]) % SIZE;
}

int identical_right(int snowflake1[6],int snowflake2[6],int start)
{
    int i;
    for(i=0;i<6;i++)
    {
        if(snowflake1[i]!=snowflake2[(start+i)%6])
        {
            return 0;
        }
    }
    return 1;
}

int identical_left(int snow1[],int snow2[],int start)
{
    int i,snow2_index;
    for(i=0;i<6;i++)
    {
        snow2_index = start - i;
        if(snow2_index<0)
        {
            snow2_index += 6;
        }
        if(snow1[i]!=snow2[snow2_index])
        {
            return 0;
        }
    }
    return 1;
}

int are_identical(int snowflake1[6],int snowflake2[6])
{
    int start;
    for(start=0;start<6;start++)
    {
        if(identical_right(snowflake1,snowflake2,start))
        {
            return 1;
        }
        if(identical_left(snowflake1,snowflake2,start))
        {
            return 1;
        }
    }
    return 0;
}

void identify_identical(snowflake_node *snowflakes[])
{
    int i;
    snowflake_node *node1,*node2;
    for(i=0;i<SIZE;i++)
    {
        node1 = snowflakes[i];
        while(node1!=NULL)
        {
            node2 = node1->next;
            while (node2!=NULL)
            {
                if(are_identical(node1->snowflake,node2->snowflake))
                {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                node2 = node2->next;
        
            }
            node1 = node1->next;
            
        }

    }
    printf("No two snowflakes are alike.\n");
}

int main(void)
{
    static snowflake_node *snowflakes[SIZE]={NULL};
    snowflake_node *snow;
    int n,i,j,snowflake_code; //Hash code  
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   
        snow = malloc(sizeof(snowflake_node));
        if(snow==NULL){
            fprintf(stderr,"Memory allocation failed\n");
            exit(1);
        }
        for(j=0;j<6;j++){
            scanf("%d",&snow->snowflake[j]);
        }
        snowflake_code = code(snow->snowflake);
        snow->next = snowflakes[snowflake_code];
        snowflakes[snowflake_code] = snow;

    }
    identify_identical(snowflakes);
    return 0;

}