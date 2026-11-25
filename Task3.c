
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int containsDigit(char *str)
{
    while (*str != '\0')
    {
        if (isdigit((unsigned char)*str))
        {
            return 1;
        }

        str++;
    }

    return 0;
}

int main()
{
    int n, i;

    char **username;

    printf("Enter number of usernames: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number.");
        return 0;
    }

    username = (char **)malloc(n * sizeof(char *));

    if (username == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        char temp[100];

        printf("Enter username %d: ", i + 1);
        scanf("%99s", temp);

        username[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));

        if (username[i] == NULL)
        {
            printf("Memory allocation failed.");
            int j;
            for ( j = 0; j < i; j++)
                free(username[j]);

            free(username);
            return 1;
        }

        strcpy(username[i], temp);
    }

    printf("\nValid Usernames:\n");

    for (i = 0; i < n; i++)
    {
        if (containsDigit(username[i]) == 0)
        {
            printf("%s\n", username[i]);
        }
    }

    printf("\nUsernames containing digits were removed.");

    for (i = 0; i < n; i++)
    {
        free(username[i]);
    }

    free(username);

    return 0;
}

