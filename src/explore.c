#include <stdio.h>
#include "game.h"

void explore(struct Player *g)
{
    int choice;
    printf("\nYou are exploring...\n");
    printf("1. Hills\n2. Villages\n3. Forests\n> ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You found 10 coins!\n");
        g->coins += 10;
    }
    else if (choice == 2)
    {
        printf("You met a kind villager! +5 XP.\n");
        g->xp += 5;
    }
    else if (choice == 3)
    {
        printf("Oh no! You fell into a trap. -15 HP.\n");
        g->health -= 15;
    }
    else
    {
        printf("Nothing interesting happened.\n");
    }
}