// echo_client.c
#include "csapp.h"

int main(int argc, char **argv) {
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }

    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);       // 서버에 연결
    Rio_readinitb(&rio, clientfd);              // rio 버퍼 초기화

    while (Fgets(buf, MAXLINE, stdin) != NULL) {  // 사용자 입력
        Rio_writen(clientfd, buf, strlen(buf));   // 서버에 전송
        Rio_readlineb(&rio, buf, MAXLINE);        // 서버 응답 받기
        Fputs(buf, stdout);                       // 화면 출력
    }

    Close(clientfd);  // 소켓 닫기
    exit(0);
}
