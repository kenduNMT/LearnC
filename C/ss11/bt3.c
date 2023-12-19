#include <stdio.h>
#define MAX_LEN 100
int linearSearch(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
int binarySearch(int* arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[MAX_LEN];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. In gia tri cac phan tu cua mang\n");
        printf("2. Nhap gia tri tim kiem va su dung thuat toan tim kiem tuyen tinh tim tat ca cac phan tu trong mang co gia tri bang gia tri tim kiem\n");
        printf("3. Nhap gia tri tim kiem va su dung thuat toan tim kiem nhi phan tim phan tu trong mang\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printArray(arr, n);
                break;
            case 2:
                printf("Nhap gia tri tim kiwm: ");
                int x;
                scanf("%d", &x);
                int result = linearSearch(arr, n, x);
                if (result == -1) {
                    printf("Phan tu khong ton tai trong mang.\n");
                } else {
                    printf("Phan tu tim thay tai vi tri: %d\n", result);
                }
                break;
            case 3:
                printf("Nhap gia tri tim kiem: ");
                scanf("%d", &x);
                result = binarySearch(arr, 0, n - 1, x);
                if (result == -1) {
                    printf("Phan tu khong ton tai trong mang.\n");
                } else {
                    printf("Phan tu tim thay tai vi tri: %d\n", result);
                }
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
