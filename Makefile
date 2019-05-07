#STM8 Makefile

#Compiler
CC = sdcc

#Platform
PLATFORM = stm8

#Project name
TARGET = $(BUILDDIR)/soundboard

#Output directory
BUILDDIR = build
INCDIR = inc
SRCDIR = src

#SDCC handles main file differently from other source files...
MAINSRC = main.c

#Collect sources from source folder
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.rel, $(SRCS))
	   
INCLUDES = -I$(INCDIR)
CFLAGS   = -m$(PLATFORM) --verbose -DDEBUG

#Build recipes
$(BUILDDIR)/%.rel: $(SRCDIR)/%.c
	$(CC) -c $(INCLUDES) $(CFLAGS) -o $@ $^

$(TARGET).ihx: $(OBJS) $(MAINSRC)
	$(CC) $(INCLUDES) $(CFLAGS) $(MAINSRC) $(OBJS) -o $@

$(OBJS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir -p $@

.PHONY:	all clean flash unlock terminal

all: $(TARGET).ihx

clean:
	@echo "Removing intermediate results"
	rm -rf $(BUILDDIR)/*
	@echo "Done."

flash: all
	@echo "Uploading " $(TARGET)".ihx to target..." 
	stm8flash -cstlinkv2 -pstm8s103f3 -w$(TARGET).ihx
	@echo "Done."

unlock:
	@echo "Unlocking MCU:"
	stm8flash -cstlinkv2 -pstm8s103f3 -u
	@echo "Done."

terminal:
	picocom -b 9600 -e b /dev/ttyUSB0
