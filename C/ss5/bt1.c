#include <math.h>
#include <stdio.h>

int main() {
    double a, b, c, discriminant, x1, x2, realPart, imagPart;

    printf("Nhap cac he so a b c: ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    // điều kiện cho hai nghiệm thực và khác nhau
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("Nghiem thu nhat = %.2lf va nghiem thu hai = %.2lf", x1, x2);
    }

        // điều kiện cho hai nghiệm thực và bằng nhau
    else if (discriminant == 0) {
        x1 = x2 = -b / (2 * a);

        printf("Nghiem thứ nhat = nghiem thu hai = %.2lf;", x1);
    }

        // nếu không có nghiệm thực
    else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);

        printf("Nghiem thu nhat = %.2lf+%.2lfi va nghiem thu hai = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
    }

    return 0;
}