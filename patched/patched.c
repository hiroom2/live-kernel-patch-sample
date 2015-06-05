#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int patched_show(struct seq_file *m, void *v)
{
  seq_printf(m, "%s\n", "Not patched yet.");
  return 0;
}

static int patched_open(struct inode *inode, struct file *file)
{
  return single_open(file, patched_show, NULL);
}

static const struct file_operations patched_fops = {
  .open = patched_open,
  .read = seq_read,
  .llseek = seq_lseek,
  .release = single_release,
};

static int patched_init(void)
{
  proc_create("patched", 0, NULL, &patched_fops);
  return 0;
}

static void patched_exit(void)
{
  remove_proc_entry("patched", NULL);
}

module_init(patched_init);
module_exit(patched_exit);
