#include <stdio.h>
#include <time.h>
int main(){
	struct tm *val;
time_t mytm;
mytm = time(NULL);
val = localtime(&mytm);
printf("time=%d-%d-%d  %d:%d:%d\n",val->tm_year+1900,val->tm_mon+1,val->tm_mday,val->tm_hour,val->tm_min,val->tm_sec);


return 0;
}
