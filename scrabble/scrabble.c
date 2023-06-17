#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 < score2)
    {
        printf("Winner: Player2!\n");
    }
    else if (score1 > score2)
    {
        printf("Winnner: Player1!\n");
    }
    else
    {
        printf("Tie.\n");
    }
}


// TODO: Compute and return score for string
int compute_score(string word)
{
    int s = 0;
    int L = strlen (word);

    for( int y=0 ; y<L ; y++)
    {
        int c = toupper(word[y]);

        if (c > 64 && c < 91)
        {
            s += POINTS[c-65];
        }
    }

    return s;
}
