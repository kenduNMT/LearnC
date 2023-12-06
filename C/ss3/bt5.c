#include<stdio.h>
int main()
{
    int ngan,chuc,tram,donvi;
    printf("hang ngan");
    scanf("%d",&ngan);
    printf("hang tram");
    scanf("%d",&tram);
    printf("hang chuc");
    scanf("%d",&chuc);
    printf("hang don vi");
    scanf("%d",&donvi);
    printf("tong cac chu so:%d\n",ngan+chuc+tram+donvi);
    printf("dao cac chu so:%d%d%d%d",donvi,chuc,tram,ngan);
}