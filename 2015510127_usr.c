#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>


int main(int argc, char **argv)
{

    long int sysId=syscall(336, argc, argv);

    return 0;
}