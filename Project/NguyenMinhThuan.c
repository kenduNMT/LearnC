#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100

typedef struct {
    char maSach[6];
    char tenSach[max];
    char tacGia[max];
    char theLoai[max];
    int gia;
} book;

void menu();
void chuanHoaTenSach(char *name);
void add(book a[], int *n);
void outPut(book a[], int n);
void ghiDuLieuVaoFile(book a[], int n);
void capNhatThongTinSach(book a[], int n);
void xoaSachTheoMaSach(book a[], int *n);
void sapXepGiam(book a[], int n);
void sapXepTang(book a[], int n);
void timKiemSachTheoTacGia(book a[], int n);
void timKiemSachTheoKhoangGia(book a[], int n);
void xoaDuLieu();
int main() {
    int choice, n = 0;
    book a[max];
    do {
        menu();
        printf("chuc nang ban muon chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add(a, &n);
                ghiDuLieuVaoFile(a, n);
                break;
            case 2:
                capNhatThongTinSach(a, n);
                break;
            case 3:
                xoaSachTheoMaSach(a, &n);
                break;
            case 4:
                outPut(a, n);
                break;
            case 5:
                sapXepGiam(a,n);
                break;
            case 6:
                sapXepTang(a, n);
                break;
            case 7:
                timKiemSachTheoTacGia(a, n);
                break;
            case 8:
                timKiemSachTheoKhoangGia(a,n);
                break;
            case 9:
                xoaDuLieu();
                break;
            case 10:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Chon chuc nang khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 10);
    return 0;
}

void menu() {
    printf("\n===== Book Management System =====\n");
    printf("1. Them sach moi\n");
    printf("2. Sua thong tin sach\n");
    printf("3. Xoa thong tin sach\n");
    printf("4. Hien thi tat ca sach\n");
    printf("5. Sap xep theo gia sach(tang)\n");
    printf("6. Sap xep theo gia sach (giam)\n");
    printf("7. Tim kiem sach theo tac gia\n");
    printf("8. Tim kiem sach theo khoang gia\n");
    printf("9. Xoa du lieu trong file book.txt\n");
    printf("10. Thoat\n ");
}

void chuanHoaTenSach(char *name) {
        int in_word = 0;
        for (int i = 0; name[i]; i++) {
            //kiểm tra alphabet
            if (isalpha(name[i])) {
                if (!in_word) {
                    // Chuyển thành chữ hoa
                    name[i] = toupper(name[i]);
                    in_word = 1;
                } else {
                    // Chuyển thành chữ thường
                    name[i] = tolower(name[i]);
                }
                //kiểm tra khoảng trắng
            } else if (isspace(name[i])) {
                in_word = 0;
            } else {
                //Xóa kí tự đặc biệt thành khoảng trắng
                memmove(&name[i], &name[i + 1], strlen(name) - i);
                i--;
            }
        }
    }

//%..s có nghĩa là căn lề trái và chiều rộng tối thiểu của trường là .. ký tự.
void ghiDuLieuVaoFile(book a[], int n) {
    FILE *fp = fopen("book.txt", "w");
    if (fp != NULL) {
        fprintf(fp,"\n| %-10s | %-18s | %-13s | %-13s | %-13s |\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
        for (int i = 0; i < n; i++) {
            fprintf(fp,"| %-10s | %-18s | %-13s | %-13d | %-13s |\n",
                    a[i].maSach,
                    a[i].tenSach,
                    a[i].tacGia,
                    a[i].gia,
                    a[i].theLoai);
        }
        fclose(fp);
    }
}
//Hàm thêm sách
void add(book a[], int *n) {
    int continueAdding = 1;
    for (; continueAdding == 1; (*n)++) {
        printf("Nhap vao thong tin sach:\n");
        do {
            printf("Nhap ma sach (5 ky tu): ");
            scanf("%s", a[*n].maSach);
            if (strlen(a[*n].maSach) != 5) {
                printf("Ma sach phai co 5 ky tu. Vui long nhap lai.\n");
            }
        } while (strlen(a[*n].maSach) != 5);
        // Thêm tên sách
        do {
            printf("Nhap ten sach (it nhat 10 ky tu, khong chua ky tu dac biet): ");
            scanf(" %[^\n]s", a[*n].tenSach);
            if (strlen(a[*n].tenSach) < 10 || strpbrk(a[*n].tenSach, "!@#$%^&*()") != NULL) {
                printf("Ten sach phai co it nhat 10 ky tu va khong chua ky tu dac biet. Vui long nhap lai.\n");
            }
        } while (strlen(a[*n].tenSach) < 10 || strpbrk(a[*n].tenSach, "!@#$%^&*()") != NULL);

        chuanHoaTenSach(a[*n].tenSach);
        // Thêm tác giả
        printf("Nhap ten tac gia: ");
        scanf(" %[^\n]s", a[*n].tacGia);

        // Thêm giá sách
        do {
            printf("Nhap gia sach (>= 1000): ");
            scanf("%d", &(a[*n].gia));
            if (a[*n].gia < 1000) {
                printf("Gia sach phai lon hon hoac bang 1000. Vui long nhap lai.\n");
            }
        } while (a[*n].gia < 1000);

        // Thêm thể loại sách
        printf("Nhap the loai sach: ");
        scanf(" %[^\n]s", a[*n].theLoai);

        // Ghi dữ liệu vào file sau mỗi lần thêm sách

        printf("Ban co muon tiep tuc them sach? (1: Co, So khac 1: Khong): ");
        //Lưu ý phải nhập số
        scanf("%d", &continueAdding);
        // Loại bỏ ký tự '\n' thừa trong book
        getchar();
    }
}

//Hàm hiển thị trên terminal
void outPut(book a[], int n) {
    printf("%-20s%-20s%-20s%-20s%-10s\n", "Ma sach", "Ten sach", "Tac gia", "Gia", "The loai");
    for (int i = 0; i < n; ++i) {
        printf("%-20s%-20s%-20s%-20d%-10s\n", a[i].maSach, a[i].tenSach, a[i].tacGia, a[i].gia, a[i].theLoai);
    }
}

void capNhatThongTinSach(book a[], int n) {
    char maSach[6];
    printf("Nhap ma sach can cap nhat: ");
    // Dùng để xóa bộ đệm đầu vào, loại bỏ bất kỳ ký tự thừa nào từ lần nhập trước.
    fflush(stdin);
    fgets(maSach, sizeof(maSach), stdin);
    maSach[strcspn(maSach, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].maSach, maSach) == 0) {
            printf("Nhap thong tin sach moi:\n");
            fflush(stdin);
            do {
                printf("Ten Sach (10 ky tu tro len): ");
                fflush(stdin);
                fgets(a[i].tenSach, sizeof(a[i].tenSach), stdin);
                a[i].tenSach[strcspn(a[i].tenSach, "\n")] = '\0';
            } while (strlen(a[i].tenSach) < 10);
            chuanHoaTenSach(a[i].tenSach);
            printf("Tac gia: ");
            fflush(stdin);
            fgets(a[i].tacGia, sizeof(a[i].tacGia), stdin);
            a[i].tacGia[strcspn(a[i].tacGia, "\n")] = '\0';
            chuanHoaTenSach(a[i].tacGia);
            printf("The loai: ");
            fflush(stdin);
            fgets(a[i].theLoai, sizeof(a[i].theLoai), stdin);
            a[i].theLoai[strcspn(a[i].theLoai, "\n")] = '\0';
            chuanHoaTenSach(a[i].theLoai);
            do {
                printf("Gia Sach (>= 1000): ");
                scanf("%d", &a[i].gia);
                // Loại bỏ ký tự '\n' thừa trong maSach
                getchar();
            } while (a[i].gia < 1000);


            printf("Cap nhat thong tin sach thanh cong!\n");
            ghiDuLieuVaoFile(a, n);
            return;
        }
    }
    printf("Khong tim thay sach voi ma sach da nhap!\n");
}

