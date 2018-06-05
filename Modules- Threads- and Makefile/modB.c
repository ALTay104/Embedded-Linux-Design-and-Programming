#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/kthread.h>
#include <linux/param.h>
#include <linux/sched.h>

static struct task_struct *kthread;
extern int my_flagCount;

static int flagCount(void * data)
{
	printk("::Inside Thread Function::\n");
	printk(KERN_INFO "%d.\n", my_flagCount++);
	schedule_timeout(30*HZ); // sleep for 30 seconds.
	printk(" Exiting Thread Function::");	
	
	return 0;
}

int my_module_init( void )
{
	kthread = kthread_run(flagCount, NULL, "mythread");
	return 0;
}

void my_module_exit( void )
{
	printk("Counter thread has stopped\n");
	kthread_stop(kthread);
} 

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_AUTHOR("Mod Example");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Thread to increment flag_counts.");