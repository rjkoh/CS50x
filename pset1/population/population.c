#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
int n;
do
{
    n=get_int("population start size\n");
}
while (n<9);
    // TODO: Prompt for end size
int end;
do
{  
    end=get_int("population end size\n");
}
while (end<n);
    // TODO: Calculate number of years until we reach threshold
int years=0;
do
{
    n=(n+n/3-n/4);
    years++;
}
while(n<end);
    // TODO: Print number of years
    printf("the number of years is %i\n",years);
}