void sapXepGiam(book a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j].gia < a[j+1].gia) {
                book temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    outPut(a,n);
}

void xoaSachTheoMaSach(book a[], int *n) {
    char maSach[6];
    printf("Nhap ma sach can xoa: ");
    fflush(stdin);
    fgets(maSach, sizeof(maSach), stdin);
    //Loại bỏ ký tự xuống dòng từ mã sách và trả về vị trí của ký tự xuống dòng đầu tiên trong maSach
    maSach[strcspn(maSach, "\n")] = '\0';

    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(a[i].maSach, maSach) == 0) {
            break;
        }
    }
//Hàm kiểm tra mã sách va xóa
    if (i != *n) {
        for (int j = i; j < *n - 1; j++) {
            a[j] = a[j + 1];
        }
        (*n)--;
        printf("Da xoa sach co ma %s\n", maSach);
        ghiDuLieuVaoFile(a, *n);
    } else {
        printf("Khong tim thay sach voi ma sach da nhap!\n");
    }
}

void sapXepTang(book a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j].gia > a[j+1].gia) {
                book temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    outPut(a,n);
}

void timKiemSachTheoTacGia(book a[], int n) {
    char tacgia[max];
    printf("Nhap ten tac gia can tim kiem: ");
    scanf(" %[^\n]", tacgia);

    int found = 0;
    printf("\nKet qua tim kiem theo tac gia '%s':\n", tacgia);
    for (int i = 0; i < n; i++) {
        // kiểm tra tên tác giả nhập vào
        if (strstr(a[i].tacGia, tacgia) != NULL) {
            printf("%s | %s | %s | %d | %s\n", a[i].maSach, a[i].tenSach,
                   a[i].tacGia, a[i].gia, a[i].theLoai);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach cua tac gia '%s'\n", tacgia);
    }
}

void timKiemSachTheoKhoangGia(book a[], int n) {
    int giaMin, giaMax;
    printf("Nhap gia thap nhat: ");
    scanf("%d", &giaMin);
    printf("Nhap gia cao nhat: ");
    scanf("%d", &giaMax);

    int check = 0;
    printf("\nKet qua tim kiem trong khoang gia %d-%d:\n", giaMin, giaMax);
    for (int i = 0; i < n; ++i) {
        if (a[i].gia >= giaMin && a[i].gia <= giaMax) {
            printf("%s | %s | %s | %d | %s\n", a[i].maSach, a[i].tenSach,
                   a[i].tacGia, a[i].gia, a[i].theLoai);
            check = 1;
        }
    }

    if (!check) {
        printf("Trong khoang gia nay khong tim thay sach nao!!!\n");
    }
}
void xoaDuLieu() {
    FILE *file = fopen("book.txt", "w");

    if (file != NULL) {
        fclose(file);
        printf("Da xoa du lieu trong file book.txt.\n");
    } else {
        printf("Khong the mo file de xoa du lieu.\n");
    }
}
