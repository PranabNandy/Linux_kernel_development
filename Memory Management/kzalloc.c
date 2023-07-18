#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>


MODULE_AUTHOR("pranab");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("my_first_module");

static char *ptr;
int alloc_size = 10;

module_param(alloc_size, int, 0);

static int test_hello_init(void)
{
	ptr = kmalloc(alloc_size,GFP_ATOMIC);
	if(!ptr) {
		/* handle error */
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	} else {
		pr_info("kmalloc Memory allocated successfully:%px\n", ptr);
		pr_info("Content of ptr+2 is %d\n", *(ptr+2));
		pr_info("Content of ptr+102 is %d\n", *(ptr+102));
	}
	kfree(ptr);
	//alloc_size=alloc_size+2;
	ptr = kzalloc(alloc_size+2,GFP_ATOMIC);
	if(!ptr) {
		/* handle error */
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	} else {
		pr_info("kzalloc Memory allocated successfully:%px\n", ptr);
		pr_info("Content of ptr+2 is %d\n", *(ptr+2));
		pr_info("Content of ptr+102 is %d\n", *(ptr+102));
	}
	kfree(ptr);

	return 0;
}

static void test_hello_exit(void)
{
	pr_info("kzalloc kmalloc\n", ptr);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
