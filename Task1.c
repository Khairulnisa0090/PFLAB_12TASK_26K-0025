
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, total = 0, lowest = 0;
    int *stock;
    float average;

    printf("Enter number of book categories: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of categories.");
        return 0;
    }

    stock = (int *)malloc(n * sizeof(int));

    if (stock == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter stock for category %d: ", i);
        scanf("%d", &stock[i]);

        total += stock[i];
    }

    average = (float)total / n;

    for (i = 1; i < n; i++)
    {
        if (stock[i] < stock[lowest])
        {
            lowest = i;
        }
    }

    printf("\nTotal Stock = %d", total);
    printf("\nAverage Stock = %.2f", average);
    printf("\nLowest Stock Category Index = %d", lowest);

    int choice, newStock;

    printf("\n\nEnter category index to update (0 to %d): ", n - 1);
    scanf("%d", &choice);

    if (choice >= 0 && choice < n)
    {
        printf("Enter new stock: ");
        scanf("%d", &newStock);

        stock[choice] = newStock;

        total = 0;
        lowest = 0;

        for (i = 0; i < n; i++)
        {
            total += stock[i];
        }

        average = (float)total / n;

        for (i = 1; i < n; i++)
        {
            if (stock[i] < stock[lowest])
                lowest = i;
        }

        printf("\nUpdated Total Stock = %d", total);
        printf("\nUpdated Average Stock = %.2f", average);
        printf("\nUpdated Lowest Category Index = %d", lowest);
    }
    else
    {
        printf("Invalid category index.");
    }

    free(stock);

    return 0;
}

