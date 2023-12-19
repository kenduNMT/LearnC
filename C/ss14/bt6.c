#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = temp;
    }
}
int main() {
    char str[MAX_LEN], str2[MAX_LEN];
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Sao chep chuoi vao mot chuoi khac\n");
        printf("4. Nhap vao chuoi khac, tien hanh them chuoi do vao chuoi ban dau\n");
        printf("5. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("6. In ra chuoi dao nguoc\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap vao chuoi: ");
                scanf("%s", str);
                break;
            case 2:
                printf("Chuoi cua ban: %s\n", str);
                break;
            case 3:
                strcpy(str2, str);
                printf("Chuoi sau khi sao chwp: %s\n", str2);
                break;
            case 4:
                printf("Nhap vao chuoi khac: ");
                scanf("%s", str2);
                strcat(str, str2);
                printf("Chuoi sau khi them: %s\n", str);
                break;
            case 5:
                printf("Nhap vao chuoi khac: ");
                scanf("%s", str2);
                if (strcmp(str, str2) == 0)
                    printf("Chuoi giong nhau.\n");
                else
                    printf("Chuoi khac nhau.\n");
                break;
            case 6:
                reverse(str);
                printf("Chuoi dao nguoc: %s\n", str);
                break;
            case 7:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);
    return 0;
}