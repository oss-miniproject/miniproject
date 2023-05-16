#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GMP.h"

int first_selectMenu();   // 관리자 모드와 사용자모드 구분
int manager_login();
int user_login(); //회원모드 접속 로그인 - 리턴값: 회원정보 리스트에서 회원의 index
int manager_selectMenu(); // 관리자 모드 메뉴
int user_selectMenu();    // 사용자 모드 메뉴
int loadData(User *u[]);  // 관리자 모드와 사용자 메뉴 시작하면 호출
int addUser(User *u[],int num); // 신규 회원 추가(only 관리자)
void readUser(User u);
void listUser(User *u[], int total); // 전체 회원 정보 조회(only 관리자)
int selectUser(User *u[],int total); // 원하는 사용자 선택
int updateUser(User *u[], int total); // 회원 정보 수정 (관리자 and 사용자)
int deleteUser(User *u[], int total); // 회원 삭제 (only 관리자)
void saveData(User *u[], int total);  // 회원 정보 파일에 저장 (관리자 and 사용자)
void searchData(User *u[], int total); // 회원 검색 (only 관리자)
int addClass(User *u[], int total); // 수업 신청(only 사용자)

int first_selectMenu() {
    int inputnum;
    printf("\n===== Gym Management Program =====\n");
    printf("\n1. 관리자(Admin)\n2. 회원(Member)\n0. 종료(Exit)\n");
    printf("\n=> 접속 모드는? ");
    scanf("%d", &inputnum);
    
    return inputnum;
}

int manager_login(){
	char ID[40];
	printf("관리자 ID를 입력하시오 (기본값: admin)  ");
	scanf("%s",ID);
	if(strstr(ID,"admin")){
		return 1;
	}
	else{
		return 0;
	}
}

int user_login() {
    return 1;
}

int manager_selectMenu() {
    int menu;
    printf("\n관리자 모드\n");
    printf("1. 전체 회원 조회\n");
    printf("2. 회원 정보 추가\n");
    printf("3. 회원 정보 수정\n");
    printf("4. 회원 정보 삭제\n");
    printf("5. 회원 검색\n");
    printf("0. 로그아웃 및 저장\n\n");
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
    int i = 0;

    FILE *fp = fopen("gmp.txt", "rt");

    if (fp == NULL) {
        printf("\n=> 파일 없음\n");
        return i;
    }
    else {
        while(1) {
            u[i] = (User *)malloc(sizeof(User));
            fscanf(fp, "%s", u[i]->name);
            fscanf(fp, "%s", u[i]->ID);
            fscanf(fp, "%d", &u[i]->class_list[0]);
            fscanf(fp, "%d", &u[i]->class_list[1]);
            fscanf(fp, "%d", &u[i]->class_list[2]);
            fscanf(fp, "%d", &u[i]->day);

            if(feof(fp)) break;
            i++;
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
        
        return i;
    }
}

int addUser(User *u[], int num) {
    int flag;
    u[num] = (User *)malloc(sizeof(User));

    printf("이름은? ");
    scanf("%s", u[num]->name);
    //printf("사용자 ID는? ");
    //scanf("%s", u[num]->ID);
    while(1){
        flag = 0;
        printf("사용자 ID는? ");
        scanf("%s", u[num]->ID);
	    for(int i = 0; i < num; i++){
            if(strcmp(u[i]->ID, u[num]->ID)==0){
                printf("중복되는 ID입니다. 다시 입력해주세요.\n");
                flag=1;
                break;
            }
        }
        if (flag != 1) break;
    }
    printf("수강 중인 강좌는? (해당되는 순서에 0 또는 1을 입력하시오.)\n");
    printf("1.필라테스 2.헬스 3.PT (ex 헬스 => 0 1 0) ");
    scanf("%d %d %d", &u[num]->class_list[0], &u[num]->class_list[1], &u[num]->class_list[2]);
    if(u[num]->class_list[0] > 1 || u[num]->class_list[1] > 1 || u[num]->class_list[2] > 1){
        printf("숫자 0 또는 1로 다시 입력하시오.\n");
        return 0;
    }
    printf("남은 일수는? ");
    scanf("%d", &u[num]->day);
    
    return 1;
}

void readUser(User u) {
    char classOffered[3][40] = {"필라테스", "헬스", "PT"};
    printf("%s %3s ",u.name, u.ID);
    for (int j=0; j<3; j++) {
        if (u.class_list[j] == 1) {
            printf("%s ", classOffered[j]);
        }
    }
    printf("%3d\n", u.day);
}

void listUser(User *u[], int total) {
    printf("No Name  ID  class-list  day");
    printf("\n*********************************\n");

    for(int i=0; i<total; i++) {
        if(u[i] == NULL){
            continue;
        }
        printf("%2d ", i+1);
        readUser(*u[i]);
    }
    printf("\n");
}

void saveData(User *u[], int total) {
    FILE *fp = fopen("gmp.txt", "wt");

    for (int i=0; i<total; i++) {
        if(u[i]==NULL) {
            continue;
        }
        fprintf(fp,"%s %s %d %d %d %d\n", u[i]->name, u[i]->ID, u[i]->class_list[0], u[i]->class_list[1], u[i]->class_list[2], u[i]->day);
    }

    fclose(fp);
    printf("저장됨!\n");
}

int selectUser(User *u[],int total){
    listUser(u,total);
    int number;
    printf("\n번호는 (취소 : 0)? ");
    scanf("%d",&number);
    return number;
}

int updateUser(User *u[], int total){
    int number;
    number = selectUser(u,total);
    if(number == 0){
        return 0; // 0번 누르면 종료
    }
    printf("이름은? ");
    scanf("%s", u[number-1]->name);
    printf("사용자 ID는? ");
    scanf("%s", u[number-1]->ID);
    printf("수강 중인 강좌는? (해당되는 순서에 0 또는 1을 입력하시오.)\n");
    printf("1.필라테스 2.헬스 3.PT (ex 헬스 => 0 1 0) ");
    scanf("%d %d %d", &u[number-1]->class_list[0], &u[number-1]->class_list[1], &u[number-1]->class_list[2]);
    if(u[number-1]->class_list[0] > 1 || u[number-1]->class_list[1] > 1 || u[number-1]->class_list[2] > 1){
        printf("숫자 0 또는 1로 다시 입력하시오.\n");
        return 0;
    }
    printf("남은 일수는? ");
    scanf("%d", &u[number-1]->day);
    return 1;
}

int deleteUser(User *u[], int total){
    int number;
    int check;
    number = selectUser(u,total);
    if(number == 0){
        return 0;
    }
    else{
        printf("\n정말로 삭제하시겠습니까? (삭제 1) ");
        scanf("%d", &check);
        if(check == 1){
            free(u[number-1]);
            u[number-1] = NULL;
            return 1;
        }
        else{
            return 0;
        }
    }
}

void searchData(User *u[], int total){
    int num = 0;
    char search_name[20];

    printf("검색할 이름은? ");
    scanf("%s", search_name);

    for(int i = 0 ; i < total; i++){
        if(u[i] == NULL) continue;
        if(strstr(u[i]->name,search_name)){
            readUser(*u[i]);
            num++;
        }
    }
    if(num == 0){
        printf("=>검색된 데이터 없음");
        printf("\n");
    }
}
