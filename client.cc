#include <iostream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include "common.h"
using namespace std;

#define MAXLINE 80


int main (int argc, char *argv[]) {
    int n, cfd;
    struct hostent *h;
    struct sockaddr_in saddr;
    char buf[MAXLINE];
    char *host = argv[1];
    int port = atoi(argv[2]);
    
    if ((cfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket() failed.\n"); 
        exit(1);
    }
    if ((h = gethostbyname(host)) == NULL) {
        printf("invalid hostname %s\n", host); 
        exit(2);
    }   
    memset((char *)&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    memcpy((char *)&saddr.sin_addr.s_addr, (char *)h->h_addr, h->h_length);
    saddr.sin_port = htons(port);

    if (connect(cfd,(struct sockaddr *)&saddr,sizeof(saddr)) < 0) {
        printf("connect() failed.\n");
        exit(3);
    }
		int card1,card2;
		read(cfd,&card1,sizeof(int));
		read(cfd,&card2,sizeof(int));
		printf("Your Card : %s %s\n",NumToCard(card1),NumToCard(card2));
    
		

		close(cfd);

    return 0;
}
