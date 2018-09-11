#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT  2345  /*ʹ�õ�port����*/

main()
{
	int sockfd,len;
	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	char buffer[256];
	/*����socket*/
	if((sockfd = socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		perror("socket");
		exit(1);
	}
	/*��дsockaddr_in�ṹ*/
	bzero(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(sockfd,&addr,sizeof(addr))<0)
	{
		perror("connect");
		exit(1);
	}
	while(1)
	{
		/*����client�˴������ַ���*/
		bzero(buffer,sizeof(buffer));
		len = recvfrom(sockfd,buffer,sizeof(buffer),0,&addr,&addr_len);
		/*��ʾclient�˵������ַ��IP��*/
		printf("receive from %s\n",inet_ntoa(addr.sin_addr));
		/*���ַ������ظ�client��*/
		sendto(sockfd,buffer,len,0,&addr,addr_len);	
	}
}