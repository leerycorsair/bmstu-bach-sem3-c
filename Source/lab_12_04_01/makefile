CC = gcc
INCPATH = ./inc/
OUTPATH = ./out/
SRCPATH = ./src/
FUNCTESTPATH = ./func_tests/
UNITTESTPATH = ./unit_tests/
LIBPATH = ./lib/

CFLAGS = -std=c99 -I$(INCPATH) -DNDEBUG -g0 -c
ST_LIB_FLAGS = -lsfile_io -lsarr
DL_FLAGS = -ldlfile_io -ldlarr
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

static: COMP_FLAG = -DSTATIC
static: dirs $(OUTPATH)main.o $(LIBPATH)libsfile_io.a $(LIBPATH)libsarr.a
	gcc -o app.exe $(OUTPATH)main.o -L$(LIBPATH) $(ST_LIB_FLAGS)

$(OUTPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) $(COMP_FLAG) -o $@ $^

$(LIBPATH)libsfile_io.a:$(OUTPATH)file_io_lib_st.o
	ar r $@ $<

$(OUTPATH)file_io_lib_st.o:$(SRCPATH)file_io_lib.c
	$(CC) $(CFLAGS) -DSTATIC -o $@ $<

$(LIBPATH)libsarr.a:$(OUTPATH)arr_lib_st.o
	ar r $@ $<

$(OUTPATH)arr_lib_st.o:$(SRCPATH)arr_lib.c
	$(CC) $(CFLAGS) -DSTATIC -o $@ $<

dynamic_link: COMP_FLAG = -DIMPORT
dynamic_link: dirs $(OUTPATH)main.o $(LIBPATH)dlfile_io.dll $(LIBPATH)dlarr.dll
	$(CC) -o app.exe $(OUTPATH)main.o -L$(LIBPATH) $(DL_FLAGS)

$(LIBPATH)dlfile_io.dll: $(OUTPATH)file_io_lib_dl.o
	$(CC) -shared $< -Wl,--subsystem,windows -o $@
	cp $(LIBPATH)dlfile_io.dll ./dlfile_io.dll

$(LIBPATH)dlarr.dll: $(OUTPATH)arr_lib_dl.o
	$(CC) -shared $< -Wl,--subsystem,windows -o $@
	cp $(LIBPATH)dlarr.dll ./dlarr.dll

$(OUTPATH)arr_lib_dl.o:$(SRCPATH)arr_lib.c
	$(CC) $(CFLAGS) -DEXPORT -o $@ $<

$(OUTPATH)file_io_lib_dl.o:$(SRCPATH)file_io_lib.c
	$(CC) $(CFLAGS) -DEXPORT -o $@ $<

dynamic_export: COMP_FLAG = -DDYN_EXPORT
dynamic_export: dirs $(OUTPATH)main.o $(LIBPATH)dlfile_io.dll $(LIBPATH)dlarr.dll
	$(CC) -o app.exe  $(OUTPATH)main.o

func: app.exe 
	cd $(FUNCTESTPATH) && cmd //C all_test.cmd
	
unit: unit_tests.exe
	./unit_tests.exe
	
unit_tests.exe: COMP_FLAG = -DIMPORT
unit_tests.exe: dirs $(OUTPATH)check_arr_lib.o $(LIBPATH)dlarr.dll
	gcc -o $@ $(OUTPATH)check_arr_lib.o -L$(LIBPATH) -ldlarr -lcheck 
	
$(OUTPATH)check_arr_lib.o: $(UNITTESTPATH)check_arr_lib.c
	$(CC) $(UCFLAGS) $(COMP_FLAG) -o $@ $<
	
dirs: $(INCPATH) $(OUTPATH) $(SRCPATH) $(FUNCTESTPATH) $(UNITTESTPATH) $(LIBPATH)

$(INCPATH):
	mkdir $@

$(OUTPATH):
	mkdir $@

$(SRCPATH):
	mkdir $@

$(FUNCTESTPATH):
	mkdir $@

$(UNITTESTPATH):
	mkdir $@

$(LIBPATH):
	mkdir $@	