/*************************************************************************
    > File Name: panic.h
    > Author: 韩佩言
    > Mail: xiyouhanpeiyan@gmail.com 
    > Created Time: 2013年11月18日 星期一 15时01分36秒
    > Class: 计科1107
 ************************************************************************/
// 打印栈信息

#ifndef INCLUDE_PANIC_H_
#define INCLUDE_PANIC_H_

void panic(const char *msg);

void print_stack_trace()
{
	uint32_t *ebp, *eip;
	asm volatile("mov %%ebp, %0" : "=r" (ebp));

	while (ebp)
	{
		eip = ebp + 1;
		printk("   [0x%x]\n", *eip);
		ebp = (uint32_t *)*ebp;
	}
}

#endif 	// INCLUDE_PANIC_H_
