#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry;


//function that counts the processes running on kernel
static int proc_count(struct seq_file *m, void *v){

	//access the kernel's running process task struct
	struct task_struct *p;

	//counter
	int count = 0;

	//iterate through the processes 
	for_each_process(p) {
	  count++;
	}

	//print number to sequential file with newline char
	seq_printf(m, "%d\n", count);
	return 0;
}

static int __init proc_count_init(void)
{
	entry = proc_create_single("count", 0, NULL, proc_count);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Anika Balakrishnan");
MODULE_DESCRIPTION("CS111 lab0 count proc number");
MODULE_LICENSE("GPL");
