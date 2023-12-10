#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 9; ++i) {
        printf("Bang cuu chuong cua :");
        scanf_s("%d",&i);
        for (j = 1; j <= 10; ++j) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }

    return 0;
}