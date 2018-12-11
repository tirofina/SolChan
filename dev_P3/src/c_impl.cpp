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
	    std::cout<<"3. make membership (press 3)"<<std::endl;
	    std::cout<<"4. bye (press 4)"<<std::endl;
        
        std::cin>>input;    

        if (input=="1"){
            show_menu();
        }
        else if (input=="2"){
            make_order();
        }
        else if (input=="3"){
            make_membership();
        }
	else if (input=="4"){
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
    msg_t msg;
    std::string c;
    std::cout<<"Please name what you want"<<std::endl;
    std::cin>>c;
    char flag;
    std::cout<<"Are you a member? (Y/N)"<<std::endl;
    std::cin>>flag;
    if(flag=='Y'){
        std::string name;
        while(true){
            std::cout<<"Please enter your name"<<std::endl;
            std::cin>>name;
             msg=make_msg(CMD_CHECK_MEM,name.c_str());
            send_msg(_wfd,msg);
            _rfd=open(_customer_fifo,O_RDONLY);
            receive_msg(_rfd,msg);
            //log("[Client] check member", msg);
            if(strcmp("-1",msg.data)==0){
                std::cout<<"name does not exist. sorry."<<std::endl;
            }else{
                break;
            }
        }
        std::string m_new;
            int point=atoi(msg.data);
            std::cout<<"Your point is "<<point<<std::endl;
            char pointflag;
            std::cout<<"Do you want to use point? (Y/N)"<<std::endl;
            std::cin>>pointflag;
            if(pointflag=='Y'){
                std::string password;
                while(true){
                    std::cout<<"Enter your membership password"<<std::endl;
                    std::cin>>password;
                    std::string c_pass=name+" "+password;
                    msg=make_msg(CMD_CHECK_PASS,c_pass.c_str());
                    send_msg(_wfd,msg);
                    _rfd=open(_customer_fifo,O_RDONLY);
                    receive_msg(_rfd,msg);
                    //log("[Client] check member", msg);
                    if(strcmp("-1",msg.data)==0){
                        std::cout<<"worng password"<<std::endl;
                    }else{
                        int u_point;
                        std::cout<<"how much would you like to use?"<<std::endl;
                        std::cin>>u_point;
                        m_new=name+" "+c+" "+std::to_string(u_point);
                        msg=make_msg(CMD_POINT_USE,m_new.c_str());
                        send_msg(_wfd,msg);
                        _rfd=open(_customer_fifo,O_RDONLY);
                        receive_msg(_rfd,msg);
                        break;
                    }
                }
            }else{
                m_new=name+" "+c;
                msg=make_msg(CMD_POINT_SAVE,m_new.c_str());
                send_msg(_wfd,msg);
                _rfd=open(_customer_fifo,O_RDONLY);
                receive_msg(_rfd,msg);
                log("[Client] get coffee", msg);
            }
    }else{
        msg=make_msg(CMD_MAKE_ORDER,c.c_str());
        send_msg(_wfd,msg);
        _rfd=open(_customer_fifo,O_RDONLY);
        receive_msg(_rfd,msg); //bolck here
        log("[Client] get coffee", msg);
    }

    return 0;
}

int Customer::make_membership(){
	std::string name, password;
	std::cout<<"Please input your name (without space)"<<std::endl;
	std::cin>>name;
	std::cout<<"Please input using password (without space)"<<std::endl;
	std::cin>>password;
	std::string u_mag=name+" "+password;
	msg_t msg = make_msg(CMD_MAKE_MEMBER,u_mag.c_str());
	log("[CLient] make_membership",msg);
	send_msg(_wfd,msg);
	_rfd=open(_customer_fifo,O_RDONLY);
	receive_msg(_rfd,msg);
	log("[CLient] get membership",msg);

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
