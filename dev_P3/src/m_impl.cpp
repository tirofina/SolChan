#include "manager.h"
#include <iostream>
#include <string>

static bool admin_mode = false;

static void sig_handler(int sig)
{
	std::cout << "\nAdmin Mode On" << std::endl;
	admin_mode = true;
}

static void sig_handler2(int sig)
{ //^C
	std::cout << "\nBYE" << std::endl;
	unlink(FIFO_MANAGER_PATH);
	exit(0);
}

int Manager::start()
{
	signal(SIGTSTP, sig_handler); //^Z
	signal(SIGINT, sig_handler2); //^C

	std::string input;
	log("[Manager] Waiting customers...");
	while (1)
	{
		if (true == admin_mode)
		{
			admin_handler();
			admin_mode = false;
			log("[Manager] Waiting customers...");
			continue;
		}

		customer_handler();
	}

	return 0;
}

int Manager::customer_handler()
{
	msg_t msg;
	int read_bytes;

	pid_t c_pid;

	while (1)
	{
		if (noCustomers() && admin_mode == 1)
		{
			break;
		}
		read_bytes = receive_msg(_rfd, msg); //waiting a msg from c.
		if (read_bytes <= 0)
			continue;
		log("received", msg);
		process(msg);
	}

	return 0;
}

int Manager::process(const msg_t &msg)
{
	char customer_fifo[256];
	sprintf(customer_fifo, FIFO_CUSTOMER_PATH, msg.pid);
	_wfd = open(customer_fifo, O_WRONLY);

	msg_t new_msg;

	if (strcmp(msg.cmd, CMD_HELLO) == 0)
	{
		new_msg = make_msg(CMD_MANAGER, "");

		send_msg(_wfd, new_msg);
		log("[Manager] new customer");
		log("[Manager] now waiting commands");

		_remainingCustomers++;

		close(_wfd);
	}
	else if (strcmp(msg.cmd, CMD_SHOW_MENU) == 0)
	{
		new_msg = make_msg(CMD_MANAGER, _store.makeMenu().c_str());
		send_msg(_wfd, new_msg);
		log("[Manager] sent menu");
		close(_wfd);
	}
	else if (strcmp(msg.cmd, CMD_MAKE_ORDER) == 0)
	{
		std::string c(msg.data);
		take_order(c);
		new_msg = make_msg(CMD_MANAGER, "");
		send_msg(_wfd, new_msg);
		log("[Manager] coffee here");
		close(_wfd);
	}
	else if (strcmp(msg.cmd, CMD_BYE) == 0)
	{
		new_msg = make_msg(CMD_MANAGER, "");
		send_msg(_wfd, new_msg);
		log("[Manager] done");
		close(_wfd);

		_remainingCustomers--;
	}

	return 0;
}

int Manager::admin_handler()
{
	std::string input;
	while (1)
	{
		std::cout << "\nPlease give an input" << std::endl;
		std::cout << "1. check sales (type 1)" << std::endl;
		std::cout << "2. check remaining ingredients (type 2)" << std::endl;
		std::cout << "3. create new Menu (type 3)" << std::endl;
		std::cout << "4. Purchase ingredients (type 4)" << std::endl;
		std::cout << "5. go back to the default mode (type q)" << std::endl;
		std::cin >> input;

		if (input == "1")
		{
			std::cout << "Sales: " << _store.getSales() << std::endl;
		}
		else if (input == "2")
		{
			_store.printAllIngredients();
		}
		else if (input == "3")
		{
			_store.createMenu();
		}

		else if (input == "4")
		{
			_store.printAllIngredients();
			
			std::cout << "Please enter the number of the menu you want to order : ";
			
			_store.PurchaseIngredients();
		}

		else if (input == "q")
		{
			break;
		}
	}
	return 0;
}
