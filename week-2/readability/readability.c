#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int words(string s)
{
    int w = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        w += (s[i] == ' ');
    return (w + 1);
}

int letters(string s)
{
    int l = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        l += (isupper(s[i]) || islower(s[i]));
    return l;
}

int sentences(string s)
{
    int l = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        l += (s[i] == '.' || s[i] == '!' || s[i] == '?');
    return l;
}

int main()
{
    string text = get_string("Text: ");
    int W = words(text);
    int L = letters(text);
    int S = sentences(text);

    int index = round(0.0588 * (L / (float) W * 100.0) - 0.296 * (S / (float) W * 100.0) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
