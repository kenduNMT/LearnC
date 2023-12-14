#include<stdio.h>

int main() {
    int m,n,sum;
    printf("nhap gia tri m: ");
    scanf_s("%d",&m);
    printf("nhap gia tri n: ");
    scanf_s("%d",&n);
    int a[m][n];
    while (1) {
        printf("1.Nhap gia tri cac phan tu cua mang\n");
        printf("2.In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3.In gia tri cac phan tu la le va tinh tong\n");

        int chucNang;
        printf("chon: ");
        scanf_s("%d", &chucNang);
        switch (chucNang) {
            case 1:
                for(int i=0;i<m;i++) {
                    for (int j = 0; j < n; j++) {
                        printf("nhap gia tri cua phan tu hang %d cot %d: ", i, j);
                        scanf_s("%d", &a[i][j]);
                    }
                }
                break;
            case 2:
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        printf("%d  ",a[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                sum = 0;
                for (int i = 0; i < m; i++) {
                    for(int j=0;j<n;j++) {
                        if (a[i][j] % 2 != 0) {
                            printf("so le: %d\n ", a[i][j]);
                            sum += a[i][j];
                            printf("\n");
                        }
                    }
                }
                printf("tong so le: %d\n ", sum);
                break;
            default:
                printf("Lua chon khong hop le");
        }

        return 0;
    }
        }