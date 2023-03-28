#include <cs50.h>
#include <stdio.h>

/* right align mario blocks */
int main(void)
{
    int heigth;
    do
    {
        heigth = get_int("Write a height of the blocks (1-8) \n");
    }
    while (heigth <= 0 || heigth > 8);
    for(int i = 0; i < heigth; i++)
    {
        for(int k = heigth - 1; k > i; k--)
        {
            printf(" ");
        }
        for(int n = 0; n <= i; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}
