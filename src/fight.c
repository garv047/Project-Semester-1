#include <stdio.h>
#include "game.h"

void fight(struct Player *g)
{
    int difficulty;
    printf("\nEnter enemy difficulty (1-5): ");
    scanf("%d", &difficulty);

    if (difficulty < 1) difficulty = 1;
    if (difficulty > 5) difficulty = 5;

    int damage = difficulty * 10;
    int reward = difficulty * 10;

    printf("You fought bravely! Took %d damage, gained %d XP.\n", damage, reward);

    g->health -= damage;
    g->xp += reward;
    g->coins += difficulty * 2;
}