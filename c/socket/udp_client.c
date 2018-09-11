#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT           23441                   /*使用的PORT号码*/
#define SERVER_IP      "192.168.0.83"            /*server的IP*/

int main(void)
{
	int s, len;
	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	char buffer[256];
	/*建立socket*/
	if ((s = socket(AF_INET,SOCK_DGRAM, 0)) < 0)
	{
		perror("socket");
		exit(1);
	}
	/*填写sockaddr_in结构*/
	bzero(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	while (1)
	{
		bzero(buffer,sizeof(buffer));
		/*从标准输入取得字符串*/
		len = read(STDIN_FILENO,buffer,sizeof(buffer));
		printf("len : %d",len);
		/*将字符串传给server端*/
		sendto(s,buffer,len,0,&addr,addr_len);
		/*接收server端返回的字符串*/
		len = recvfrom(s,buffer,sizeof(buffer),0,&addr,addr_len);
		printf("receive : %s",buffer);
		
	}
}
