#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define DEVICE_NAME "linux_sentinel"
#define CLASS_NAME  "linux_sentinel_class"

static dev_t device_number;
static struct cdev sentinel_cdev;
static struct class *sentinel_class;
static struct device *sentinel_device;

static DEFINE_MUTEX(sentinel_mutex);

static char device_status[64] = "DEVICE_OK\n";

static int sentinel_open(struct inode *inode, struct file *file)
{
    pr_info("Linux Sentinel: device opened\n");
    return 0;
}

static ssize_t sentinel_read(struct file *file,
                             char __user *buffer,
                             size_t length,
                             loff_t *offset)
{
    size_t status_length;
    ssize_t result;

    if (*offset != 0)
    {
        return 0;
    }

    if (mutex_lock_interruptible(&sentinel_mutex))
    {
        return -ERESTARTSYS;
    }

    status_length = strlen(device_status);

    if (length < status_length)
    {
        mutex_unlock(&sentinel_mutex);
        return -EINVAL;
    }

    if (copy_to_user(buffer, device_status, status_length))
    {
        mutex_unlock(&sentinel_mutex);
        return -EFAULT;
    }

    *offset += status_length;
    result = status_length;

    mutex_unlock(&sentinel_mutex);

    return result;
}

static ssize_t sentinel_write(struct file *file,
                              const char __user *buffer,
                              size_t length,
                              loff_t *offset)
{
    char command[64];
    size_t copy_length;

    copy_length = min(length, sizeof(command) - 1);

    if (copy_from_user(command, buffer, copy_length))
    {
        return -EFAULT;
    }

    command[copy_length] = '\0';

    if (mutex_lock_interruptible(&sentinel_mutex))
    {
        return -ERESTARTSYS;
    }

    if (strncmp(command, "RESET", 5) == 0)
    {
        strcpy(device_status, "DEVICE_RESET\n");
    }
    else if (strncmp(command, "START", 5) == 0)
    {
        strcpy(device_status, "DEVICE_STARTED\n");
    }
    else if (strncmp(command, "STOP", 4) == 0)
    {
        strcpy(device_status, "DEVICE_STOPPED\n");
    }
    else
    {
        strcpy(device_status, "UNKNOWN_COMMAND\n");
    }

    mutex_unlock(&sentinel_mutex);

    pr_info("Linux Sentinel: command received: %s", command);

    return length;
}

static int sentinel_release(struct inode *inode, struct file *file)
{
    pr_info("Linux Sentinel: device closed\n");
    return 0;
}

static const struct file_operations sentinel_fops =
{
    .owner = THIS_MODULE,
    .open = sentinel_open,
    .read = sentinel_read,
    .write = sentinel_write,
    .release = sentinel_release
};

static int __init sentinel_init(void)
{
    int result;

    result = alloc_chrdev_region(&device_number, 0, 1, DEVICE_NAME);

    if (result < 0)
    {
        pr_err("Linux Sentinel: failed to allocate device number\n");
        return result;
    }

    cdev_init(&sentinel_cdev, &sentinel_fops);

    result = cdev_add(&sentinel_cdev, device_number, 1);

    if (result < 0)
    {
        unregister_chrdev_region(device_number, 1);
        return result;
    }

    sentinel_class = class_create(CLASS_NAME);

    if (IS_ERR(sentinel_class))
    {
        cdev_del(&sentinel_cdev);
        unregister_chrdev_region(device_number, 1);
        return PTR_ERR(sentinel_class);
    }

    sentinel_device = device_create(
        sentinel_class,
        NULL,
        device_number,
        NULL,
        DEVICE_NAME
    );

    if (IS_ERR(sentinel_device))
    {
        class_destroy(sentinel_class);
        cdev_del(&sentinel_cdev);
        unregister_chrdev_region(device_number, 1);
        return PTR_ERR(sentinel_device);
    }

    pr_info("Linux Sentinel: driver loaded successfully\n");
    pr_info("Linux Sentinel: device /dev/%s created\n", DEVICE_NAME);

    return 0;
}

static void __exit sentinel_exit(void)
{
    device_destroy(sentinel_class, device_number);
    class_destroy(sentinel_class);
    cdev_del(&sentinel_cdev);
    unregister_chrdev_region(device_number, 1);

    pr_info("Linux Sentinel: driver unloaded\n");
}

module_init(sentinel_init);
module_exit(sentinel_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gayatree Sahoo");
MODULE_DESCRIPTION("Linux Sentinel virtual character device driver");
MODULE_VERSION("1.0");
