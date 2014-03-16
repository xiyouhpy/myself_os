/*************************************************************************
    > File Name: types.h
    > Author: 韩佩言
    > Mail: xiyouhanpeiyan@gmail.com 
    > Created Time: 2013年11月18日 星期一 15时01分36秒
    > Class: 计科1107
 ************************************************************************/
// 基础类型的定义

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_

#ifndef NULL
	#define NULL 0
#endif

#ifndef TRUE
	#define TRUE  1
	#define FALSE 0
#endif

typedef unsigned int   uint32_t;
typedef          int   int32_t;
typedef unsigned short uint16_t;
typedef          short int16_t;
typedef unsigned char  uint8_t;
typedef          char  int8_t;

// 进程标识符
typedef uint32_t pid_t;

#endif 	// INCLUDE_TYPES_H_
