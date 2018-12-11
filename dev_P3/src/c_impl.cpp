#include "customer.h"
#include <string>
#include <iostream>

int Customer::start(){
    say_hello();
    
    std::string input;
    
    while(1){
        std::cout<<"What do you want?"<<std::endl;
        std::cout<<"1. show menu (press 1)"<<std::endl;
        std::cout<<"2. make order (press 2)"<<std::endl;
        std::cout<<"3. bye (press 3)"<<std::endl;
        
        std::cin>>input;    

        if (input=="1"){
            show_menu();
        }
        else if (input=="2"){
            make_order();
        }
        else if (input=="3"){
            bye();
            break;
        }
    }

    return 0;
}

//make a connection with the manager
int Customer::say_hello(){
    log ("[Customer] new customer comes in.");
    msg_t msg = make_msg(CMD_HELLO, "");
    
    send_msg(_wfd, msg);
    _rfd = open(_customer_fifo, O_RDONLY);
    std::cout<<_rfd<<std::endl;
    receive_msg(_rfd, msg); //block here
}

int Customer::show_menu(){
    msg_t msg = make_msg(CMD_SHOW_MENU, "");
    log("[Client] show menu", msg);
    send_msg(_wfd, msg);
    _rfd = open(_customer_fifo, O_RDONLY);
    receive_msg(_rfd, msg); //block here
    log("[Client] get menu", msg);

    return 0;
}

int Customer::make_order(){
    std::string c;
    std::cout<<"Please name what you want"<<std::endl;
    std::cin>>c;
    msg_t msg = make_msg(CMD_MAKE_ORDER, c.c_str());
    log("[Client] make_order", msg);
    send_msg(_wfd, msg);
    _rfd = open(_customer_fifo, O_RDONLY);
    receive_msg(_rfd, msg); //block here
    log("[Client] get coffee", msg);

    return 0;
}

int Customer::bye(){
    msg_t msg = make_msg(CMD_BYE, "");
    send_msg(_wfd, msg);
    _rfd = open(_customer_fifo, O_RDONLY);
    receive_msg(_rfd, msg); //block here
    log("[Client] bye", msg);
    close(_rfd);
    unlink(_customer_fifo);

    return 0;
}