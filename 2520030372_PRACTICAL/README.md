uname -a --> The uname command provides information about the Linux operating system and kernel
lscpu --> The lscpu command displays information about the CPU
lsblk --> The lsblk command displays information about storage devices and block devices
ps --> The ps command displays information about currently running processes
top --> The top command provides real-time information about system activity
The operating system (OS) acts as a bridge between hardware resources and application programs. It manages hardware resources and provides services so that users and applications can use the hardware without directly controlling it.
CPU Abstraction:
The OS abstracts the CPU by providing processes and scheduling. Programs do not need to directly control the CPU. The OS scheduler decides which process gets CPU time.
Memory Abstraction:
The OS provides each process with its own virtual address space. Programs can use memory without needing to know the physical memory locations.
Storage Abstraction:
The OS hides the complexity of physical disks through files, directories, and file systems. Programs work with files rather than directly accessing disk sectors.
I/O Device:
The OS uses device drivers to communicate with hardware such as keyboards, displays, disks, and other devices. Applications use standard system calls instead of directly controlling the hardware.
