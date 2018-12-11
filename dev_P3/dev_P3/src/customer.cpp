#include "customer.h"

char customer_fifo[256];
char manager_fifo[256];

int main(){
    if (make_fifo(customer_fifo, FIFO_CUSTOMER_PATH) == -1){
        return -1;
    }
    if (make_fifo(manager_fifo, FIFO_MANAGER_PATH) == -1){
        return -1;
    }
    
    Customer customer(customer_fifo);
    customer.start();
    
    return 0;
}