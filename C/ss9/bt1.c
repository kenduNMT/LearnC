#include<stdio.h>


int a[100];
int n,sum;
int main(){
    while(1) {
        printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2.In ra gia tri cac phan tu dang quan ly\n");
        printf("3.In ra gia tri cac phan tu chan va tinh tong\n");

        int chucNang;
        printf("chon: ");
        scanf_s("%d", &chucNang);
        switch (chucNang) {
            case 1:
                printf("Nhap so phan tu can nhap: ");
                scanf_s("%d", &n);

                for (int i = 0; i < n; i++) {
                    printf("nhap gia tri phan tu thu %d: ", i);
                    scanf_s("%d", &a[i]);
                }
                break;
            case 2:
                if (n == 0) {
                    printf("khong gia tri\n");
                } else {
                    printf("\ngia tri cac phan tu dang quan ly: \n");
                    for (int i = 0; i < n; i++) {
                        printf("%d\n",a[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                sum = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] % 2 == 0) {
                        printf("so chan: %d\n ", a[i]);
                        sum += a[i];
                        printf("\n");
                    }
                }
                printf("tong so chan: %d\n ", sum);
                break;
            default:
                printf("Lua chon khong hop le");
        }

        return 0;
    }
        }