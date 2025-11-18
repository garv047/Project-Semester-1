#include <stdio.h>

struct Player
{
    char name[30];
    int health;
    int xp;
    int gold;
};

void fight(struct Player *p);


void fight(struct Player *p)
{
    int difficulty;
    printf("\nEnter enemy difficulty (1-5): ");
    scanf("%d", &difficulty);
    if (difficulty < 1)
        difficulty = 1;
    if (difficulty > 5)
        difficulty = 5;

    int damage = difficulty * 10;
    int reward = difficulty * 10;

    printf("You fought bravely! Took %d damage, gained %d XP.\n", damage, reward);

    p->health -= damage;
    p->xp += reward;
    p->gold += difficulty * 2;
}
int main(void)
{
    struct Player player;

    printf("Enter your hero's name: ");
    scanf("%29s", player.name);

    player.health = 100;
    player.xp = 0;
    player.gold = 10;

    int choice;

    printf("\n⚔️ Welcome, %s! Your adventure begins...\n", player.name);

}