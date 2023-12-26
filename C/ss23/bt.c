#include <stdio.h>

typedef struct {
    char name[50];
    int income;
    int population;
    float literacyRate;
} ThanhPho;
int main() {
    int n;
    printf("Nhap so thanh pho: ");
    scanf("%d", &n);
    ThanhPho cities[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap chi tiet thanh pho thu %d:\n", i);
        printf("Nhap ten thanh pho: ");
        scanf("%s", cities[i].name);
        printf("Nhap tong so dan: ");
        scanf("%d", &cities[i].population);
        printf("Nhap ti le biet doc viet: ");
        scanf("%f", &cities[i].literacyRate);
        printf("Nhap tong thu nhap: ");
        scanf("%d", &cities[i].income);
    }
    int tongThuNhap = 0;
    int hocVan = 0;
    for (int i = 1; i < n; i++) {
        if (cities[i].income > cities[tongThuNhap].income) {
            tongThuNhap = i;
        }
        if (cities[i].literacyRate > cities[hocVan].literacyRate) {
            hocVan = i;
        }
    }
    printf("Thanh pho co ti le biet doc viet cao nhat: %s\n", cities[hocVan].name);
    printf("Thanh pho co tong thu nhap cao nhat: %s\n", cities[tongThuNhap].name);
    return 0;
}