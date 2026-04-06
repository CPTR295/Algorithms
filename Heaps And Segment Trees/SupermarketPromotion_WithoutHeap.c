#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECEIPTS 1000000
#define MAX_COSTS 1000000

typedef struct receipt
{
    int cost;
    int used;
}receipt;

int extract_max(receipt receipts[], int num_receipts)
{
    int max_index = -1;
    int max_cost = -1;
    for (int i = 0; i < num_receipts; i++)
    {   
        if (!receipts[i].used && receipts[i].cost > max_cost)
        {
            max_cost = receipts[i].cost;
            max_index = i;
        }
    }
    receipts[max_index].used = 1; // Mark the receipt as used
    return max_cost;
}

int extract_min(receipt receipts[], int num_receipts)
{
    int min_index = -1;
    int min_cost = 1000000000; // A large number
    for (int i = 0; i < num_receipts; i++)
    {   
        if (!receipts[i].used && receipts[i].cost < min_cost)
        {
            min_cost = receipts[i].cost;
            min_index = i;
        }
    }
    receipts[min_index].used = 1; // Mark the receipt as used
    return min_cost;
}

int main(void)
{
    static struct receipt receipts[MAX_RECEIPTS];
    int num_days, num_receipts_today;
    int num_receipts = 0;
    long long total_price = 0;
    int i,j,max,min;
    scanf("%d",&num_days);

    for(i=0;i<num_days;i++)
    {
        scanf("%d",&num_receipts_today);
        for(j=0;j<num_receipts_today;j++)
        {
            scanf("%d",&receipts[num_receipts].cost);
            receipts[num_receipts].used = 0; // Initialize as unused
            num_receipts++;
        }
        max = extract_max(receipts, num_receipts);
        min = extract_min(receipts, num_receipts);
        total_price += max-min;
    }
    printf("%lld\n",total_price);
    return 0;

}