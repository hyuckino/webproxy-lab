# Makefile for Tiny Server + Echo Programs
CC = gcc
CFLAGS = -O2 -Wall -I .
LIB = -lpthread

# 기본 타겟: tiny, echo_server, echo_client 다 만들기
all: tiny cgi echo_server echo_client

# ----------------------------
# ✅ Tiny 웹 서버 빌드
tiny: tiny.c csapp.o
	$(CC) $(CFLAGS) -o tiny tiny.c csapp.o $(LIB)

# ----------------------------
# ✅ Echo 서버 빌드
echo_server: echo_server.c csapp.o
	$(CC) $(CFLAGS) -o echo_server echo_server.c csapp.o $(LIB)

# ✅ Echo 클라이언트 빌드
echo_client: echo_client.c csapp.o
	$(CC) $(CFLAGS) -o echo_client echo_client.c csapp.o $(LIB)

# ----------------------------
# csapp.o (공통 소스)
csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c

# ----------------------------
# CGI 바이너리용 (필요한 경우)
cgi:
	(cd cgi-bin; make)

# ----------------------------
# 클린 업
clean:
	rm -f *.o tiny echo_server echo_client *~
	(cd cgi-bin; make clean)
