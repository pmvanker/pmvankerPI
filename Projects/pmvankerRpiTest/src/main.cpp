/*
 * main.cpp
 *
 *  Created on: 04-May-2020
 *      Author: pmvanker
 */

#include <iostream>
#include <thread>
#include <string>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


#include "socket.hpp"

#define RTSP_SERVER_BIN_PATH "/home/pi/project/v4l2rtspserver"

TcpServer s(3000);


void socketReceiver(){
	std::string str;
	static int child_pid = 0;
	while(1)
	{
		if(s.receive(str,50)>0){
			std::cout << "data :" << str << std::endl;
			if(str == "videostream"){
				if(child_pid = fork()){/* parent process */
					s.transfer("rtsp://192.168.0.103:8554/unicast");
				}else{/* child process */
					execl(RTSP_SERVER_BIN_PATH,NULL);
				}
			}
			else if(str == "StopVideoStream"){
				kill(child_pid,SIGKILL);
			}
			s.transfer("fail");
		}
		usleep(1);
	}
}

int main()
{
	s.accept_connection();
	std::thread t1(socketReceiver);
	t1.join();
	return 0;
}


