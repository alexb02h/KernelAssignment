#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/seq_file.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");

static int proc_show(struct seq_file *m,void *v){
	unsigned long z[NR_VM_EVENT_ITEMS];
	all_vm_events(z);
	seq_printf(m,"%llu\n",(unsigned long long) z[PGFAULT]);
	return 0;
}
static int __init createproc(void){
	struct proc_dir_entry *npf;
	npf = proc_create_single("numpagefaults",0,NULL,proc_show);
	return 0;
}
static void __exit exit_proc(void){
	remove_proc_entry("numpagefaults",NULL);
}

module_init(createproc);
module_exit(exit_proc);

MODULE_LICENSE("GPL");
