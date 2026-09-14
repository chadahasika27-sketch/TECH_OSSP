#include<stdio.h>
#include<unistd.h>//for for() system call
#include<sys/wait.h>//for wait() and waitpid() system call
#include<stdlib.h>//for exit() system call
int main()
{
int pid[3];// array to create 3 childs
for(int i=0;i<3;i++){//for loop to navigate through the childs
pid[i]=fork();// creating the childs
if(pid[i]==0)//checking for the child process
{
printf("Child %d pid=%d\n",i+1,getpid());//printing the child and its process id
sleep(i+1);// making every child sleep for 1 sec
exit(0);//exiting the standard input
}
}
wait(NULL);//taking the status of child
printf("Parent:Any one child completes with wait()\n");//one parent printing its status
waitpid(pid[2],NULL,0);//taking the status of the 3rd child
printf("Parent:child 3 complets with waitpid()\n");//one parent
wait(NULL);// last child satus
printf("Parent:All the childs completed");//another parent taking the satus of the last
}
