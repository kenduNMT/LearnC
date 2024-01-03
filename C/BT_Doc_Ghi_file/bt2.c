#include <stdio.h>


typedef struct {
    char ten[50];
    char lop[50];
    char ngaySinh[50];
    double gpa;
} SinhVien;

void selectionSort(SinhVien* danhSachSV, int n) {
    for (int i = 0; i < n-1; i++) {
        int maxIndex = i;
        for (int j = i+1; j < n; j++) {
            if (danhSachSV[j].gpa > danhSachSV[maxIndex].gpa) {
                maxIndex = j;
            }
        }
        // Hoán đổi sinh viên có GPA lớn nhất với sinh viên đầu dãy
        SinhVien temp = danhSachSV[maxIndex];
        danhSachSV[maxIndex] = danhSachSV[i];
        danhSachSV[i] = temp;
    }
}

int main() {
    FILE* fileIn = fopen("sinhvien.txt", "r");
    FILE* fileOut = fopen("sinhvien_out.txt", "w");
    SinhVien danhSachSV[100];
    int n = 0;

    while (!feof(fileIn)) {
        fscanf(fileIn, "%[^,],%[^,],%[^,],%lf\n", danhSachSV[n].ten, danhSachSV[n].lop, danhSachSV[n].ngaySinh, &danhSachSV[n].gpa);
        n++;
    }

    selectionSort(danhSachSV, n);

    for (int i = 0; i < n; i++) {
        fprintf(fileOut, "%s,%s,%s,%.1lf\n", danhSachSV[i].ten, danhSachSV[i].lop, danhSachSV[i].ngaySinh, danhSachSV[i].gpa);
    }

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}