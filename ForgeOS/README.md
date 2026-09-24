Linux Process Creation, Execution and Termination System
1. Introduction
The Linux Process Creation, Execution and Termination System is a C-based Operating Systems project designed to demonstrate the complete lifecycle of a Linux process.

The project explains how a parent process creates a child process using fork(), how the child can replace its program using exec(), and how the parent monitors the child using wait() and waitpid().

The project also demonstrates Process IDs (PID), Parent Process IDs (PPID), normal termination, abnormal termination, zombie processes, and orphan processes.

2. Problem Statement
Understanding process management is an important part of Operating Systems.

System calls such as:

fork()
exec()
wait()
waitpid()
exit()
are fundamental to Linux process management.

However, these concepts can be difficult to understand through theory alone.

Therefore, this project provides a simple interactive Linux-based system that allows students to observe process creation, execution, synchronization, and termination.

3. Objectives
The main objectives of this project are:

To understand Linux process creation.
To demonstrate the fork() system call.
To understand parent and child processes.
To demonstrate the exec() system call.
To understand process synchronization using wait().
To demonstrate waitpid().
To understand normal process termination.
To demonstrate abnormal process termination.
To understand zombie processes.
To understand orphan processes.
To observe PID and PPID relationships.
4. Technologies Used
Operating System: Linux / Ubuntu
Programming Language: C
Compiler: GCC
System Calls: fork(), exec(), wait(), waitpid(), exit(), kill()
Debugging Tool: GDB (optional)
5. System Calls Used
fork()
fork() creates a new child process.

The child process receives a separate Process ID.

exec()
exec() replaces the current process program with another executable program.

In this project, execl() is used.

wait()
wait() allows the parent process to wait for a child process to finish.

waitpid()
waitpid() allows the parent to wait for a specific child process.

getpid()
getpid() returns the Process ID of the current process.

getppid()
getppid() returns the Parent Process ID.

exit()
exit() terminates the current process normally.

kill()
kill() is used to send a signal to a process. In this project it is used to demonstrate abnormal termination.

6. Process Lifecycle
The basic process lifecycle is:

Parent Process | | fork() ↓ Child Process | | exec() ↓ Program Execution | | exit() ↓ Child Termination | | wait()/waitpid() ↓ Parent Collects Status

7. Project Modules
Module 1: Process Creation
Demonstrates the creation of a child process using fork().

The program displays:

Parent PID
Child PID
Child PPID
Module 2: Process Execution
Demonstrates the use of exec().

The child process replaces its current program with the child executable.

Module 3: Normal Termination
The child process terminates normally using:

exit(0);

The parent uses waitpid() to collect the termination status.

Module 4: Abnormal Termination
The child process sends SIGTERM to itself.

The parent detects abnormal termination using:

WIFSIGNALED()

and obtains the signal number using:

WTERMSIG()

Module 5: Zombie Process
A zombie process occurs when a child has terminated but its parent has not yet collected its termination status.

The project intentionally delays the parent's wait() call to demonstrate this condition.

After wait() is called, the zombie entry is removed.

Module 6: Orphan Process
An orphan process occurs when the parent terminates before the child.

The child continues execution and gets adopted by another system process.

The project displays the child's PPID before and after the original parent terminates.

8. Compilation
Open the terminal in the project directory.

Compile the child program:

gcc child.c -o child

Compile the main program:

gcc main.c -o process_lifecycle

9. Running the Program
Run the program using:

./process_lifecycle

10. Sample Menu
======================================== LINUX PROCESS LIFECYCLE DEMONSTRATION
Process Creation using fork()
Process Execution using exec()
Normal Process Termination
Abnormal Process Termination
Zombie Process
Orphan Process
Exit ========================================
11. Sample Output - Process Creation
--- PROCESS CREATION ---

Parent Process Parent PID : 2450 Child PID : 2451

Child Process Created Child PID : 2451 Child PPID : 2450

Parent: Child process completed.

12. Sample Output - exec()
--- EXEC DEMONSTRATION ---

Child before exec() Child PID: 2500

--- CHILD PROGRAM EXECUTED USING exec() --- Program Name : child Process PID : 2500 Parent PID : 2499

The child process has successfully replaced its program.

Parent: Child execution completed.

13. Sample Output - Normal Termination
--- NORMAL TERMINATION ---

Child Process PID: 2601 Child is terminating normally.

Parent received child termination. Exit Status: 0

14. Sample Output - Abnormal Termination
--- ABNORMAL TERMINATION ---

Child PID: 2701 Child will be terminated by SIGTERM.

Child terminated abnormally. Signal Number: 15

15. Zombie Process
When the child terminates before the parent calls wait(), the child temporarily remains as a zombie.

The parent eventually calls wait() and collects the child's status.

This removes the zombie process.

16. Orphan Process
When a parent terminates before its child, the child becomes an orphan.

The child continues execution and is adopted by another system process.

The child's PPID changes after the original parent terminates.

17. Advantages
Easy to understand process lifecycle.
Provides practical understanding of Linux system calls.
Demonstrates parent-child relationships.
Shows PID and PPID information.
Demonstrates normal and abnormal termination.
Provides practical examples of zombie and orphan processes.
18. Limitations
The project is designed mainly for Linux/Ubuntu.
It is a demonstration system rather than a complete process manager.
Zombie and orphan behavior depends on the operating system environment.
Process IDs change each time the program is executed.
19. Future Enhancements
The project can be extended with:

Process tree visualization.
Multiple child process creation.
CPU and memory usage monitoring.
Process scheduling simulation.
Process priority management.
Signal handling interface.
Logging of process events.
Graphical user interface.
20. Conclusion
The Linux Process Creation, Execution and Termination System provides a practical demonstration of Linux process management.

The project shows how processes are created using fork(), how programs are replaced using exec(), and how parent processes synchronize with children using wait() and waitpid().

It also demonstrates normal termination, abnormal termination, zombie processes, and orphan processes.

Therefore, the project helps students understand the complete lifecycle of a Linux process through practical experimentation.
