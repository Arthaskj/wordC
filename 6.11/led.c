#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <sys/ioctl.h>

#define LED_MAGIC 'k'
#define LED_ON _IO(LED_MAGIC,0) 
#define LED_OFF _IO(LED_MAGIC,1)

int main(){
	int fd;
	int ledno;
fd = open("/dev/led",O_RDWR);
if(fd<0)
{
printf("open fail");
exit(-1);
}
ledno=1;
ioctl(fd,LED_ON,ledno);
sleep(1);
ioctl(fd,LED_OFF,ledno);
close(fd);


return 0;
}
