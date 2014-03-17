; -------------------------------------------------
; 	将 GDT 地址 载入 GDTR
;
; 	hurley 2013/10/18
;
; -------------------------------------------------

[GLOBAL gdt_flush]

gdt_flush:
	mov eax, [esp+4]  ; 得到 GDT 的指针并作为参数存入 eax 寄存器
	lgdt [eax]        ; 加载到 GDTR [修改原先GRUB设置]

	mov ax, 0x10      ; 加载我们的数据段描述符,0x10 是我们 GDT 数据段的偏移
	mov ds, ax        ; 更新所有可以更新的段寄存器
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush   ; 远跳转，0x08是我们的代码段描述符
			  ; 远跳目的是清空流水线并串行化处理器
.flush:
	ret
.end:
