# Process-Info
Operating Systems Homework

# Goal
In this assignment, you will implement a system call to the linux kernel and then you will build it.
After building, you will call your own system call if your program is working in user space. The
detailed scenario is given in the below.

# Implementation Details & Requirements
Your code running into user space should run the system call is named as “processinfo”. Your
program has been worked using four different usages without argument and with three arguments
such as -p, -k and -all separately.

# Additionally, it may be taken as different time with the following parameters:
● without argument, it prints the right usage of this program.
● “-all”, it lists all the processes and some information about them.
● “-p processID”, it outputs the given process ID and its command line.
● “-k processID”, it kills the given process ID.

# The sample executing formats and its functionality shortly.
./processinfo.out >> program’s right usage
./processinfo.out -all >> all processes some information
./processinfo.out -p 1425 >> process and its cmdline
./processinfo.out -k 1425 >> kill process
