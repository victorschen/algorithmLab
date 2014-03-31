#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i;
    for (i=0; i<2; i++)
    {
        pid_t pid = fork();
        printf("-");
        //printf("%d进程%d第%d次: - \n", getppid(), getpid(), i);
        //sleep(10);
    }

    return 0;
}
