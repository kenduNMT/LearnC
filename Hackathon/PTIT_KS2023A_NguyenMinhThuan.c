#include <stdio.h>
#define MAX 100
// Hàm kiểm tra số nguyên tố
int isPrime(int n) {
    if(n <= 1) return 0;
    if(n <= 3) return 1;

    if(n % 2 == 0 || n % 3 == 0) return 0;

    for(int i = 5; i * i <= n; i += 6)
        if(n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}
// Hàm để hoán đổi hai phần tử
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Hàm sắp xếp lựa chọn cho mảng hai chiều theo cột
void selectionSort(int arr[][100], int n, int m) {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n-1; i++) {
            // Tìm phần tử nhỏ nhất trong cột j từ hàng i đến n
            int min_idx = i;
            for (int k = i+1; k < n; k++)
                if (arr[k][j] < arr[min_idx][j])
                    min_idx = k;
            // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên
            swap(&arr[min_idx][j], &arr[i][j]);
        }
    }
}
// Hàm sắp xếp nổi bọt cho đường chéo chính của mảng hai chiều
void bubbleSort(int arr[][100], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j][j] < arr[j+1][j+1]) {
                swap(&arr[j][j], &arr[j+1][j+1]);
            }
        }
    }
}
void nhapMang(int arr[][100], int n, int m) {
    printf("Nhap gia tri cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
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
void chenMang1ChieuVaoMang2Chieu(int arr1[], int n, int arr2[][100], int m, int col) {
    printf("Nhap gia tri cua mang 1 chieu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Nhap chi so cot muon chen vao mang 2 chieu: ");
    scanf("%d", &col);
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= col; j--) {
            arr2[i][j + 1] = arr2[i][j];
        }
        arr2[i][col] = arr1[i];
    }
    printf("Mang 2 chieu sau khi chen mang 1 chieu:\n");
    inMang(arr2, n, m + 1);
}
int countPrimes(int arr[][100], int n, int m) {
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] % 2 == 0 && arr[i][j] % 3 == 0)
                count++;
    printf("%d\n", count);
}
int main() {
    int arr[100][100];
    int n, m, choice, arr1[100], col;
    printf("Nhap so cot: ");
    scanf("%d", &n);
    printf("Nhap so hang: ");
    scanf("%d", &m);
    do {
        printf("************************MENU**************************\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
        printf("3. Tinh so luong cac phan tu chia het cho 2 va 3 trong mang\n");
        printf("4. In cac phan tu va tong cac phan ta nam tren duong bien, duong cheo chinh va duong cheo phu\n");
        printf("5. Su dung thuat toan sap xep lua chon sap xep cac phan tu tang dan theo cot cua mang\n");
        printf("6. In ra cac phan tu la so nguyen to trong mang\n");
        printf("7. Su dung thuat toan noi bot sap xep cac phan tu tren duong cheo chinh cua mang giam dan\n");
        printf("8. Nhap gia tri mot mang 1 chieu gom m phan tu va chi so dong muon chen vao mang, thuc hien chen vao mang 2 chieu\n");
        printf("9. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, n, m);
                break;
            case 2:
                inMang(arr, n, m);
                break;
            case 3:
                printf("So luong cac phan tu chia het cho 2 va 3 trong mang: %d\n",countPrimes(arr,n,m));
                break;
            case 4:
                printf("Cac phan tu và tong cac phan ta nam tren duong bien, duong cheo chinh va duong cheo phu:\n");
                int sum = 0;
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                        if(i == 0 || i == n-1 || j == 0 || j == m-1 || i == j || i + j == m - 1) {
                            printf("%d ", arr[i][j]);
                            sum += arr[i][j];
                        }
                printf("\nTong: %d\n", sum);
                break;
            case 5:
                printf("Sap xep cac phan tu tang dan theo cot cua mang:\n");
                selectionSort(arr, n, m);
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++)
                        printf("%d ", arr[i][j]);
                    printf("\n");
                }
                break;
            case 6:
                printf("Cac phan tu la so nguyen to trong mang:\n");
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                        if(isPrime(arr[i][j]))
                            printf("%d ", arr[i][j]);
                printf("\n");
                break;
            case 7:
                printf("Sap xep cac phan tu tren duong cheo chinh cua mang giam dan:\n");
                bubbleSort(arr, n);
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++)
                        printf("%d ", arr[i][j]);
                    printf("\n");
                }
                break;
            case 8:
                chenMang1ChieuVaoMang2Chieu(arr1, n, arr, m, col);
                break;
            case 9:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while(choice != 9);

    return 0;
}