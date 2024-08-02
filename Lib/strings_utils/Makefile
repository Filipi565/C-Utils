COMPILER = gcc

ifeq ($(OS), Windows_NT)
	DELETE_COMMAND = del
	OPTIONCHAR = /
else
	DELETE_COMMAND = rm
	OPTIONCHAR = -
endif

CFLAGS = $(OPTIONCHAR)I./../include $(OPTIONCHAR)c

final: endswith.o reverse.o startswith.o
	@ar rs ../strings_utils.a endswith.o reverse.o startswith.o

all: final clean

endswith.o:
	@$(COMPILER) $(CFLAGS) endswith.c $(OPTIONCHAR)c endswith.o

startswith.o:
	@$(COMPILER) $(CFLAGS) startswith.c $(OPTIONCHAR)c startswith.o

reverse.o:
	@$(COMPILER) $(CFLAGS) reverse.c $(OPTIONCHAR)c reverse.o

clean:
	@$(DELETE_COMMAND) *.o