#@copyRight Diaa Abayazeed  
CC=arm-none-eabi-
CFLAGS=-g -mcpu=cortex-m3 -gdwarf-2 
INCS =-I .
LIBS =
SRC =$(wildcard *.c) 
OBJ =$(SRC:.c=.o)
AS =$(wildcard *.s)  
ASOBJ =$(AS:.s=.o) 
PROJECT_NAME =High_Pressure_Detection 
  
  
all:High_Pressure_Detection.bin
	@echo "**********build done**********"
%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

High_Pressure_Detection.elf:$(OBJ) $(ASOBJ)	
	$(CC)ld.exe -T LinkerScript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

High_Pressure_Detection.bin:High_Pressure_Detection.elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.elf *.bin *.o
	
clean:
	rm *.elf *.bin
	
