#include <stdio.h>
#include <ctype.h>
#include <string.h>

void chuanHoa(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (i == 0 || str[i - 1] == ' ') {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}
void xoaKhoangTrangThua(char* str) {
    int n = strlen(str);
    int j = 0;
    for (int i = 0; i <= n; i++) {
        if (!(str[i] == ' ' && str[i+1] == ' ')) {
            str[j++] = str[i];
        }
    }
}
int main() {
    FILE *fi = fopen("sinhvien.txt", "r");
    FILE *fo = fopen("sinhvien_out.txt", "w");
    int n;
    if(fi ==NULL) {
        printf("file not open!\n");
        return-1;
    }
    fscanf(fi, "%d\n", &n);
    fprintf(fo, "%d\n", n);
    for (int i = 0; i < n; i++) {
        char str[100];
        fgets(str, sizeof(str), fi);
        chuanHoa(str);
        xoaKhoangTrangThua(str);
        fputs(str, fo);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}