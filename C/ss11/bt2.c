#include <stdio.h>
#define MAX_LEN 100

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void inMang(int arr[][100], int n, int m) {
    printf("Gia tri cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int arr[MAX_LEN][MAX_LEN];
    int m, n;
    printf("Nhap so cot: ");
    scanf("%d", &n);
    printf("Nhap so hang: ");
    scanf("%d", &m);

    printf("Nhap gia tri cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. In gia tri mang theo ma tran\n");
        printf("2. Sap xep mang co gia tri cac phan tu theo dong tang dan\n");
        printf("3. Sap xep mang co gia tri cac phan tu theo cot giam dan\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inMang(arr, n, m);
                break;
            case 2:
                for (int i = 0; i < m; i++) {
                    insertionSort(arr[i], n);
                }
                printf("Mang sau khi sap xep theo dong tang dan:\n");
                inMang(arr, n, m);
                break;
            case 3:
                for (int j = 0; j < n; j++) {
                    int col[MAX_LEN];
                    for (int i = 0; i < m; i++) {
                        col[i] = arr[i][j];
                    }
                    insertionSort(col, m);
                    for (int i = 0; i < m; i++) {
                        arr[i][j] = col[i];
                    }
                }
                printf("Mang sau khi sap xep theo cot giam dan:\n");
                inMang(arr, n, m);
                break;
            case 4:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 4);
    return 0;
}