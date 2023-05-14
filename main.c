#include <stdio.h>
#include "GMP.h"

int main() {
    User *u_list[100];
    int mode, manager_mode, user_mode, count, index, uLogin;

    count = loadData(u_list);
    index = count;

    while(1) {
        mode = first_selectMenu();
        if (mode == 1) {
            manager_mode = manager_selectMenu();
            if(manager_mode == 0){
                break;
            }
        }
        else if (mode == 2) {
             if (count == 0) {
                printf("등록된 회원이 없습니다. 관리자에게 문의해주세요!\n");
            }
            else {
                uLogin = user_login();
                if (uLogin >= 0) {
                    while(1) {
                        user_mode = user_selectMenu();
                        if (user_mode == 1) {
                            readOneUser(&u_list[uLogin]);
                        }
                        else if (user_mode == 2) {

                        }
                        else {
                            saveData(u_list, index);
                            printf("\n로그아웃 되었습니다!\n");
                            break;
                        }
                    }
                }
                else {
                    printf("등록되지 않은 회원입니다. 관리자에게 문의해주세요!\n");
                }
            }
        }
        else if (mode == 0) {
            printf("\nGood Bye!\n");
            break;
        }
        else {
            printf("\nwrong input!\n");
        }
    }
}
