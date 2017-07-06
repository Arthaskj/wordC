#include <stdio.h>
int main(){
	int a,b,c;
int i,s;
s=0;
printf("请输入三个数：");
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
for(i=0;i<=100;i++)
{
if(i==a|i==b|i==c)
{
	continue;
}
   
   s=s+i;

}
printf("结果为：%d\n",s);
return 0;
}
