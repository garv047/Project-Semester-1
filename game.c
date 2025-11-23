#include <stdio.h>

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


void fight(struct Player *g)
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

    g->health -= damage;
    g->xp += reward;
    g->coins += difficulty * 2;
}

void heal(struct Player *g)
{
    if (g->coins >= 5)
    {
        printf("\nYou spend 5 coins to heal +25 HP.\n");
        g->health += 25;
        g->coins -= 5;
        if (g->health > 100)
            g->health = 100;
    }
    else
    {
        printf("\nNot enough coins to heal!\n"); 
    }
}

void explore(struct Player *g)
{
    int choice;
    printf("\nYou are exploring...\n");
    printf("Choose Exploring number:\n1. Hills\n2. Villages\n3. Forests\n> ");
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

int main(void)
{
    struct Player player;

    printf("Enter your hero's name: ");
    scanf("%29s", player.name);

    player.health = 100;
    player.xp = 0;
    player.coins = 10;

    int choice;

    printf("\n⚔️ Welcome, %s! Your adventure begins...\n", player.name);

    while (player.health > 0)
    {
        printf("\n💪 Health: %d | ⭐ XP: %d | 💰 coins: %d\n", player.health, player.xp, player.coins);
        printf("Choose an action:\n");
        printf("1. Explore 🌍\n2. Fight 🐉\n3. Heal 💊\n4. Quit ❌\n> ");
        scanf("%d", &choice);

        if (choice == 1)
            explore(&player);
        else if (choice == 2)
            fight(&player);
        else if (choice == 3)
            heal(&player);
        else if (choice == 4)
        {
            printf("You retire from your adventure. 🏰\n");
            return 0;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    printf("\n💀 %s has fallen in battle. Game Over.\n", player.name);
    return 0;
}