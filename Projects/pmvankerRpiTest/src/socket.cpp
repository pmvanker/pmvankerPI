/*
 * Title: socket.cpp
 * Description : tcp socket basic class definations
 *
 * Revision History
 * Owner                        Date                   Reason for Change
 * Praful Vanker                04/05/2020             Initial file
 * *******************************************************************/

#include "socket.hpp"

/**************************************************************
 * Function Name:   accept_connection()
 * @brief:          accept the socket connection
 * @remarks:        blocking function
 ***************************************************************/
int TcpServer::accept_connection(){
	active_sfd = accept( master_sfd , (struct sockaddr*)&client, &client_len);
	if(active_sfd > 0){
		return Pass;
	}
	return Fail;
}

/**************************************************************
 * Function Name:   transfer
 * @brief:          send data to socket
 * @param[IN]:		data : buffer data
 * 					size : size of data
 ***************************************************************/
int TcpServer::transfer(char *data, int size){
	return send(active_sfd,data,size,MSG_DONTWAIT);
}


/**************************************************************
 * Function Name:   receive()
 * @brief:          receive data from socket
 * @param[OUT]:     data : received data
 * 					size : size of data
 ***************************************************************/
int TcpServer::receive(char *data, int size){
	return recv(active_sfd,data,size,MSG_WAITFORONE);
}


/**************************************************************
 * Function Name:   TcpServer()
 * @brief:          Constuctor call will construct the object
 * 					create socket bind it, listen it.
 ***************************************************************/
TcpServer::TcpServer(){
	master_sfd = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;						//bind
	server.sin_port   = htons(DEFAULT_PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(master_sfd,(struct sockaddr*)&server, sizeof(server));
	listen(master_sfd,1);
	client_len = 0;
	active_sfd = 0;
}

/**************************************************************
 * Function Name:   TcpServer()
 * @brief:          Constuctor call will construct the object
 * 					create socket bind it, listen it.
 * @param[IN]:		port : port no
 ***************************************************************/
TcpServer::TcpServer(int port)
{
	master_sfd = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;						//bind
	server.sin_port   = htons(port);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(master_sfd,(struct sockaddr*)&server, sizeof(server));
	listen(master_sfd,1);
	client_len = 0;
	active_sfd = 0;
}
