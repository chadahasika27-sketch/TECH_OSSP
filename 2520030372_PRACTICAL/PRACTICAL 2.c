#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd1,fd2;
size_t n;
char buf[100];
fd1=open("a7",O_RDWR);
fd2=open("a8", O_WRONLY | O_CREAT, 0644);
while((n=read(fd1,buf,sizeof(buf)))>0)
{
 write(fd2, buf, n);
 write(1, buf, n);
}

remove("a7");
 }
