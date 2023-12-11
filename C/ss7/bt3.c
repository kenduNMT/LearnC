#include <stdio.h>

int main() {
    double principal, rate;
    int months;
    printf("Nhap vao so tien gui ngan hang ban dau: ");
    scanf_s("%lf", &principal);

    printf("Nhap vao lai suat nam (%%): ");
    scanf_s("%lf", &rate);

    printf("Nhap vao so thang gui: ");
    scanf_s("%d", &months);

    rate = rate / 1200;
    printf("Thang\tTien gui\tTien lai\n");
    for(int i = 1; i <= months; i++) {
        double interest = principal * rate;
        principal += interest;
        printf("%d\t%.2lf\t%.2lf\n", i, principal, interest);
    }
    return 0;
}