#include <stdio.h>
#define MAX_LEN 100

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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
        printf("2. Su dung Insertion Sort sap xep mang giam dan va in ra\n");
        printf("3. Su dung Selection Sort sap xep mang giam dan va in ra\n");
        printf("4. Su dung Bubble Sort sap xep mang giam dan va in ra\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printArray(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                printf("Mang sau khi sap xep giam dan bang Insertion Sort:\n");
                printArray(arr, n);
                break;
            case 3:
                selectionSort(arr, n);
                printf("Mang sau khi sap xep giam dan bang Selection Sort:\n");
                printArray(arr, n);
                break;
            case 4:
                bubbleSort(arr, n);
                printf("Mang sau khi sap xep giam dan bang Bubble Sort:\n");
                printArray(arr, n);
                break;
            case 5:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 5);
    return 0;
}