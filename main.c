#include <stdio.h>
#include "GMP.h"

int main() {
    User *u_list[100];
    int mode;
    int manager_mode;
    int user_mode;

    while(1) {
        mode = first_selectMenu();
        if (mode == 1) {
            manager_mode = manager_selectMenu();
            if(manager_mode == 0){
                break;
            }
        }
        else if (mode == 2) {
            user_mode = user_selectMenu();
            if(user_mode == 0){
                break;
            }
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
