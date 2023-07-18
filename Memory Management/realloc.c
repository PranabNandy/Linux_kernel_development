#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static void *addr;

static int test_hello_init(void)
{
	addr = kmalloc(4, GFP_KERNEL);
        printk("I got: %zu bytes of memory\n", ksize(addr));
        addr = krealloc(addr, 20, GFP_KERNEL);
        printk("I got: %zu bytes of memory\n", ksize(addr));
        kfree(addr);
	return 0;
}

static void test_hello_exit(void)
{
	printk("Bye for realloc\n\n\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);
