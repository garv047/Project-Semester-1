#include <stdio.h>
#include "game.h"

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
        printf("\n💪 Health: %d | ⭐ XP: %d | 💰 coins: %d\n",
               player.health, player.xp, player.coins);

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
            printf("Invalid choice!\n");
    }

    printf("\n💀 %s has fallen in battle. Game Over.\n", player.name);
    return 0;
}