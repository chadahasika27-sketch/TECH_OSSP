#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void process_creation(); void exec_demo(); void normal_termination(); void abnormal_termination(); void zombie_process(); void orphan_process();

int main() { int choice;

while (1)
{
    printf("\n========================================\n");
    printf(" LINUX PROCESS LIFECYCLE DEMONSTRATION\n");
    printf("========================================\n");
    printf("1. Process Creation using fork()\n");
    printf("2. Process Execution using exec()\n");
    printf("3. Normal Process Termination\n");
    printf("4. Abnormal Process Termination\n");
    printf("5. Zombie Process\n");
    printf("6. Orphan Process\n");
    printf("7. Exit\n");
    printf("========================================\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            process_creation();
            break;

        case 2:
            exec_demo();
            break;

        case 3:
            normal_termination();
            break;

        case 4:
            abnormal_termination();
            break;

        case 5:
            zombie_process();
            break;

        case 6:
            orphan_process();
            break;

        case 7:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
    }
}

return 0;
}

/* 1. Process Creation */

void process_creation() { pid_t pid;

printf("\n--- PROCESS CREATION ---\n");

pid = fork();

if (pid < 0)
{
    printf("Fork failed.\n");
    return;
}

if (pid == 0)
{
    printf("Child Process Created\n");
    printf("Child PID  : %d\n", getpid());
    printf("Child PPID : %d\n", getppid());

    exit(0);
}
else
{
    printf("Parent Process\n");
    printf("Parent PID : %d\n", getpid());
    printf("Child PID  : %d\n", pid);

    wait(NULL);

    printf("Parent: Child process completed.\n");
}
}

/* 2. exec() Demonstration */

void exec_demo() { pid_t pid; int status;

printf("\n--- EXEC DEMONSTRATION ---\n");

pid = fork();

if (pid < 0)
{
    printf("Fork failed.\n");
    return;
}

if (pid == 0)
{
    printf("Child before exec()\n");
    printf("Child PID: %d\n", getpid());

    execl("./child", "child", NULL);

    printf("exec() failed.\n");
    exit(1);
}
else
{
    waitpid(pid, &status, 0);

    printf("Parent: Child execution completed.\n");
}
}

/* 3. Normal Termination */

void normal_termination() { pid_t pid; int status;

printf("\n--- NORMAL TERMINATION ---\n");

pid = fork();

if (pid < 0)
{
    printf("Fork failed.\n");
    return;
}

if (pid == 0)
{
    printf("Child PID: %d\n", getpid());
    printf("Child is terminating normally.\n");

    exit(0);
}
else
{
    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
    {
        printf("Parent received child termination.\n");
        printf("Exit Status: %d\n", WEXITSTATUS(status));
    }
}
}

/* 4. Abnormal Termination */

void abnormal_termination() { pid_t pid; int status;

printf("\n--- ABNORMAL TERMINATION ---\n");

pid = fork();

if (pid < 0)
{
    printf("Fork failed.\n");
    return;
}

if (pid == 0)
{
    int a = 10;
    int b = 0;

    printf("Child PID: %d\n", getpid());
    printf("Child will perform an invalid arithmetic operation.\n");

    /* Deliberate runtime error */
    printf("Result: %d\n", a / b);

    exit(0);
}
else
{
    waitpid(pid, &status, 0);

    if (WIFSIGNALED(status))
    {
        printf("Child terminated abnormally.\n");
        printf("The child was terminated by the operating system.\n");
    }
    else
    {
        printf("Child terminated normally.\n");
    }
}
}

/* 5. Zombie Process */

void zombie_process() { pid_t pid;

printf("\n--- ZOMBIE PROCESS ---\n");

pid = fork();

if (pid < 0)
{
    printf("Fork failed.\n");
    return;
}

if (pid == 0)
{
    printf("Child PID: %d\n", getpid());
    printf("Child is terminating immediately...\n");

    exit(0);
}
else
{
    printf("Parent PID: %d\n", getpid());
    printf("Child PID : %d\n", pid);

    printf("\nChild has terminated.\n");
    printf("Parent has not called wait() yet.\n");
    printf("The child temporarily becomes a ZOMBIE.\n");

    printf("Parent sleeping for 10 seconds...\n");

    sleep(10);

    wait(NULL);

    printf("Parent collected child status.\n");
    printf("Zombie process removed.\n");
}
}

/* 6. Orphan Process */

void orphan_process() { pid_t pid;

printf("\n--- ORPHAN PROCESS ---\n");

pid = fork();

if (pid < 0)
{
    printf("Fork failed.\n");
    return;
}

if (pid == 0)
{
    printf("Child PID: %d\n", getpid());
    printf("Original Parent PID: %d\n", getppid());

    sleep(5);

    printf("\nParent has terminated.\n");
    printf("Child is still running.\n");
    printf("Child PID: %d\n", getpid());
    printf("New Parent PID: %d\n", getppid());

    printf("Child has become an ORPHAN process.\n");
}
else
{
    printf("Parent PID: %d\n", getpid());
    printf("Parent is terminating before the child.\n");

    exit(0);
}
}
