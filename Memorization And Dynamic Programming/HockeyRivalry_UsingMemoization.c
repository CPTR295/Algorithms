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

int solve(char outcomes1[], char outcomes2[], int goals1[], int goals2[], int i , int j,int memo[SIZE+1][SIZE+1])
{
    int first, second,third,forth;

    if(memo[i][j]!=-1)
        return memo[i][j];
    
    if(i==0 || j==0){
        memo[i][j]=0;
        return memo[i][j];
    }

    if((outcomes1[i] == 'W' && outcomes2[j]=='L' && goals1[i]>goals2[j]) || (outcomes1[i] == 'L' && outcomes2[j]=='W' && goals1[i]<goals2[j]))
    {
        first = solve(outcomes1,outcomes2,goals1,goals2,i-1,j-1,memo)+goals1[i]+goals2[j];
    }
    else
        first = 0;
    second = solve(outcomes1,outcomes2,goals1,goals2,i-1,j-1,memo);
    third = solve(outcomes1,outcomes2,goals1,goals2,i-1,j,memo);
    forth = solve(outcomes1,outcomes2,goals1,goals2,i,j-1,memo);
    memo[i][j] = max(first,max(second,max(third,forth)));
    return memo[i][j];
}

int main(void)
{
    int i,j,n,result;
    char outcomes1[SIZE+1],outcomes2[SIZE+1];
    int goals1[SIZE+1],goals2[SIZE+1];
    static int memo[SIZE+1][SIZE+1];
    scanf("%d ",&n);
    for(i=1;i<=n;i++)
        scanf("%c",&outcomes1[i]);
    for(i=1;i<=n;i++)
        scanf("%d ",&goals1[i]);
    for(i=1;i<=n;i++)
        scanf("%c",&outcomes2[i]);    
    for(i=1;i<=n;i++)
        scanf("%d ",&goals2[i]);
    
    for(i=1;i<SIZE+1;i++)
        for(j=0;j<SIZE+1;j++)
            memo[i][j]=-1;
    
    result = solve(outcomes1,outcomes2,goals1,goals2,n,n,memo);
    printf("%d\n",result);
    return 0;
}