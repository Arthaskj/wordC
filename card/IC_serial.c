#include "IC_serial.h"

void open_port(int *fd)
{
	*fd = open(NAME_SERIAL, O_RDWR | O_NOCTTY | O_NDELAY);
	if(*fd < 0)
	{
		perror("open_port error:");
		exit(0);
	}
	//set fd is 阻塞
	fcntl(*fd, F_SETFL, 0);


}

void uart_init(int fd)
{
#if 1	
	struct termios opt, opt_old;
	int ret;
	ret = tcgetattr(fd, &opt_old);
	if(ret != 0)
	{
		perror("tcgetattr error:");
	}
	//设置本地模式
	bzero(&opt, sizeof(opt));
	opt.c_cflag |= (CLOCAL | CREAD);
	opt.c_cflag &= ~CSIZE;

	cfsetispeed(&opt, 9600);
	cfsetospeed(&opt, 9600);
	
	//设置数据位数
	opt.c_cflag |= CS8;

	//校验
	opt.c_cflag &= ~PARENB;
	opt.c_cflag &= ~INPCK;

	//设置停止位
	opt.c_cflag &= ~CSTOPB;

	opt.c_cc[VTIME] = 0;
	opt.c_cc[VMIN] = 13;
	tcflush(fd, TCIFLUSH);
	ret = tcsetattr(fd, TCSANOW, &opt);
	if(ret != 0)
	{
		perror("tcgetattr error:");
	}
#endif
}

void read_from_serial(int fd, unsigned char *buf)
{
	char buf_temp[20];
	int i, j = 0;
	read(fd, buf_temp, 20);
	for(i = 0; i < 20; i++)
	{
		if(buf_temp[i] <= '9' && buf_temp[i] >= '0')
			buf[j++] = buf_temp[i];
	}
}



