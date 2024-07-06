#include <cs50.h>
#include <stdio.h>

int main()
{

    int cents = 0;
    do
    {
        cents = get_int("Money owed: ");
    }
    while (cents < 0);

    int coins = 0;

    coins += cents / 25;
    cents = cents % 25;

    coins += cents / 10;
    cents = cents % 10;

    coins += cents / 5;
    cents = cents % 5;

    coins += cents;

    printf("%i\n", coins);

    return 0;
}
