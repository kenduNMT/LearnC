#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int decimal = 0;
    int base = 1;
    int temp = n;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        decimal += last_digit * base;
        base = base * 2;
    }
    int octal = 0;
    base = 1;
    temp = decimal;
    while (temp) {
        int last_digit = temp % 8;
        temp = temp / 8;
        octal += last_digit * base;
        base = base * 10;
    }
    printf("OUTPUT:");
    printf("%d", octal);

    return 0;
}