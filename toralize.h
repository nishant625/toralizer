#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <dlfcn.h>

// socket()
// connect()
// close()
// htons()
// inet_addr()

#define PROXY "127.0.0.1"
#define PROXYPORT 9050
#define reqsize  sizeof(struct proxy_request)
#define ressize  sizeof(struct proxy_response)
#define USERNAME "toraliz"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct proxy_request
{
    int8 vn;
    int8 cd;
    int16 dstport;
    int32 dstip;
    unsigned char userid[8];
};

typedef struct proxy_request Req;

struct proxy_response
{
    int8 vn;
    int8 cd;
    int16 _;
    int32 __;
};

typedef struct proxy_response Res;

Req *request(struct sockaddr_in *);

int connect(int , const struct sockaddr *,
                   socklen_t );