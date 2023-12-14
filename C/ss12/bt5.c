#include <stdio.h>

int la_so_nguyen_to(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    printf("Nhap so hang n: ");
    scanf_s("%d", &n);
    printf("Nhap so cot m: ");
    scanf_s("%d", &m);
    int arr[n][m];
    int choice;
    do {
        printf("MENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("Nhap phan tu arr[%d][%d]: ", i, j);
                        scanf_s("%d", &arr[i][j]);
                    }
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("%d %d\n", arr[0][0], arr[0][m-1]);
                printf("%d %d\n", arr[n-1][0], arr[n-1][m-1]);
                break;
            case 4:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                            printf("%d ", arr[i][j]);
                        } else {
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 5:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == j || i + j == n - 1) {
                            printf("%d ", arr[i][j]);
                        } else {
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 6:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (la_so_nguyen_to(arr[i][j])) {
                            printf("%d ", arr[i][j]);
                        } else {
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 7:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
