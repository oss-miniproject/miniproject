#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GMP.h"

int first_selectMenu();   // 관리자 모드와 사용자모드 구분
int user_login(); //회원모드 접속 로그인 - 리턴값: 회원정보 리스트에서 회원의 index
int manager_selectMenu(); // 관리자 모드 메뉴
int user_selectMenu();    // 사용자 모드 메뉴
int loadData(User *u[]);  // 관리자 모드와 사용자 메뉴 시작하면 호출
int addUser(User *u[],int num); // 신규 회원 추가(only 관리자)
void readUser(User *u[], int total); // 전체 회원 정보 조회(only 관리자)
int selectUser(User *u[],int total); // 원하는 사용자 선택
int updateUser(User *u[], int total); // 회원 정보 수정 (관리자 and 사용자)
int deleteUser(User *u[], int total); // 회원 삭제 (only 관리자)
void saveData(User *u[], int total);  // 회원 정보 파일에 저장 (관리자 and 사용자)
void searchData(User *u[], int total); // 회원 검색 (only 관리자)
void readOneUser(User *u[]); // 한명의 회원 정보만 보여줌
int addClass(User *u[], int total); // 수업 신청(only 사용자)

int first_selectMenu() {
    int inputnum;
    printf("\n===== Gym Management Program =====\n");
    printf("\n1. Admin(관리자)\n2. Member(회원)\n0. Exit(종료)\n");
    printf("\nSelect Menu > ");
    scanf("%d", &inputnum);
    
    return inputnum;
}

int manager_selectMenu() {
    int menu;
    printf("\n관리자 모드\n");
    printf("1. 전체 회원 조회\n");
    printf("2. 회원 정보 추가\n");
    printf("3. 회원 정보 수정\n");
    printf("4. 회원 정보 삭제\n");
    printf("5. 회원 검색\n");
    printf("0. 로그아웃 및 \n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int user_selectMenu() {
    int menu;
   
    printf("\n회원 모드\n");
    printf("1. 회원 정보 조회\n"); // readOneUser 실행(로그인한 한명의 회원 정보만 보여줌)
    printf("2. 회원 정보 수정\n");
    printf("3. 수업 신청\n");
    printf("0. 로그아웃 및 저장\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    
    return menu;
}

int loadData(User *u[]) {
    return 1;
}

int addUser(User *u[], int num) {
    u[num] = (User *)malloc(sizeof(User));

    printf("이름은?");
    scanf("%s", u[num]->name);
    printf("사용자 ID는?");
    scanf("%s", u[num]->ID);
    printf("수강 중인 강좌는?");
    scanf("%d %d %d", &u[num]->class_list[0], &u[num]->class_list[1], &u[num]->class_list[2]);
    printf("남은 일수는?");
    scanf("%d", &u[num]->day);
    
    return 1;
}

void readUser(User *u[], int total) {
    char classOffered[3][40] = {"필라테스", "헬스", "PT"};
    printf("No Name  ID  class-list  day");
    printf("*********************************\n");
    for(int i = 0; i < total; i++){
        if(u[i] == NULL){
            continue;
        }
        printf("%d %s %3s ", i+1, u[i]->name, u[i]->ID);
        for (int j=0; j<3; j++) {
            if (u[j]->class_list[j] == 1) {
                printf("%s ", classOffered[j]);
            }
        }
        printf("%3d\n", u[i]->day);
    }
}

void saveData(User *u[], int total) {
    
}

void readOneUser(User *u[]) {

}
int selectUser(User *u[],int total){
    readUser(u,total);
    int number;
    printf("\n번호는 (취소 : 0)?");
    scanf("%d",&number);
    return number;
}
