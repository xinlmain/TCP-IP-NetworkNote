#include <stdio.h>
#include <unistd.h>

int global = 10;
int main(int argc, char *argv[])
{
    int local = 20;

    pid_t pid = fork();
    
    if (pid == 0)
        global += 2, local += 2;
    else
        global -= 2, local -= 2;

    if (pid == 0)
        printf("Child Proc: [%d,%d] \n", global, local);
    else
        printf("Parent Proc: [%d,%d] \n", global, local);

    return 0;
}
