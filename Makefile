TARGET = kfs.bin

CC = gcc
ASM = nasm
LD = ld

SRC_DIR = src
SRC_C = $(wildcard $(SRC_DIR)/*.c)
SRC_ASM = $(wildcard $(SRC_DIR)/*.asm)
SRC_LD = linker.ld

ASMFLAGS = -f elf32
CFLAGS = -Wall -Wextra -m32 -ffreestanding -fno-builtin -fno-stack-protector -nostdlib
LDFLAGS = -m elf_i386 -T $(SRC_LD)

OBJ_C = $(SRC_C:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
OBJ_ASM = $(SRC_ASM:$(SRC_DIR)/%.asm=$(SRC_DIR)/%.o)
OBJ = $(OBJ_C) $(OBJ_ASM)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJ)
	mv $(TARGET) kfs/boot/$(TARGET)
	grub-mkrescue -o KFS.iso kfs/

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o

fclean: clean
	rm -f kfs/boot/$(TARGET) KFS.iso

re: fclean all
