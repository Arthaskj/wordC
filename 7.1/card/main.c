#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "IC_serial.h"

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

void caijiuser(USR *user,int fd,char buf[32]){
	printf("欢迎来到新华学院，请输入你的姓名：");
	scanf("%s",user->name);
	printf("请将磁卡靠近读卡区域！\n");
	read_from_serial(fd,buf);
	strcpy(user->card,buf);
FLAG:
	printf(" ===================\n=请选择车型：       =\n=大型车 20/h===>4   =\n=中型车 15/h===>3   =\n=小型车 10/h===>2   =\n=MINI    5/h===>1   =\n ===================\n");
	scanf("%d",&user->type);
	if(user->type>4||user->type<1)
	{
		printf("输入错误，请重新输入！\n");
		goto FLAG;
	}
	return;
}

void start_time(USR *user){
time_t mytm;
struct tm *val;
mytm=time(NULL);
val=localtime(&mytm);
user->start_time.tm_year=val->tm_year+1900;
user->start_time.tm_mon=val->tm_mon+1;
user->start_time.tm_mday=val->tm_mday;
user->start_time.tm_hour=val->tm_hour;
user->start_time.tm_min=val->tm_min;
user->start_time.tm_sec=val->tm_sec;
printf("当前时间为：%d-%d-%d-  %d:%d:%d\n",val->tm_year+1900,val->tm_mon+1,
		val->tm_mday,val->tm_hour,val->tm_min,val->tm_sec);
printf("\n\n\n");
return ;
}

void end_time(USR *user,int fd,char buf[32],char bufb[32]){
time_t mytm;
struct tm *val;
mytm=time(NULL);
val=localtime(&mytm);
user->end_time.tm_year=val->tm_year+1900;
user->end_time.tm_mon=val->tm_mon+1;
user->end_time.tm_mday=val->tm_mday;
user->end_time.tm_hour=val->tm_hour;
user->end_time.tm_min=val->tm_min;
user->end_time.tm_sec=val->tm_sec;
printf("截止时间为：%d-%d-%d-  %d:%d:%d\n",val->tm_year+1900,val->tm_mon+1,
		val->tm_mday,val->tm_hour,val->tm_min,val->tm_sec);
if(bufb[32]=buf[32]){
	if(user->end_time.tm_sec-user->start_time.tm_sec>0){
		user->money =5*user->type*(user->end_time.tm_sec - user->start_time.tm_sec);}
else if(user->end_time.tm_sec-user->start_time.tm_sec<=0){
		user->money =5*user->type*(user->end_time.tm_sec - user->start_time.tm_sec+60);}
		printf("%s您好，谢谢使用停车系统，您一共消费%.1f元，欢迎下次使用！\n",user->name,user->money);
printf("\n\n\n");
}else{
printf("请刷同一张卡！");
printf("\n\n\n");
}
return;
}

void print_user(USR *user,int fd){
	printf("==============================================\n");
	printf("==================信息展示====================\n");
	printf("==============================================\n");
	printf("=   用户名：%s                                  \n",user->name);
	printf("=   卡号：%s                                      \n",user->card);
	printf("=   消费金额：%.1f                           \n",user->money);
	printf("=   车型：%d                                     \n",user->type);
	printf("==============================================\n");
	printf("==============================================\n");
printf("\n\n\n");
	return;
}
int main(int argc, const char *argv[])
{
	USR *user;
	user=userinit();
	int fd;	
	char buf[32]={0};
	char bufb[32]={0};
	open_port(&fd);
	uart_init(fd);
	for(;;){
	caijiuser(user,fd,buf);
	start_time(user);
	read_from_serial(fd,buf);
	printf("你的卡号是：%s\n",buf);
	end_time(user,fd,buf,bufb);
	print_user(user,fd);
	}
	return 0;
}
