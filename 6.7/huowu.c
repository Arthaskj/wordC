#include <stdio.h>

int main(){
float weight;
float price;
float distance;
float freight;
printf("请输入货物总重量：");
scanf("%f",&weight);
printf("请输入货物路程：");
scanf("%f",&distance);
printf("请输入货物每吨*千米单价：");
scanf("%f",&price);
if(distance<250)
{
	freight=weight*distance*price;
printf("总费用为：%.1f\n",freight);
}
else if(distance<500&&distance>=250)
{
	freight=weight*distance*price*(1-0.02);
printf("总费用为：%.1f\n",freight);
}

else if(distance<1000&&distance>=500)
{
	freight=weight*distance*price*(1-0.05);
printf("总费用为：%.1f\n",freight);
}
else if(distance<2000&&distance>=1000)
{
	freight=weight*distance*price*(1-0.08);
printf("总费用为：%.1f\n",freight);
}

else if(distance<3000&&distance>=2000)
{
	freight=weight*distance*price*(1-0.1);
printf("总费用为：%.1f\n",freight);
}

else if(distance>=3000)
{
	freight=weight*distance*price*(1-0.15);
printf("总费用为：%.1f\n",freight);
}
return 0;
}
