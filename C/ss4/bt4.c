#include <stdio.h>
int main(){
    int year,month;
    printf("nhap nam: ");
    scanf_s("%d",&year);
    printf("nhap thang: ");
    scanf_s("%d",&month);
    switch (month){
        case 4:
            printf("30 ngay");
            break;
        case 6:
            printf("30 ngay");
            break;
        case 9:
            printf("30 ngay");
            break;
        case 11:
            printf("30 ngay");
            break;
        case 1:
            printf("31 ngay");
            break;
        case 3:
            printf("31 ngay");
            break;
        case 5:
            printf("31 ngay");
            break;
        case 7:
            printf("31 ngay");
            break;
            case 8:
            printf("31 ngay");
            break;
        case 10:
            printf("31 ngay");
            break;
        case 12:
            printf("31 ngay");
            break;
        case 2:
            if(year%4==0){
                printf("nam nhuan co 29 ngay");
            }else {
                printf("nam khong nhuan co 28 ngay");
            }break;
        default:
            printf("chi nhap 1->12");
    }
}