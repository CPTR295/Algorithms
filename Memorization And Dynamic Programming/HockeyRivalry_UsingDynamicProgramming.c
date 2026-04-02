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

int solve(char outcomes1[], char outcomes2[], int goals1[], int goals2[], int n)
{
    int first, second,third,forth;
    int i,j;
    static int dp[SIZE+1][SIZE+1];
    for(i=0;i<=n;i++)
        dp[0][i]=0;
    
    for(i=0;i<=n;i++)
        dp[i][0]=0;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if((outcomes1[i]=='W' && outcomes2[j]=='L' && goals1[i]>goals2[j]) || (outcomes1[i]=='L' && outcomes2[j]=='W' && goals1[i]<goals2[j]))
                first = dp[i-1][j-1]+goals1[i]+goals2[j];
            else
                first = 0;
            second = dp[i-1][j-1];
            third = dp[i-1][j];
            forth = dp[i][j-1];
            dp[i][j] = max(first,max(second,max(third,forth)));
        }
        return dp[n][n];
    
}

int main(void)
{
    int i,j,n,result;
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
    

    
    result = solve(outcomes1,outcomes2,goals1,goals2,n);
    printf("%d\n",result);
    return 0;
}