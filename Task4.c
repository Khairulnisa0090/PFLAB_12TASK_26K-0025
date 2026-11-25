
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int total = 0;
    int highest = 0;
    int *ratings;
    float average;

    printf("Enter number of movie categories: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of categories.");
        return 0;
    }

    ratings = (int *)malloc(n * sizeof(int));

    if (ratings == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter rating count for category %d: ", i);
        scanf("%d", &ratings[i]);

        total += ratings[i];
    }

    for (i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[highest])
        {
            highest = i;
        }
    }

    average = (float)total / n;

    printf("\nTotal Ratings = %d", total);
    printf("\nAverage Ratings = %.2f", average);
    printf("\nHighest Rating Category Index = %d", highest);

    int choice, newRating;

    printf("\n\nEnter category index to update (0 to %d): ", n - 1);
    scanf("%d", &choice);

    if (choice >= 0 && choice < n)
    {
        printf("Enter new rating count: ");
        scanf("%d", &newRating);

        ratings[choice] = newRating;

        total = 0;
        highest = 0;

        for (i = 0; i < n; i++)
        {
            total += ratings[i];
        }

        for (i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[highest])
            {
                highest = i;
            }
        }

        average = (float)total / n;

        printf("\nUpdated Total Ratings = %d", total);
        printf("\nUpdated Average Ratings = %.2f", average);
        printf("\nUpdated Highest Category Index = %d", highest);
    }
    else
    {
        printf("Invalid category index.");
    }

    free(ratings);

    return 0;
}

