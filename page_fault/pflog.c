#include <linux/debugfs.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#include "pflog.h"

struct dentry *dir, *file;


// Emulate page fault handling
static ssize_t pflog_call(struct file *file, const char __user *buf, size_t count, loff_t *ppos) {

}

static ssize_t pflog_return(struct file *file, char _user *userbuf, size_t count, loff_t * ppos)
{
	return 0;
}

// Define the read/write operation of the created file
static const struct file_operations my_fops = {
	.read = pflog_return,
	.write = pflog_call,
};

static int __init pflog_module_init(void) {
	// Create debugfs directory
	dir = debugfs_create_dir();
	if(dir == NULL)
	{
		return -ENODEV;
	}

	// Create file and give everyone rw access
	file = debugfs_create_file();


	if(file == NULL)
	{
		return -ENODEV;
	}

	return 0;
}

static void __exit pflog_module_exit(void) {

}

module_init();
module_exit();
MODULE_LICENSE("GPL");
