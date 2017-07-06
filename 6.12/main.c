#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>


#define NUM 20

typedef struct student{
char name[NUM];
char card[NUM];
int type;
float money;
struct tm start_time;
struct tm end_time;
}USR;

USR *userinit()
{
	USR *p;
	p=(USR *)malloc(sizeof(USR));
	if(p==NULL)
	{
	perror("malloc fail");
	exit(-1);
	}
	return p;
}

int main(int argc, const char *argv[])
{
	USR *user;
	user=userinit();
	user->start_time.tm_hour=10;	
	int flage=1;
//	if(flage==1){

	printf("请输入你的姓名：");
	scanf("%s",user->name);
	printf(" ===================\n=请选择车型：       =\n=大型车 20/h===>4   =\n=中型车 15/h===>3   =\n=小型车 10/h===>2   =\n=MINI    5/h===>1   =\n ===================\n");
	scanf("%d",&user->type);
	flage=0;
//	}
//	else{
		user->end_time.tm_hour=20;	
		user->money = 5*user->type*(user->end_time.tm_hour - user->start_time.tm_hour);
		flage=1;
//}
		printf("%s您好，谢谢使用停车系统，您一共消费%.1f元，欢迎下次使用！\n",user->name,user->money);
	return 0;
}
