#ifndef MANAGER_H
#define MANAGER_H

#include "common.h"
#include "store.h"
#include <signal.h>
#include <sys/types.h>

class Manager{
    public:
        Manager(const char *fifo_path){
            _wfd = -1;
            _rfd = open(fifo_path, O_RDONLY | O_NONBLOCK);
            _remainingCustomers = 0;
        };
        ~Manager(){}; 
    
    public:
        int start();

    private:
        int customer_handler();
        int admin_handler();
        int process(const msg_t& msg);
        int take_order(std::string coffee){return _store.take_order(coffee);};

        
        int getSales(){return _store.getSales();};
        bool noCustomers(){return _remainingCustomers==0;};

    private:
        int _wfd;
        int _rfd;
        
        int _remainingCustomers; // how many customers are here?

        Store _store;
};




#endif
