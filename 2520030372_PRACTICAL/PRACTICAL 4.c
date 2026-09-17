#include<stdio.h>
#include<unistd.h>// for fork() system call
#include<sys/wait.h>// for wait() and waitpid()
#include<stdlib.h>//for exit() system call
int main()
{
int pid[3];// array to create 3 childs
for(int i=0;i<3;i++)// for loop to navigate through the child
{
pid[i]=fork();// creating the child process
if(pid[i]==0)// checking the child process
{
printf("Child %d pid=%d\n",i+1,getpid());//printing the child and the process
sleep(i+1);//making the child sleep for 1 sec
exit(0);// exiting standard input
}
}
wait(NULL);
printf("Parent:Any one child completes with wait()");
waitpid(pid[2],NULL,0);
printf("Parent: Child 3 completes with waitpid()\n");
wait(NULL);
printf("Parent:All the childs completed");
}


                      
