/*************************************************************************
    > File Name: debug.h
    > Author: 韩佩言
    > Mail: xiyouhanpeiyan@gmail.com 
    > Created Time: 2013年11月18日 星期一 15时01分36秒
    > Class: 计科1107
 ************************************************************************/
// debug 调试相关函数

#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_

#include "elf.h"
#include "panic.h"
#include "printk.h"

// 打印当前的段存器值
void print_cur_status();

#endif 	// INCLUDE_DEBUG_H_
