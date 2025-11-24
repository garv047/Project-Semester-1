#include <stdio.h>
#include "game.h"

void heal(struct Player *g)
{
    if (g->coins >= 5)
    {
        printf("\nYou spend 5 coins to heal +25 HP.\n");
        g->health += 25;
        g->coins -= 5;
        if (g->health > 100) g->health = 100;
    }
    else
    {
        printf("\nNot enough coins to heal!\n");
    }
}