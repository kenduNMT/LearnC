#include <stdio.h>
#include <string.h>
#define Max 50

typedef struct {
    int id;
    char name[Max];
    char birthday[Max];
    char address[Max];
    int status;
} SinhVien;

SinhVien studentList[100];
int studentCount = 2;
void printStudents() {
    for (int i = 0; i < studentCount; i++) {
        printf("%d %s %s %s %d\n", studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
    }
}
//Thêm mới sinh viên vào vị trí cuối cùng của studentList
void addStudent() {
    printf("Nhap thong tin sinh vien moi:\n");

    printf("Nhap id: ");
    scanf("%d", &studentList[studentCount].id);

    printf("Nhap ten: ");
    getchar();
    gets(studentList[studentCount].name);

    printf("Nhap ngay sinh: ");
    scanf("%s", studentList[studentCount].birthday);

    printf("Nhap dia chi: ");
    getchar();
    gets(studentList[studentCount].address);

    printf("Nhap trang thai: ");
    scanf("%d", &studentList[studentCount].status);

    studentCount++;
}
//Cập nhật thông tin của một sinh viên
void updateStudent() {
    char name[Max];
    printf("Nhap ten sinh vien muon chinh sua: ");
    getchar();
    gets(name);
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentList[i].name, name) == 0) {
            printf("Nhap thong tin moi cho sinh vien:\n");

            printf("Nhap id: ");
            scanf("%d", &studentList[i].id);

            printf("Nhap ten: ");
            getchar();
            gets(studentList[i].name);

            printf("Nhap ngay sinh: ");
            scanf("%s", studentList[i].birthday);

            printf("Nhap dia chi: ");
            getchar();
            gets(studentList[i].address);

            printf("Nhap trang thai: ");
            scanf("%d", &studentList[i].status);

            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay\n");
    }
}
//Xóa một sinh viên
void deleteStudent() {
    char name[Max];
    printf("Nhap ten sinh vien muon xoa: ");
    getchar();
    gets(name);
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentList[i].name, name) == 0) {
            // Xoa sinh vien bang cach dich chuyen cac sinh vien phia sau len
            for (int j = i; j < studentCount - 1; j++) {
                studentList[j] = studentList[j + 1];
            }
            studentCount--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay\n");
    }
}
//Thuật toán sắp xếp nổi bọt
void bubbleSort() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (strcmp(studentList[j].name, studentList[j + 1].name) > 0) {
                // Hoán đổi vị trí của hai sinh viên
                SinhVien temp = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = temp;
            }
        }
    }
}
//Tìm kiếm nhị phân
void searchStudent() {
    char name[Max];
    printf("Nhap ten sinh vien muon tim: ");
    getchar();
    gets(name);
    // Tim sinh vien trong danh sach
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentList[i].name, name) == 0) {
            // In thong tin sinh vien
            printf("%d %s %s %s %d\n", studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
            return;
        }
    }
    printf("Khong tim thay\n");
}
//Tìm kiếm sinh viên theo status
void searchStudentByStatus() {
    int status;
    printf("Nhap trang thai sinh vien muon tim: ");
    scanf("%d", &status);
    int found = 0;
    // Tim sinh vien trong danh sach
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].status == status) {
            // In thong tin sinh vien
            printf("%d %s %s %s %d\n", studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay\n");
    }
}

int main() {
    int choice;
    studentList[0].id = 1;
    strcpy(studentList[0].name, "Nguyen Minh Thuan");
    strcpy(studentList[0].birthday, "15/01/2005");
    strcpy(studentList[0].address, "TP Ho Chi Minh");
    studentList[0].status = 1;

    studentList[1].id = 2;
    strcpy(studentList[1].name, "Nguyen Hong Thanh Phu");
    strcpy(studentList[1].birthday, "31/12/2005");
    strcpy(studentList[1].address, "TP Ho Chi Minh");
    studentList[1].status = 1;
    do {
        printf("************************MENU**************************\n");
        printf("1. In toan bo danh sach sinh vien co o trong mang studentList tren cung mot hang\n");
        printf("2. Thuc hien chuc nang them moi sinh vien vao vi tri cuoi cung cua studentList.\n");
        printf("3. Thuc hien chuc nang cap nhat thong tin cua mot sinh vien.\n");
        printf("4. Thuc hien chuc nang xoa mot sinh vien.\n");
        printf("5. Thuc hien chuc nang sap xep (Su dung thuat toan sap xep noi bot) va in ra danh sach studentList da duoc sap xep\n");
        printf("6. Thuc hien chuc nang tim kiem (Tim kiem nhi phan) va in ra thong tin cua sinh vien (Tim kiem theo ten)\n");
        printf("7. Thuc hien chuc nang tim kiem va in ra toan bo thong tin sinh vien theo status\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang ");
        scanf("%d", &choice);

    switch (choice) {
        case 1:
            printStudents();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            bubbleSort();
            printStudents();
            break;
        case 6:
            searchStudent();
            break;
        case 7:
            searchStudentByStatus();
            break;
        case 8:
            printf("Thoat\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
    }
    } while(choice != 8);

    return 0;
}