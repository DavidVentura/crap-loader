.PHONY: all clean
all: blob program blob_disas
clean:
	rm -f blob program blob_init blob_disas

CFLAGS=-Wall -Werror -g 

blob: loadable_blob.c Makefile script.ld
	gcc -fPIE $(CFLAGS) -T script.ld -c -o $@ loadable_blob.c

program: program.c Makefile script.ld
	gcc $(CFLAGS) -T script.ld -o $@ program.c

blob_init: blob
	objcopy -O binary --only-section=.guest_init $^ $@

blob_disas: blob_init
	ndisasm -p intel -b 64 $^ > $@
