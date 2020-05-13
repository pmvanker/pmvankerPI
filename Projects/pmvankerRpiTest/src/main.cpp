/*
 * main.cpp
 *
 *  Created on: 04-May-2020
 *      Author: pmvanker
 */



#include "main.hpp"

TcpServer tcp_socket(3000);

int main()
{

	tcp_socket.accept_connection();
	std::thread t(socketReceiver);
	t.join();
	return 0;
}


