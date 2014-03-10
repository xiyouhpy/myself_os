/*
 *      kernel.ld 链接脚本，这个脚本告诉内核如何构造映像文件
 *
 *		声明内核程序的入口地址：start
 *		
 *		声明了第一个段 .text 段（代码段）和它的起始地址 0x100000（1MB）。
 *      
 *      声明已初始化数据段 .data 和 未初始化数据段 .bss 和 4K 的页对齐方式。
 *      
 *      Linux GCC 增加了额外的数据段 .rodata，这是一个只读的已初始化数据段，放置常量什么的。
 *      简单起见，我们把和 .data 段放在一起好了。
 */

ENTRY(start)
SECTIONS
{
  .text 0x100000 :
  {
    code = .; _code = .; __code = .;
    *(.text)
    . = ALIGN(4096);
  }

  .data :
  {
     data = .; _data = .; __data = .;
     *(.data)
     *(.rodata)
     . = ALIGN(4096);
  }

  .bss :
  {
    bss = .; _bss = .; __bss = .;
    *(.bss)
    . = ALIGN(4096);
  }

  end = .; _end = .; __end = .;

  /DISCARD/ : { *(.comment) *(.eh_frame) }
}

