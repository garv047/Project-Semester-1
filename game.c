#include <stdio.h>

struct Player
{
    char name[30];
    int health;
    int xp;
    int gold;
};

void fight(struct Player *p);
void heal(struct Player *p);
void explore(struct Player *p);

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

void heal(struct Player *p)
{
    if (p->gold >= 5)
    {
        printf("\nYou spend 5 gold to heal +25 HP.\n");
        p->health += 25;
        p->gold -= 5;
        if (p->health > 100)
            p->health = 100;
    }
    else
    {
        printf("\nNot enough gold to heal!\n");
    }
}

void explore(struct Player *p)
{
    int choice;
    printf("\nYou are exploring...\n");
    printf("Choose Exploring number:\n1. Hills\n2. Villages\n3. Forests\n> ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You found 10 gold!\n");
        p->gold += 10;
    }
    else if (choice == 2)
    {
        printf("You met a kind villager! +5 XP.\n");
        p->xp += 5;
    }
    else if (choice == 3)
    {
        printf("Oh no! You fell into a trap. -15 HP.\n");
        p->health -= 15;
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
    player.gold = 10;

    int choice;

    printf("\n⚔️ Welcome, %s! Your adventure begins...\n", player.name);

    while (player.health > 0)
    {
        printf("\n💪 Health: %d | ⭐ XP: %d | 💰 Gold: %d\n", player.health, player.xp, player.gold);
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