#ifndef COMMON_H
#define COMMON_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// Note that this path is relative to the current working directory.
#define FIFO_CUSTOMER_PATH "../res/c_fifo_%d"  
#define FIFO_MANAGER_PATH "../res/s_fifo"  

#define CMD_HELLO       "HELLO"
#define CMD_SHOW_MENU   "SMENU"
#define CMD_MAKE_ORDER  "ORDER"
#define CMD_BYE         "BYEBY"
#define CMD_MANAGER     "MNGER"
#define CMD_POINT_SAVE	"SPOIN" //
#define CMD_POINT_USE	"UPOIN" //
#define CMD_CHECK_MEM   "CKMEM" //
#define CMD_MAKE_MEMBER "MKMEM" //
#define CMD_CHECK_PASS  "CKPAS" 

#define CMD_LEN 6
#define DATA_LEN 1024   // < PIPE_BUF

typedef struct MSG{
    char cmd[CMD_LEN];        //command
    char data[DATA_LEN];    //custom_data
    pid_t pid;
} msg_t;

int make_fifo(char *dst, const char *src); //make fifo

msg_t make_msg(const char *cmd, const char *data); //make a msg
int send_msg(const int wfd, const msg_t msg);   //write a msg to the given fifo
int receive_msg(const int rfd, msg_t& msg);   //read a msg from the given fifo

void log(const char *str, const msg_t& msg);
void log(const char *str);

#endif
