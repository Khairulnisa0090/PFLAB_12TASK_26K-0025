
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getCategory(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return 1;

    else if (ch >= 'a' && ch <= 'z')
        return 2;

    else if (ch >= '0' && ch <= '9')
        return 3;

    else
        return 4;
}

int main()
{
    int n, i, j;
    int highestIndex = 0;
    float highestScore = -1;

    char *pattern;
    char **passwords;
    float *scores;

    printf("Enter number of participants: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number.");
        return 0;
    }

    char temp[200];

    printf("Enter password pattern: ");
    scanf("%199s", temp);

    pattern = (char *)malloc((strlen(temp) + 1) * sizeof(char));

    if (pattern == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    strcpy(pattern, temp);

    int length = strlen(pattern);

    passwords = (char **)malloc(n * sizeof(char *));
    scores = (float *)malloc(n * sizeof(float));

    if (passwords == NULL || scores == NULL)
    {
        printf("Memory allocation failed.");
        free(pattern);
        free(passwords);
        free(scores);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter password attempt %d: ", i + 1);
        scanf("%199s", temp);

        passwords[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));

        if (passwords[i] == NULL)
        {
            printf("Memory allocation failed.");

            for (j = 0; j < i; j++)
                free(passwords[j]);

            free(passwords);
            free(scores);
            free(pattern);
            return 1;
        }

        strcpy(passwords[i], temp);

        int match = 0;

        for (j = 0; j < length && passwords[i][j] != '\0'; j++)
        {
            if (getCategory(pattern[j]) == getCategory(passwords[i][j]))
            {
                match++;
            }
        }

        scores[i] = ((float)match / length) * 100;

        if (scores[i] > highestScore)
        {
            highestScore = scores[i];
            highestIndex = i;
        }
    }

    printf("\nPassword Similarity Results:\n");

    for (i = 0; i < n; i++)
    {
        printf("\nPassword: %s", passwords[i]);
        printf("\nSimilarity: %.2f%%\n", scores[i]);
    }

    printf("\nHighest Similarity Password: %s",
           passwords[highestIndex]);

    printf("\nHighest Similarity Score: %.2f%%",
           highestScore);

    for (i = 0; i < n; i++)
    {
        free(passwords[i]);
    }

    free(passwords);
    free(scores);
    free(pattern);

    return 0;
}

