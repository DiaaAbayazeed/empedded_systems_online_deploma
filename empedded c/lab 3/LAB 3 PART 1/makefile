#@copyRight Diaa Abayazeed  
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s 
INCS =-I .
LIBS =
SRC =$(wildcard *.c) 
OBJ =$(SRC:.c=.o)
AS =$(wildcard *.s)  
ASOBJ =$(AS:.s=.o) 
PROJECT_NAME =learn_in_depth 
  
  
all:learn_in_depth.bin
	@echo "**********build done**********"
	
%.o:%.s
	$(CC)as.exe $(CFLAGS)$(INCS) $< -o $@

%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

learn_in_depth.elf:$(OBJ) $(ASOBJ)	
	$(CC)ld.exe -T LinkerScript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

learn_in_depth.bin:learn_in_depth.elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.elf *.bin *.o
	
clean:
	rm *.elf *.bin
	
