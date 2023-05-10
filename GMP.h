typedef struct{
    char name[20];
    char ID[20];
    int class_list[3];
    int day;
}User;

int first_selectMenu();   // 관리자 모드와 사용자모드 구분
int manager_selectMenu(); // 관리자 모드 메뉴
int User_SelectMenu();    // 사용자 모드 메뉴
int loadData(User *u[]);  // 관리자 모드와 사용자 메뉴 시작하면 호출
int addUser(User *u[],int num); // 신규 회원 추가(only 관리자)
void readUser(User *u[], int total); // 전체 회원 정보 조회(only 관리자)
int selectUser(User *u[],int total); // 원하는 사용자 선택
int updateUser(User *u[], int total); // 회원 정보 수정 (관리자 and 사용자)
int deleteUser(User *u[], int total); // 회원 삭제 (only 관리자)
void saveData(User *u[], int total);  // 회원 정보 파일에 저장 (관리자 and 사용자)
void searchData(User *u[], int total); // 회원 검색 (only 관리자)
void readOneUser(User *u[], int num); // 한명의 회원 정보만 보여줌
int addClass(User *u[], int total); // 수업 신청(only 사용자)
