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
	// 初始化全局段描述符表
	init_gdt();
	// 初始化全局中断描述符表
	init_idt();
	
	// 清屏
	monitor_clear();
	printk_color(rc_black, rc_red, "***********************************\n");
	printk_color(rc_black, rc_red, "*     Hello, everyone.    *\n");
	printk_color(rc_black, rc_red, "***********************************\n\n");
	printk_color(rc_black, rc_blue, "This is a kernel and the auther is Hanpeiyan.\n\n");
	asm volatile ("int $0x3");
	
	return 0;
}

