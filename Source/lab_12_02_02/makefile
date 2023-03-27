CC = gcc
INCPATH = ./inc/
OUTPATH = ./out/
SRCPATH = ./src/
UNITTESTPATH = ./unit_tests/
LIBPATH = ./lib/

CFLAGS = -std=c99 -I$(INCPATH) -DNDEBUG -g0 -c
B_FLAGS = -ldlarr
ULFLAGS = -lfile_io -larr
UCFLAGS = -std=c99 -I$(INCPATH) -Werror -Wall -Wpedantic -Wextra -c

.PHONY: clean

clean: 
	rm -fv *.exe
	rm -fv *.dll
	rm -fv $(OUTPATH)*.o
	rm -fv $(OUTPATH)*.gcno
	rm -fv $(OUTPATH)*.gcda
	rm -fv $(LIBPATH)*.a
	rm -fv $(LIBPATH)*.dll


build: COMP_FLAG = -DIMPORT
build: dirs $(LIBPATH)dlarr.dll

$(LIBPATH)dlarr.dll: $(OUTPATH)arr_lib_dl.o
	$(CC) -shared $< -Wl,--subsystem,windows -o $@
	cp $(LIBPATH)dlarr.dll ./dlarr.dll

$(OUTPATH)arr_lib_dl.o:$(SRCPATH)arr_lib.c
	$(CC) $(CFLAGS) -DEXPORT -o $@ $<

	
unit: unit_tests.exe
	./unit_tests.exe
	
unit_tests.exe: COMP_FLAG = -DIMPORT
unit_tests.exe: dirs $(OUTPATH)check_arr_lib.o $(LIBPATH)dlarr.dll
	gcc -o $@ $(OUTPATH)check_arr_lib.o -L$(LIBPATH) -ldlarr -lcheck 
	
$(OUTPATH)check_arr_lib.o: $(UNITTESTPATH)check_arr_lib.c
	$(CC) $(UCFLAGS) $(COMP_FLAG) -o $@ $<
	
dirs: $(INCPATH) $(OUTPATH) $(SRCPATH) $(UNITTESTPATH) $(LIBPATH)

$(INCPATH):
	mkdir $@

$(OUTPATH):
	mkdir $@

$(SRCPATH):
	mkdir $@


$(UNITTESTPATH):
	mkdir $@

$(LIBPATH):
	mkdir $@	