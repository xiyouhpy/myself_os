/*************************************************************************
    > File Name: printk.h
    > Author: 韩佩言
    > Mail: xiyouhanpeiyan@gmail.com 
    > Created Time: 2013年11月18日 星期一 15时01分36秒
    > Class: 计科1107
 ************************************************************************/
// 内核打印函数

#ifndef INCLUDE_PRINTK_H_
#define INCLUDE_PRINTK_H_

#include "monitor.h"
#include "vargs.h"

// 内核的打印函数
void printk(const char *format, ...);

void printk_color(real_color_t back, real_color_t fore, const char *format, ...);

int vsprintf(char *buff, const char *format, va_list args);

#endif 	// INCLUDE_PRINTK_H_
