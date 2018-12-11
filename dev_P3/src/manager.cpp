#include "manager.h"

char manager_fifo[256];

int main(){
    if (make_fifo(manager_fifo, FIFO_MANAGER_PATH) == -1){
        return -1;
    }

    Manager manager(manager_fifo);
    manager.start();
    
    return 0;
}