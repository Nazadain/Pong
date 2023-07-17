#include <stdio.h>
#include <stdlib.h>

int game();
int bot_game();

int main() {
    int inp;
    system("clear");
    printf("██████╗░██╗███╗░░██╗░██████╗░  ██████╗░░█████╗░███╗░░██╗░██████╗░\n");
    printf("██╔══██╗██║████╗░██║██╔════╝░  ██╔══██╗██╔══██╗████╗░██║██╔════╝░\n");
    printf("██████╔╝██║██╔██╗██║██║░░██╗░  ██████╔╝██║░░██║██╔██╗██║██║░░██╗░\n");
    printf("██╔═══╝░██║██║╚████║██║░░╚██╗  ██╔═══╝░██║░░██║██║╚████║██║░░╚██╗\n");
    printf("██║░░░░░██║██║░╚███║╚██████╔╝  ██║░░░░░╚█████╔╝██║░╚███║╚██████╔╝\n");
    printf("╚═╝░░░░░╚═╝╚═╝░░╚══╝░╚═════╝░  ╚═╝░░░░░░╚════╝░╚═╝░░╚══╝░╚═════╝░\n");
    printf("\nControls:\n");
    printf("\tLeft Player: ");
    printf("a - up, z - down\n");
    printf("\tRight Player: ");
    printf("k - up, m - down\n");
    printf("\tq - quit\n\n");
    printf("1: Play PVP\n");
    printf("2: Play vs Bot\n");
    printf("3: Exit\n");
    printf(">");
    scanf("%d", &inp);
    switch (inp) {
        case 1:
            game();
            break;
        case 2:
            bot_game();
            break;
        case 3:
            break;
        default:
            printf("error");
            return 1;
    }
    return 0;
}