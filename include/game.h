#ifndef GAME_H
#define GAME_H

struct Player
{
    char name[30];
    int health;
    int xp;
    int coins;
};

void fight(struct Player *g);
void heal(struct Player *g);
void explore(struct Player *g);

#endif
