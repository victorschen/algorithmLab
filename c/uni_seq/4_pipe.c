#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#define MAXLINE 100

void server(int, int);
void client(int, int);

int main(void)
{
    int pipe1[2], pipe2[2];
    pid_t childpid;

    if(pipe(pipe1) < 0 || pipe(pipe2) < 0)
    {
        perror("pipe:");
        return 0;
        //exit(-1);
    }

    if((childpid = fork()) < 0)
    {
        perror("fork:");
        return 0;
        //exit(-1);
    }

    if(childpid == 0)
    {
        close(pipe1[1]);
        close(pipe2[0]);
        server(pipe1[0],pipe2[1]);
    }

    close(pipe1[0]);
    close(pipe2[1]);
    client(pipe2[0],pipe1[1]);
    //waidpid(childpid, NULL, 0);

    return 0;
}

void server(int readfd, int writefd)
{
    int fd;
    ssize_t n;
    char buff[MAXLINE+1];

    if( (n = read(readfd, buff, MAXLINE)) == 0)
        printf("读取结束");
    buff[n] = '\0';

    if( (fd = open(buff, O_RDONLY)) < 0) 
    {
        snprintf(buff+n, sizeof(buff)-n, "不能打开,%s\n", strerror(errno));
        n = strlen(buff);
        write(writefd, buff, n);
    } 
    else
    {
        while( (n = read(fd, buff, MAXLINE)) > 0)
            write(writefd, buff, n);
        close(fd);
    }
}

void client(int readfd, int writefd)
{
    size_t len;
    ssize_t n;
    char buff[MAXLINE];

    fgets(buff, MAXLINE, stdin);
    len = strlen(buff);
    if (buff[len-1] == '\n')
        len--;
    write(writefd, buff, len);
    while( (n = read(readfd, buff, MAXLINE)) > 0)
        write(STDOUT_FILENO, buff, n);
}

