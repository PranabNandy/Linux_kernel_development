#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/fs.h>

static int my_char_file_open(struct inode *char_test_inode, struct file *my_char_file){
       printk(KERN_NOTICE "My char file is open now\n");
	return 0;
}

static int my_char_file_close(struct inode *char_test_inode, struct file *my_char_file){
       printk(KERN_NOTICE "My char file is close now\n");
	return 0;
}

ssize_t my_char_file_read (struct file *char_test_inode, char __user *buffer, size_t length, loff_t *my_char_offset){
       printk(KERN_NOTICE "My char file is being read now\n");
	return 0;
};

static const struct file_operations my_char_file_operations = {
	.owner = THIS_MODULE,
	.open = my_char_file_open,
	.release = my_char_file_close,
	.read = my_char_file_read,
};

static int __init entry_function(void) {
	printk(KERN_NOTICE "Character Driver from init module\n");
	register_chrdev(200, "Test Character Driver", &my_char_file_operations);	
	return 0;
}

static void __exit exit_function(void) {
	printk("Good bye from exit module\n");
	unregister_chrdev(200, "Test Character Driver");	
}

module_init(entry_function);
module_exit(exit_function);

MODULE_AUTHOR("slashroot");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple character driver module");
