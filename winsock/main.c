/*linker
*        ws2_32
*        wsock32
*/
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>


int main()
{
    WSADATA data;
    SOCKET s;
    struct sockaddr_in str;
    char *request, answer[100000], ip[13];
    int v;
    printf("zadajte ip\n");
    scanf("%s", ip);
    WSAStartup(MAKEWORD(2,2), &data);
    s=socket(AF_INET, SOCK_STREAM, 0);

    str.sin_addr.s_addr=inet_addr(ip);
    str.sin_family=AF_INET;
    str.sin_port=htons(8080);


    connect(s, (struct sockaddr*)&str, sizeof(str));
    //printf("poziadavku v http\n");
    request="GET /HTTP/1.0\n\r\n\r";
    send(s, request, strlen(request), 0);
    v=recv(s, answer, 100000, 0);
    answer[v]='\0';
    puts(answer);
    getchar();
    return 0;
}
