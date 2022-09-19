#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt for input
    int height;
    do
 {
        height=get_int("height");
 }
    while (height<1 || height>8);

for (int row=0; row<height; row++)
{
     for(int spaces=height-1; spaces>row; spaces--)
    {
        printf(" ");
    }
    
    for(int hashes=row+height+1 ;hashes>height; hashes--)
    {
        printf("#");
    }

    printf("\n");
}
}

