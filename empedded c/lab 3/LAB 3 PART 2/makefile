#@copyRight Diaa Abayazeed  
CC=arm-none-eabi-
CFLAGS=-g -mcpu=cortex-m3 -gdwarf-2 
INCS =-I .
LIBS =
SRC =$(wildcard *.c) 
OBJ =$(SRC:.c=.o)
AS =$(wildcard *.s)  
ASOBJ =$(AS:.s=.o) 
PROJECT_NAME =led-toggle-cortex-m3 
  
  
all:led-toggle-cortex-m3.bin
	@echo "**********build done**********"
	
%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

led-toggle-cortex-m3.elf:$(OBJ) $(ASOBJ)	
	$(CC)ld.exe -T LinkerScript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

led-toggle-cortex-m3.bin:led-toggle-cortex-m3.elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.elf *.bin *.o
	
clean:
	rm *.elf *.bin
	
