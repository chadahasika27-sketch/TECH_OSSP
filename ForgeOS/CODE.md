#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void process_creation();
void exec_demo();
void normal_termination();
void abnormal_termination();
void zombie_process();
void orphan_process();

int main()
{
    int choice;

    while (1)
    {
        printf("\n========================================\n");
        printf("   LINUX PROCESS LIFECYCLE DEMONSTRATION\n");
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
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter 1 to 7.\n");
        }
    }

    return 0;
}


/* ========================================
   1. PROCESS CREATION USING fork()
   ======================================== */

void process_creation()
{
    int pid;

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


/* ========================================
   2. PROCESS EXECUTION USING exec()
   ======================================== */

void exec_demo()
{
    int pid;
    int status;

    printf("\n--- EXEC DEMONSTRATION ---\n");

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed.\n");
        return;
    }

    if (pid == 0)
    {
        printf("Child process before exec()\n");
        printf("Child PID: %d\n", getpid());

        printf("Executing 'ls' using exec()...\n\n");

        execl("/bin/ls", "ls", NULL);

        printf("exec() failed.\n");
        exit(1);
    }
    else
    {
        waitpid(pid, &status, 0);

        printf("\nParent: exec() child completed.\n");
    }
}


/* ========================================
   3. NORMAL PROCESS TERMINATION
   ======================================== */

void normal_termination()
{
    int pid;
    int status;

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


/* ========================================
   4. ABNORMAL PROCESS TERMINATION
   ======================================== */

void abnormal_termination()
{
    int pid;
    int status;

    printf("\n--- ABNORMAL TERMINATION ---\n");

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed.\n");
        return;
    }

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        printf("Child will terminate abnormally.\n");

        abort();
    }
    else
    {
        waitpid(pid, &status, 0);

        if (WIFSIGNALED(status))
        {
            printf("Child terminated abnormally.\n");
            printf("Operating system terminated the child.\n");
        }
        else
        {
            printf("Child terminated normally.\n");
        }
    }
}


/* ========================================
   5. ZOMBIE PROCESS
   ======================================== */

void zombie_process()
{
    int pid;

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

        printf("Parent sleeping for 5 seconds...\n");

        sleep(5);

        wait(NULL);

        printf("Parent collected child status.\n");
        printf("Zombie process removed.\n");
    }
}


/* ========================================
   6. ORPHAN PROCESS
   ======================================== */

void orphan_process()
{
    int pid;

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

        sleep(3);

        printf("\nParent has terminated.\n");
        printf("Child is still running.\n");
        printf("Child PID: %d\n", getpid());
        printf("New Parent PID: %d\n", getppid());

        printf("Child has become an ORPHAN process.\n");

        exit(0);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        printf("Parent is terminating before the child.\n");

        exit(0);
    }
}
