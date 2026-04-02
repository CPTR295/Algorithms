#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000

int max(int v1,int v2){
    if(v1>v2)
        return v1;
    else
        return v2;
}

int solve(char outcomes1[], char outcomes2[], int goals1[], int goals2[], int i , int j)
{
    int first, second,third,forth;
    
    if(i==0||j==0)
        return 0;
    if((outcomes1[i] == 'W' && outcomes2[j]=='L' && goals1[i]>goals2[j]) || (outcomes1[i] == 'L' && outcomes2[j]=='W' && goals1[i]<goals2[j]))
    {
        first = solve(outcomes1,outcomes2,goals1,goals2,i-1,j-1)+goals1[i]+goals2[j];
    }
    else
        first = 0;
    second = solve(outcomes1,outcomes2,goals1,goals2,i-1,j-1);
    third = solve(outcomes1,outcomes2,goals1,goals2,i-1,j);
    forth = solve(outcomes1,outcomes2,goals1,goals2,i,j-1);
    return max(first,max(second,max(third,forth)));
}

int main(void)
{
    int i,n,result;
    char outcomes1[SIZE+1],outcomes2[SIZE+1];
    int goals1[SIZE+1],goals2[SIZE+1];
    scanf("%d ",&n);
    for(i=1;i<=n;i++)
        scanf("%c",&outcomes1[i]);
    for(i=1;i<=n;i++)
        scanf("%d ",&goals1[i]);

    for(i=1;i<=n;i++)
        scanf("%c",&outcomes2[i]);    
    for(i=1;i<=n;i++)
        scanf("%d ",&goals2[i]);
    
    result = solve(outcomes1,outcomes2,goals1,goals2,n,n);
    printf("%d\n",result);
    return 0;
}