#ifndef  _TEST_
#define _TEST_


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define LEN_BUF 11 
#define NAME_SERIAL "/dev/ttyUSB0"

extern void open_port(int *);
extern void uart_init(int);
extern void read_from_serial(int, unsigned char *);
#endif
