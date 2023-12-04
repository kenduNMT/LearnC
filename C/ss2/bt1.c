#include <stdio.h>
int main()
{
    float e,w,l,r,Pi=3.14;
    printf("canh la:");
    scanf("%f",&e);
    printf("chieu rong la:");
    scanf("%f",&w);
    printf("chieu dai la:");
    scanf("%f",&l);
    printf("ban kinh la:");
    scanf("%f",&r);
    printf("dien tich hinh vuong la:%f - chu vi hinh vuong la:%f\n",e*e,e*4);
    printf("dien tich hinh chu nhat:%f - chu vi hinh chu nhat:%f\n",w*l,(w+l)*2);
    printf("dien tich hinh tron:%f - chu vi hinh tron:%f",Pi*r*r,2*Pi*r);
}