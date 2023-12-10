#include <stdio.h>

int main() {
    int day, month;

    printf("NHap ngAy sinh: ");
    scanf_s("%d", &day);

    printf("NHap thang sinh: ");
    scanf_s("%d", &month);

    if (month == 12) {
        if (day < 22)
            printf("Nhan Ma");
        else
            printf("Ma Ket");
    } else if (month == 1) {
        if (day < 20)
            printf("Ma Ket");
        else
            printf("Bao BInh");
    } else if (month == 2) {
        if (day < 19)
            printf("Bao BInh");
        else
            printf("Song Ngu");
    } else if (month == 3) {
        if (day < 21)
            printf("Song Ngu");
        else
            printf("Bach Duong");
    } else if (month == 4) {
        if (day < 20)
            printf("Bach Duong");
        else
            printf("Kim NgUu");
    } else if (month == 5) {
        if (day < 21)
            printf("Kim NgUu");
        else
            printf("Song Tu");
    } else if (month == 6) {
        if (day < 21)
            printf("Song Tu");
        else
            printf("Cu GIai");
    } else if (month == 7) {
        if (day < 23)
            printf("Cu GIai");
        else
            printf("Su Tu");
    } else if (month == 8) {
        if (day < 23)
            printf("Su Tu");
        else
            printf("Xu Nu");
    } else if (month == 9) {
        if (day < 23)
            printf("Xu Nu");
        else
            printf("THien BInh");
    } else if (month == 10) {
        if (day < 23)
            printf("THien BInh");
        else
            printf("Bo Cap");
    } else if (month == 11) {
        if (day < 22)
            printf("Bo Cap");
        else
            printf("Nhan Ma");
    }

    return 0;
}