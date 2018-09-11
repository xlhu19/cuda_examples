#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <mqueue.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <dirent.h>
#include <signal.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>
#include <netdb.h>
#include <sys/ioctl.h> 
#include <net/if.h> 
#include <netinet/ip_icmp.h> 
#include <linux/if_ether.h>


#define PROMISC_MODE                     1
#define TIME_OUT                         1000

char src_dev[10];
char dst_dev[10];
unsigned int packet_cnt = 0;
unsigned int snaplen = 1600;


void process_pkt(u_char *firstfile, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
	struct sockaddr sa;
	int sock;
	packet_cnt++;

	sock = socket(AF_INET, SOCK_PACKET, htons(ETH_P_RARP));
	if (sock < 0)
	{
		perror("socket error\n");
		exit(1);
	}

	strcpy(sa.sa_data, dst_dev);

	if (sendto(sock, pkt_data, header->len, 0, &sa, sizeof(sa)) < 0)
	{
		perror("sendto error\n");
	}

	close(sock);
}

void show_statistics(int signal)
{
	printf("packet count %d\n", packet_cnt);
	exit(0);
}

int main(int argc, char** argv)
{
	pcap_t* pcap = NULL;
	char errorbuf[256];
	int ch;

	strcpy(src_dev, "eth0");
	strcpy(dst_dev, "eth1");

	while ((ch = getopt(argc, argv, "s:d:")) != -1)
	{
		switch (ch)
		{
			case 's':
				strcpy(src_dev, optarg);
				//printf("src_dev %s\n", src_dev);
				break;
			case 'd':
				strcpy(dst_dev, optarg);
				//printf("dst_dev %s\n", dst_dev);
				break;
			case ':':
				opterr = 0;
				printf("option requires an argument\n");
				break;
			case '?':
				opterr = 0;
				printf("can not find option %c\n", optopt);
				break;
		}
	}

	signal(SIGINT, show_statistics);

	pcap = pcap_open_live(src_dev, snaplen, PROMISC_MODE, TIME_OUT, errorbuf);
	if (pcap == NULL)
	{
		printf("open device error\n");
		return -1;
	}

	pcap_loop(pcap, -1, (pcap_handler)process_pkt, NULL);
}
