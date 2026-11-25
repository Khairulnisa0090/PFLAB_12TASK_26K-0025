
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i;
    int totalCharacters = 0;
    int longestIndex = 0;

    char **feedback = NULL;

    printf("Enter number of feedback entries: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of entries.");
        return 0;
    }

    feedback = (char **)malloc(n * sizeof(char *));

    if (feedback == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    feedback = (char **)realloc(feedback, n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        char temp[500];

        printf("Enter feedback %d: ", i + 1);
        scanf(" %[^\n]", temp);

        feedback[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));

        if (feedback[i] == NULL)
        {
            printf("Memory allocation failed.");
            int j;
            for ( j = 0; j < i; j++)
                free(feedback[j]);

            free(feedback);
            return 1;
        }

        strcpy(feedback[i], temp);

        totalCharacters += strlen(feedback[i]);
    }

    int maxLength = 0;

    for (i = 0; i < n; i++)
    {
        int length = 0;
        char *ptr = feedback[i];

        while (*ptr != '\0')
        {
            length++;
            ptr++;
        }

        if (length > maxLength)
        {
            maxLength = length;
            longestIndex = i;
        }
    }

    printf("\nAll Feedback Entries:\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\n", feedback[i]);
    }

    printf("\nTotal Characters = %d", totalCharacters);
    printf("\nLongest Feedback = %s", feedback[longestIndex]);
    printf("\nLongest Length = %d", maxLength);

    for (i = 0; i < n; i++)
    {
        free(feedback[i]);
    }

    free(feedback);

    return 0;
}

