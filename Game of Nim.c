#include <stdio.h>
#include <stdlib.h>
void gameOfNim(int pile[], int n, int totalCoins)
{
    int turn = 1, a_pile, a_coins, b_pile, b_coins, j;

    while(totalCoins > 0)
    {
        if(turn%2 != 0)
        {
            printf("\n\nPLAYER A'S TURN\n");
            printf("---------------");

            while(1)
            {
                printf("\n\nWhich pile do you select? ");
                scanf("%d", &a_pile);

                if(pile[a_pile - 1] <= 0)
                    printf("\nThis pile is already empty. Enter again.\n");
                else if(a_pile <= 0 || a_pile > n)
                    printf("\nInvalid pile number. Enter again.\n");
                else
                    break;
            }

            while(1)
            {
                printf("\nHow many coins do you want to remove? ");
                scanf("%d", &a_coins);

                if(pile[a_pile - 1] - a_coins < 0)
                    printf("\nYou cannot remove this many coins from this pile. Enter again.\n");
                else if(a_coins <= 0)
                    printf("\nYou must remove at least one coin in your turn. Enter again.\n");
                else
                    break;
            }

            pile[a_pile - 1] = pile[a_pile - 1] - a_coins;

            totalCoins = totalCoins - a_coins;

            turn++;

            printf("\n\nPile of coins:\n\n");
            for(j = 0; j < n; j++)
                printf("%d\t",pile[j]);
        }
        else
        {
            printf("\n\nPLAYER B'S TURN\n");
            printf("---------------");
            while(1)
            {
                printf("\nWhich pile do you select? ");
                scanf("%d", &b_pile);

                if(pile[b_pile - 1] <= 0)
                    printf("\nThis pile is already empty. Enter again.\n");
                else if(b_pile <= 0 || b_pile > n)
                    printf("\nInvalid pile number. Enter again.\n");
                else
                    break;
            }
            while(1)
            {
                printf("\nHow many coins do you want to remove? ");
                scanf("%d", &b_coins);

                if(pile[b_pile - 1] - b_coins < 0)
                    printf("\nYou cannot remove this many coins from this pile. Enter again.\n");
                else if(b_coins <= 0)
                    printf("\nYou must remove at least one coin in your turn. Enter again.\n");
                else
                    break;
            }

            pile[b_pile - 1] = pile[b_pile - 1] - b_coins;
            totalCoins = totalCoins - b_coins;

            turn++;
            printf("\n\nPile of coins:\n\n");
            for(j = 0; j < n; j++)
                printf("%d\t",pile[j]);
        }
    }
    if(turn % 2 == 0)
        printf("\n\nPlayer A wins the game!!!\n\n");
    else
        printf("\n\nPlayer B wins the game!!!\n\n");
}
int main()
{
    int totalCoins = 0, n, i;

    printf("Enter the total number of piles of coins: ");
    scanf("%d", &n);
    int pile[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter number of coins in Pile #%d: ", i+1);
        scanf("%d", &pile[i]);
        totalCoins += pile[i];
    }

    printf("\nPile of coins:\n\n");
    for(i = 0; i < n; i++)
        printf("%d\t", pile[i]);

    gameOfNim(pile, n, totalCoins);
    return 0;
}
