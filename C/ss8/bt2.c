#include <stdio.h>

int main() {
    int row, col;
    printf("Nhap so hang: ");
    scanf_s("%d", &row);
    printf("Nhap so cot: ");
    scanf_s("%d", &col);

    float arr[row][col];
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            scanf_s("%f", &arr[i][j]);
        }
    }

    float sum = 0;
    printf("Cac phan tu co gia tri chan: ");
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if((int)arr[i][j] % 2 == 0) {
                printf("%.2f ", arr[i][j]);
                sum += arr[i][j];
            }
        }
    }

    printf("\nTong cac phan tu co gia tri chan trong mang la: %.2f\n", sum);

    return 0;
}