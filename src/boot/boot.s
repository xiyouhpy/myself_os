; ----------------------------------------------------------------
;
; 	boot.s -- 内核从这里开始
;
;                 这里还有根据 GRUB Multiboot 规范的一些定义
;
; ----------------------------------------------------------------

MBOOT_HEADER_MAGIC 	equ 	0x1BADB002						; Multiboot 魔数，由规范决定的,用来标识多重兼容内核
MBOOT_PAGE_ALIGN 	equ 	1 << 0							; 0 号位表示所有的引导模块将按页(4KB)边界对齐
MBOOT_MEM_INFO 		equ 	1 << 1							; 1 号位通过 Multiboot 信息结构的 mem_* 域包括可用内存的信息(一般的ELF映像这样就可以)


; 定义我们使用的 multiboot 的标记
MBOOT_HEADER_FLAGS 	equ 	MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO



; MBOOT_PAGE_ALIGN GRUB页对齐核心部分，MBOOT_MEM_INFO 内存信息
; 域checksum是一个32位的无符号值，当与其他的magic域(也就是magic和flags)相加时，
; 要求其结果必须是32位的无符号值 0 (即magic + flags + checksum = 0)
; MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS +MBOOT_CHECKSUM = 0,这个可以看作是检错标志
MBOOT_CHECKSUM 		equ 	- (MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)



; 符合Multiboot规范的 OS 映象需要这样一个 magic Multiboot 头
; Multiboot 头的分布必须如下表所示：
; ----------------------------------------------------------
; 偏移量  类型  域名        备注
;
;   0     u32   magic       必需
;   4     u32   flags       必需 
;   8     u32   checksum    必需 
;
; 我们只使用到这些就够了，更多的详细说明请参阅 GNU 相关文档
;-----------------------------------------------------------

[BITS 32]  	; 所有代码以 32-bit 的方式编译

section .text 	; 代码段从这里开始

; 在代码段的起始位置设置符合 multiboot 规范的标记

dd MBOOT_HEADER_MAGIC										; GRUB 会通过这个魔数判断该映像是否支持
dd MBOOT_HEADER_FLAGS										; GRUB 的一些加载时选项，其详细注释在定义处
dd MBOOT_CHECKSUM											; 检测数值，其含义在定义处

[GLOBAL start]												; 内核代码入口，此处提供该声明给 ld 链接器
[EXTERN hpy_main]											; 声明内核 C 代码的入口函数


; code, bss, end, start 这些符号定义的连接器用来告诉GRUB我们的内核的不同部位，在启动时进行加载
start:
	cli														; 此时还没有设置好保护模式的中断处理，所以必须关闭中断
	mov esp, stack											; 设置内核栈地址，按照 multiboot 规范，当需要使用堆栈时，OS映象必须自己创建一个
	push ebx												; 调用内核 main 函数的参数，struct multiboot *mboot_ptr
	mov ebp, 0												; 帧指针修改为 0
		
	call hpy_main											; 调用内核入口函数

stop:
	hlt														; 停机指令，什么也不做，可以降低 CPU 功耗
	jmp stop												; 到这里结束，这是个死循环
.end:


section .bss												; 未初始化的数据段从这里开始
    resb 32768												; 这里32KB作为内核栈
stack:


