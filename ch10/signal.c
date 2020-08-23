#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) //信号处理器
{
    if (sig == SIGALRM)
        puts("Time out!");
    alarm(2); //为了每隔 2 秒重复产生 SIGALRM 信号，在信号处理器中调用 alarm 函数
}
void keycontrol(int sig) //信号处理器
{
    if (sig == SIGINT)
        puts("CTRL+C pressed");
}
int main(int argc, char *argv[])
{
    int i;
    signal(SIGALRM, timeout); //注册信号及相应处理器
    signal(SIGINT, keycontrol);
    alarm(2); //预约 2 秒候发生 SIGALRM 信号

    for (i = 0; i < 3; i++)  // 为啥control-C或者 alarm 只打印三次呢？就是因为发生信号中断的时候一定是在sleep期间，而sleep的次数就决定了能响应几次。次数用完后程序就跑到结束了。
    {
        puts("wait...");
        sleep(100);
    }
    return 0;
}
