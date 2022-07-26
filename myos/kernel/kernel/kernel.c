#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	
	/*
	To do
	
	Learn interrupts. (This is needed if I'm going to read input from the user.)
	Create a Shell.
	Paging, memory management.
	Create a kernel-space multitasking system. Context switch to user mode.
	Process scheduling.
	Virtual memory.
	Implement file system.
	*/

	printfWithBorder("Hello World.");
}
