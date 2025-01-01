run: OS.iso
	qemu-system-x86_64 -cdrom OS.iso
debug: OS.iso
	qemu-system-i386 -s -S -cdrom OS.iso &
	gdb OS/boot/kernel -ex "target remote localhost:1234"
all: kernel.bin OS.iso

kernel.o: kernel.c
	gcc -m32 -g -fno-stack-protector -fno-builtin -c kernel.c -o objects/kernel.o

io.o: drivers/stdio.c
	gcc -m32 -g -fno-stack-protector -fno-builtin -c drivers/stdio.c -o objects/stdio.o

cpu.o : drivers/cpu.c
	gcc -m32 -g -fno-stack-protector -fno-builtin -c drivers/cpu.c -o objects/cpu.o

boot.o: boot.s
	nasm -f elf32 boot.s -o objects/boot.o

kernel.bin: kernel.o io.o boot.o cpu.o linker.ld
	ld -m elf_i386 -T linker.ld -o kernel objects/stdio.o objects/cpu.o objects/kernel.o objects/boot.o
	cp kernel OS/boot

OS.iso: kernel.bin
	grub-mkrescue -o OS.iso OS/

clean:
	rm -f *.o
	rm -f OS/boot/kernel
	rm -f OS.iso
	rm -f kernel