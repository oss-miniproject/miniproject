
#include <stdio.h>
#include "GMP.h"

int main() {
    User *u_list[100];
    int mode, manager_mode, user_mode, count, index, uLogin, mLogin;

    count = loadData(u_list);
    index = count;

    while(1) {
        mode = first_selectMenu();
        if (mode == 1) {
            mLogin = manager_login();
            if(mLogin == 0){
                continue;
            }
            else{
                while(1){
                    manager_mode = manager_selectMenu();
                    if(manager_mode == 0){
                        saveData(u_list, index);
                        printf("\n=> 로그아웃 되었습니다!\n");
                        break;
                    }
                    if(manager_mode == 1 || manager_mode == 3 || manager_mode == 4){
                        if(count == 0){
                            printf("\n=> 입력된 정보가 없습니다.\n ");
                                continue;
                        }
                    }
                    if(manager_mode == 1) {
                        listUser(u_list, index);
                    }

                    else if (manager_mode == 2) {
                        if(addUser(u_list, index++) == 0){
                            printf("\n=> 추가실패..\n");
                            continue;
                        }
                        else{
                            count++;
                            printf("\n=> 추가완료!\n");
                        }
                    }

                    else if (manager_mode == 3){
                        if(updateUser(u_list, index) == 0){
                            printf("\n=> 수정실패..\n");
                            continue;
                        }
                        else{
                            printf("\n=> 수정완료!\n");
                        }
                    }
                    else if (manager_mode == 4){
                        if(deleteUser(u_list, index) == 0){
                            printf("\n=> 삭제실패..\n");
                            continue;
                        }
                        else{
                            printf("=> 삭제완료!\n");
                            count--;
                        }
                    }
                    else if(manager_mode == 5){
                        searchData(u_list, index);
                    }
                }
            }
            
        }
        else if (mode == 2) {
             if (count == 0) {
                printf("\n등록된 회원이 없습니다. 관리자에게 문의해주세요!\n");
            }
            else {
                uLogin = user_login(u_list, index);
                if (uLogin >= 0) {
                    printf("\n%s님 안녕하세요!\n", u_list[uLogin]->name);
                    while(1) {
                        user_mode = user_selectMenu();
                        if (user_mode == 1) {
                            printf("\n");
                            readUser(*u_list[uLogin]);
                        }
                        else if (user_mode == 2) {
                            if (addClass(u_list[uLogin])==0) {
                                printf("\n=> 신청실패..\n");
                                continue;
                            }
                            else {
                                printf("\n=> 신청완료!\n");
                            }
                        }
                        else if (user_mode == 3) {
                            if (extendUse(u_list[uLogin])==0) {
                                printf("\n=> 수정실패..\n");
                                continue;
                            }
                            else {
                                printf("\n=> 수정완료!\n");
                            }
                        }
                        else if (user_mode == 4) {
                            BmiTester(u_list[uLogin]);
                        }
                        else {
                            saveData(u_list, count);
                            printf("\n로그아웃 되었습니다!\n");
                            break;
                        }
                    }
                }
                else {
                    printf("\n=> 등록되지 않은 회원입니다. 관리자에게 문의해주세요!\n");
                }
            }
        }
        else if (mode == 0) {
            printf("\n===== 프로그램을 종료합니다 =====\n");
            break;
        }
        else {
            printf("\n=> 잘못된 입력입니다.\n");
        }
    }
}
