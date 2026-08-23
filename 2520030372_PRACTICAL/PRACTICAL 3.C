#include <stdio.h>
#include <unistd.h>
int main()
{
pid_t pid;
printf("Before fork()\n");
printf("PID:%d\n", getpid());
printf("PPID:%d\n", getppid());
printf("State:Running\n\n");
pid = fork();
if (pid < 0)
{
printf("Fork failed\n");
}
else if (pid == 0)
{
printf("CHILD PROCESS\n");
printf("PID:%d\n", getpid());
printf("PPID:%d\n", getppid());
printf("State: Running\n");
printf("Child process: Terminating\n");
}
else
{
printf("PARENT PROCESS\n");
printf("PID:%d\n", getpid());
printf("PPID:%d\n", getpid());
printf("State: Running\n");
printf("Parent process: Terminating\n");
}
return 0;
}

               
