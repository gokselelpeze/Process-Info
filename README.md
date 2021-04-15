# Process-Info
Implement a system call to the linux kernel and then build it.

Operating Systems Homework

# Goal
In this assignment, you will implement a system call to the linux kernel and then you will build it.
After building, you will call your own system call if your program is working in user space. The
detailed scenario is given in the below.

# Implementation Details & Requirements
Your code running into user space should run the system call is named as “processinfo”. Your
program has been worked using four different usages without argument and with three arguments
such as -p, -k and -all separately.

# Additionally, it may be taken as different time with the following parameters:<br>
● without argument, it prints the right usage of this program.<br>
● “-all”, it lists all the processes and some information about them.<br>
● “-p processID”, it outputs the given process ID and its command line.<br>
● “-k processID”, it kills the given process ID.<br>

# The sample executing formats and its functionality shortly.<br>
./processinfo.out >> program’s right usage<br>
./processinfo.out -all >> all processes some information<br>
./processinfo.out -p 1425 >> process and its cmdline<br>
./processinfo.out -k 1425 >> kill process<br>
