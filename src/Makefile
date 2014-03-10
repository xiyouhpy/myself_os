#!Makefile
# 这个是一个小内核的 Makefile
# 作者：韩佩言
# 使用的 C语言编译器是 gcc、使用的汇编语言编译器是 nasm
#

# shell find . -name '*.c' 是调用 shell 脚本查找当前目录下所有的 .c 文件并将其给 C_SOURCES
# patsubst 是将 C_SOURCES 中的 '.c' 用 '.o'取代
C_SOURCES = $(shell find . -name *.c)
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name *.s)
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

CC = gcc
LD = ld
ASM = nasm

C_FLAGS = -c -Wall -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T kernel.ld -m elf_i386
ASM_FLAGS = -f elf

all: $(S_OBJECTS) $(C_OBJECTS) link

# The automatic variable '$<' is just the first prerequisite
.c.o:
	@echo 编译代码文件 $< ...
	$(CC) $(C_FLAGS) $< -o $@

.s.o:
	@echo 编译汇编文件 $< ...
	$(ASM) $(ASM_FLAGS) $< 

link:
	@echo 链接内核文件...
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o hpy_kernel

.PHONY:clean

clean:
	$(RM) $(S_OBJECTS) $(C_OBJECTS) hpy_kernel

.PHONY:update_image

update_image:
	sudo mount floppy.img /mnt/kernel
	sudo cp hpy_kernel /mnt/kernel/hpy_kernel
	sleep 1
	sudo umount /mnt/kernel

.PHONY:mount_image
mount_image:
	sudo mount floppy.img /mnt/kernel

.PHONY:umount_image

umount_image:
	sudo umount /mnt/kernel

.PHONY:run

run:
	bochs -f bochsrc.txt

.PHONY:start

start:
	sudo mount floppy.img /mnt/kernel
	sudo cp hpy_kernel /mnt/kernel/hpy_kernel
	sleep 1
	sudo umount /mnt/kernel
	sleep 1
	bochs -f bochsrc.txt
