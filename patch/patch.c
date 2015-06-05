#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/livepatch.h>
#include <linux/seq_file.h>

static int patch_show(struct seq_file *m, void *v)
{
  seq_printf(m, "%s\n", "Patched.");
  return 0;
}

static struct klp_func funcs[] = {
  {
    .old_name = "patched_show",
    .new_func = patch_show,
  }, {}
};

static struct klp_object objs[] = {
  {
    .name = "patched",
    .funcs = funcs,
  }, {}
};

static struct klp_patch patch = {
  .mod = THIS_MODULE,
  .objs = objs,
};

static int patch_init(void)
{
  return klp_register_patch(&patch);
}

static void patch_exit(void)
{
  klp_disable_patch(&patch);
  klp_unregister_patch(&patch);
}

module_init(patch_init);
module_exit(patch_exit);
MODULE_LICENSE("GPL");
