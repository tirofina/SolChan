#include "common.h"

int make_fifo(char *dst, const char *src){
    // Creating FIFO
    // Each customer makes a FIFO to read data from the manager. 
    // The path of the FIFO is set to FIFO_PATH/FIFO_CUSTOMER_PATH
    sprintf(dst, src, getpid());
    
    int ret = 0;
    if (access(dst, F_OK)==-1){
        ret = mkfifo(dst, 0777);
    }

    return ret;
}

msg_t make_msg(const char *cmd, const char *data){
    msg_t msg;

    strncpy(msg.cmd, cmd, CMD_LEN);
    strncpy(msg.data, data, DATA_LEN);
    msg.pid = getpid();
    
    return msg;
}

int send_msg(const int wfd, const msg_t msg){
    int size = write(wfd, &msg, sizeof(msg_t));
    return size;
}

int receive_msg(const int rfd, msg_t& msg){
    int size = read(rfd, &msg, sizeof(msg_t));
    return size;
}

void log(const char *str, const msg_t& msg){
    printf("%s: (cmd: %s)\n[msg]\n%s\n", str, msg.cmd, msg.data);
}

void log(const char *str){
    printf("%s\n", str);
}