/*************************************************************************
    > File Name: hpy_main.c
    > Author: 韩佩言
    > Mail: xiyouhanpeiyan@gmail.com 
    > Created Time: 2013年11月18日 星期一 15时01分36秒
    > Class: 计科1107
 ************************************************************************/
// 内核入口函数

#include "multiboot.h"
#include "common.h"
#include "monitor.h"
#include "types.h"

int hpy_main()
{
	monitor_clear();
	monitor_write("hello world!\n");
	init_gdt();
	init_idt();
	asm volatile ("int $0x3");
	
	return 0;
}

