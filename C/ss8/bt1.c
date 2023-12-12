#include <stdio.h>

int main() {
    int n, i;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);
    int arry[n];

    printf("Nhap gia tri cac phan tu cua mang: ");
    for(i = 0; i < n; i++) {
        scanf_s("%d", &arry[i]);
    }

    int max = arry[0];
    int min = arry[0];

    for(i = 1; i < n; i++) {
        if(arry[i] > max) {
            max = arry[i];
        }
        if(arry[i] < min) {
            min = arry[i];
        }
    }

    printf("Gia tri lon nhat trong mang la: %d\n", max);
    printf("Gia tri nho nhat trong mang la: %d\n", min);

    return 0;
}
