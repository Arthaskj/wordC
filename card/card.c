#include <stdio.h>
#include "IC_serial.h"

main()
{
	int i;
	int fd;
	char buf[32]={0};
	
	open_port(&fd);
	uart_init(fd);
	
	for(i=0;i<20;i++)
	{
		read_from_serial(fd,buf);
		printf("card:%s\n",buf);
	}
}
//create  table  stu( sno  integer primary key,sname  text not null ,ssex  text default 'ÄÐ' ,sage  integer default 19 , sdept  text default 'math');