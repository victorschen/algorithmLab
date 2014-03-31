#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define MAXLINE 100

int main(void)
{
    char cmd[MAXLINE];
    FILE *fp;
    int n = 0;
    
    printf("请输入命令:");
    fgets(cmd, MAXLINE, stdin);
    n = strlen(cmd);
    if(cmd[n-1] == '\n')
        cmd[n-1] = '\0';

    if((fp = popen(cmd, "r")) == NULL)
    {
        printf("命令%s执行错误", cmd);
        return 0;
    }

    while((fgets(cmd, MAXLINE, fp)) != NULL)
        fputs(cmd, stdout);

    pclose(fp);

    return 0;
}

