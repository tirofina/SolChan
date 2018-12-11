#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "common.h"

class Customer{
    public:
        Customer(const char *customer_fifo){
            _customer_fifo = customer_fifo;
            _wfd = open(FIFO_MANAGER_PATH, O_WRONLY);
            _rfd = -1;
        };
        ~Customer(){}; 
        
        int start();
    
    private:
        int say_hello();
        int show_menu();
        int make_order();
	int make_membership();
        int bye();

    private:
        const char* _customer_fifo;
        int _wfd;
        int _rfd;
};

#endif
