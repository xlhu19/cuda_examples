

/*
int
select
(
int maxfdp1,
fd_set *readset,
fd_set *writeset,
fd_set *exceptset,
const struct timeval * timeout
);
Return
>0：就绪描述字的正数目
-1：出错
0 ：超时
*/

/*
struct timeval
{
long tv_sec; // seconds
long tv_usec; // microseconds
}
*/

/*
void FD_ZERO (fd_set *fdset); // clear all bits in fdset
void FD_SET (int fd, fd_set *fdset); // turn on the bit for fd in fdset
void FD_CLR (int fd, fd_set *fdset); // turn off the bit for fd in fdset
int FD_ISSET (int fd, fd_set *fdset); // is the bit for fd on in fdset
*/

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#define PORT  2345  /*使用的port号码*/

int main()
{
	int sockfd, len, ret;
	int addr_len;
	char buffer[256];
	struct sockaddr_in addr;
	fd_set readFds;
	struct timeval timeout;

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket");
		exit(1);
	}
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
	{
		perror("connect");
		exit(1);
	}

	while (1)
	{
		FD_ZERO(&readFds);
		FD_SET(sockfd, &readFds);
		timeout.tv_sec = 3;
		timeout.tv_usec = 0;
		ret = select(sockfd + 1, &readFds, NULL, NULL, &timeout);

		if (FD_ISSET(sockfd, &readFds))
		{
			printf("receive socket data!\n");
			bzero(buffer, sizeof(buffer));
			addr_len = sizeof(struct sockaddr_in);
			len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len);
			printf("receive from %s\n", inet_ntoa(addr.sin_addr));
			sendto(sockfd, buffer, len, 0, (struct sockaddr*)&addr, addr_len);
		}
		printf("do something else!\n");
	}

	return 0;
}
