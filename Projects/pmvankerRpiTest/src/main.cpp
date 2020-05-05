/*
 * main.cpp
 *
 *  Created on: 04-May-2020
 *      Author: pmvanker
 */

#include <iostream>
#include <thread>
#include <string>

#include "socket.hpp"

TcpServer s(3000);


void socketReceiver(){
	char buffer[50]={0};
	while(1)
	{
		if(s.receive(buffer,50)>0){
			std::cout << "data :" << buffer << std::endl;
			s.transfer((char*)"pass",5);
		}
		usleep(1);
	}
}

int main()
{
	s.accept_connection();
	std::cout << "conneted" << std::endl;
	std::thread t1(socketReceiver);


	t1.join();
	return 0;
}


