#include<stdio.h>
int main()
{
    float math,Literature,English;
    printf("toan");
    scanf("%f",&math);
    printf("van");
    scanf("%f",&Literature);
    printf("anh");
    scanf("%f",&English);
    printf("tong diem:%.2f\n",math+Literature+English);
    printf("diem trung binh:%.2f",(math+Literature+English)/2);
}