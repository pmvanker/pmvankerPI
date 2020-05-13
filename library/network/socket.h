/*
 * Title: socket.hpp
 * Description : tcp socket basic class header file
 *
 * Revision History
 * Owner                        Date                   Reason for Change
 * Praful Vanker                04/05/2020             Initial file
 * *******************************************************************/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>

#include "GPIO.h"

#define DEFAULT_PORT	3001
#define RTSP_SERVER_BIN_PATH "/home/pi/project/v4l2rtspserver"

enum{
	Fail = -1,
	Pass = 0,
};

/**************************************************************
 * class Name:   TcpServer *
 * @brief:       create tcp socket for communication over socket.
 * @param[IN]:	 port no
 ***************************************************************/
class TcpServer{
	int master_sfd;
	int active_sfd;
	socklen_t client_len;
	struct sockaddr_in server;
	struct sockaddr_in client;

public:
	TcpServer();						/* default constructor */
	TcpServer(int port);				/* Parameterized constructor */
	int transfer(std::string);
	int receive(std::string &,int size);
	int accept_connection();
	~TcpServer(){
		close(active_sfd);
		close(master_sfd);
	}
};

extern TcpServer tcp_socket;
void socketReceiver();
string get_ip();
#endif /* SOCKET_HPP_ */
