#include <stdio.h>
#include <cs50.h>
#include <math.h>

int coins;
int main(void)
{
    float change;
    do
    {
        change = get_float("change owed\n");
    }
    while (change < 0);
    
    int cents = round(change * 100);
    
    //using quarters
    for (; cents >= 25;)
    {
        cents = cents - 25;
        coins++;
    }
    
    //using dimes
    for (; cents >= 10;)
    {
        cents = cents - 10;
        coins++;
    }
    
    //using nickels
    for (; cents >= 5 ;)
    {
        cents = cents - 5;
        coins++;
    }
    
    //using pennies
    for (; cents >= 1;)
    {
        cents = cents - 1;
        coins++;
    }
    
    //telling user number of coins
    printf("number of coins is %i\n", coins);
    
}