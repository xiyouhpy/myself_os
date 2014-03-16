/*************************************************************************
    > File Name: common.c
    > Author: 韩佩言
    > Mail: xiyouhanpeiyan@gmail.com 
    > Created Time: 2013年11月18日 星期一 15时01分36秒
    > Class: 计科1107
 ************************************************************************/
// 屏幕打印函数

#include "common.h"

// 端口写一个字节
void outb(uint16_t port, uint8_t value)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

// 端口读一个字节
uint8_t inb(uint16_t port)
{
	uint8_t ret;

	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));

	return ret;
}

// 端口读一个字
uint16_t inw(uint16_t port)
{
	uint16_t ret;

	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));

	return ret;
}

