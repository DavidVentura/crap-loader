SECTIONS
{
	.host_functionality 0x0aaaaaa0:
	{
		KEEP(*(.host_functionality))
	}
	.guest_functionality 0x0aaaaab0:
	{
		KEEP(*(.guest_functionality))
	}
	.guest_init 0x0aaaccc0:
	{
		KEEP(*(.guest_init))
	}
}
INSERT AFTER .rodata;
