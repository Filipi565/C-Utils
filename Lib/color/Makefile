COMPILER = gcc

ifeq ($(OS), Windows_NT)
	DELETE_COMMAND = del
	OPTIONCHAR = /
else
	DELETE_COMMAND = rm
	OPTIONCHAR = -
endif

CFLAGS = $(OPTIONCHAR)I../../Include $(OPTIONCHAR)c

final: helper.o setcolor.o
	@ar rs ../color.a helper.o setcolor.o

all: final clean

helper.o:
	@$(COMPILER) $(CFLAGS) helper.c $(OPTIONCHAR)c helper.o

setcolor.o: 
	@$(COMPILER) $(CFLAGS) setcolor.c $(OPTIONCHAR)c setcolor.o

clean:
	@$(DELETE_COMMAND) *.o