#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
  #include <stdlib.h>

int main()
{
int fd,sd;
char buf[128]={0};
ssize_t ret;
ssize_t rett;
fd=open("./newfile1",O_RDWR|O_CREAT|O_APPEND,0644);
sd=open("./newfile2",O_RDWR|O_CREAT|O_APPEND,0644);
if(fd<0){
printf("open fail\n");
exit(-1);
}
while(1){

rett=read(sd,buf,sizeof(buf));

if(rett>0){
ret=write(fd,buf,rett);
}
else
{
break;
}
}
close(sd);
close(fd);
return 0;
}
