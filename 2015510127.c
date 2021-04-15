#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <asm/siginfo.h>
#include <linux/pid_namespace.h>
#include <linux/pid.h>
#include <linux/sched/signal.h>

char* concat(const char *string1, const char *string2)
{
    char* result = vmalloc(strlen(string1) + strlen(string2) + 1);
    strcpy(result, string1);
    strcat(result, string2);
    return result;
}

SYSCALL_DEFINE2(init, int, argc, char**, argv)
{
    if(argc == 1){
        printk("Right Usage:\n\t-all prints some information (process id and its argument/s) about all processes\n\t-p takes process id and prints the details of it\n\t-k takes process id\n");
    }
    else if(strcmp(argv[1],"-all") == 0 && argc == 2){
        printk("Process id and the argument list for the processes:");

        struct task_struct *task;
	struct mm_struct *mm;
        for_each_process(task) {
          printk(KERN_INFO "%d \t %d\t %s \n",task->pid, task_ppid_nr(task), task->comm);
        }
    }
    else if(strcmp(argv[1],"-p") == 0 && argc == 3){
        struct task_struct *task;
        int pID;
        sscanf(argv[2], "%d", &pID);
        task = find_task_by_vpid(pID);
        printk("Argument#[%d]-Process Information:",pID);
        printk("\n %d\t%s \n",task->pid,task->comm);
    }
    else if(strcmp(argv[1],"-k") == 0 && argc == 3){

        struct task_struct *task;
        int signum = SIGKILL;
        int pID;
        sscanf(argv[2], "%d", &pID);
        task = find_task_by_vpid(pID);
        struct siginfo info;
        memset(&info, 0, sizeof(struct siginfo));
        info.si_signo = signum;
        int ret = send_sig_info(signum, &info, task);   
        if (ret < 0) {
            printk(KERN_INFO "error sending signal\n");
        }
        else{
            printk("Process %d was killed...",pID);
        }
    }
    return 0;
}
