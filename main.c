#include <stdio.h>
#include "GMP.h"

int main() {
    int mode;

    while(1) {
        mode = first_selectMenu();
        if (mode == 1) {
            manager_selectMenu();
        }
        else if (mode == 2) {
            user_selectMenu();
        }
        else if (mode == 0) {
            printf("\nGood Bye!\n");
            break;
        }
        else {
            printf("\nwrong input!\n");
            break;
        }
    }
}