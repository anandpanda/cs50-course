#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Compute Score
int score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
            score += points[word[i] - 'A'];
        else if (islower(word[i]))
            score += points[word[i] - 'a'];
    }
    return score;
};

int main()
{
    // input from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score
    int score1 = score(word1);
    int score2 = score(word2);

    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score2 > score1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}
