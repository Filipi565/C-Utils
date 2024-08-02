COMPILER = gcc

ifeq ($(OS), Windows_NT)
	DELETE_COMMAND = del
	OPTIONCHAR = /
else
	DELETE_COMMAND = rm
	OPTIONCHAR = -
endif

CFLAGS = $(OPTIONCHAR)I../../Include $(OPTIONCHAR)c

final: cwd.o dirs.o exists.o join.o path_struct.o
	@ar rs ../path.a cwd.o dirs.o exists.o join.o path_struct.o

all: final clean

cwd.o:
	@$(COMPILER) $(CFLAGS) cwd.c $(OPTIONCHAR)o cwd.o

dirs.o:
	@$(COMPILER) $(CFLAGS) dirs.c $(OPTIONCHAR)o dirs.o

exists.o:
	@$(COMPILER) $(CFLAGS) exists.c $(OPTIONCHAR)o exists.o

join.o:
	@$(COMPILER) $(CFLAGS) join.c $(OPTIONCHAR)o join.o

path_struct.o:
	@$(COMPILER) $(CFLAGS) path_struct.c $(OPTIONCHAR)o path_struct.o

clean: 
	@$(DELETE_COMMAND) *.o