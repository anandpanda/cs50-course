#include <cs50.h>
#include <stdio.h>

int main()
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for (int i = 0; i < h; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            if (j < (h - i))
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }

    return 0;
}
