#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/fs.h>
ssize_t simple_write (struct file *a, const char __user *b, size_t c, loff_t *d){
	printk("write Driver 3 \n");
	return (ssize_t)0;

}

ssize_t simple_read (struct file *a, char __user *b, size_t c, loff_t *d){
	printk("Read Driver 3 \n");
	return (ssize_t)0;

}
int simple_open (struct inode *a, struct file *b){
 	printk("OPEN Driver 3 \n");
	return 0;
}
int simple_release (struct inode *a, struct file *b){
	printk("RELEASE Driver 3 \n");
	return 0;
}
static const struct file_operations file_ops= {    // for the register driver file operation mentioned                      
        .owner   = THIS_MODULE,    
        .open		= simple_open,   // respective file operation for "cat /dev/driver3_pranab_nandy"
	    .release	=  simple_release, 
	    .read= simple_read,                                    
        .write= simple_write,                       
};
static int  __init entry_function(void){
	printk("hello Driver 3 init function\n");
	register_chrdev(199,"foo_pranab_nandy",&file_ops); // we have to register a driver to /proc/devices
	return 0;
}

static void __exit exit_function(void){
	printk("bye bye Driver 3 function\n");
	unregister_chrdev(199,"foo_pranab_nandy"); // we have to register a driver to /proc/devices
	
}



module_init(entry_function);
module_exit(exit_function);


MODULE_AUTHOR("pranab");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("my_first_module");


/* command */
// sudo make -C /usr/src/linux-headers-5.15.0-76-generic/ M=/home/pranab/Linux_kernel/
// sudo insmod driver3.ko
// sudo rmmod driver3.ko
// cat /dev/driver3_pranab_nandy  // sudo mknod /dev/driver3_pranab_nandy c 199 1
// cat /proc/devices    // check "199 foo_pranab_nandy"
// sudo dmesg -c 
// sudo tail -f /var/log/syslog/   // system log information
//ls /sys/module/    //lsmod
//cat /proc/modules/driver3    //status of the module
// grep driver3 /proc/kallsyms      // kernel symbol for driver3

//----- some imporant header files are
// /include/linux/kern_levels.h 
// /include/linux//printk.h  
// /include/linux//fs.h  


//------------ extra command
// cat /proc/sys/kernel/printk     // log level of console driver and printk 
// strace hello.out
// uname -r
//sudo apt-get install linux-kernel-headers


// --------- Important for linux
// https://elixir.bootlin.com/linux/latest/source

// git commit -s -v
