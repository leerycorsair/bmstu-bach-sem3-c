CC = gcc
INCPATH = ./inc/
OUTPATH = ./out/
SRCPATH = ./src/
FUNCTESTPATH = ./func_tests/
UNITTESTPATH = ./unit_tests/

CFLAGS = -std=c99 -I$(INCPATH) -DNDEBUG -g0 -c
LFLAGS = 
ULFLAGS = -lcheck
UCFLAGS = -std=c99 -I$(INCPATH) -Werror -Wall -Wpedantic -Wextra -c

.PHONY: clean
.NOTPARALLEL: release debug

release: dirs $(OUTPATH)release.lastbuildstate app.exe

debug: CFLAGS = -std=c99 -I$(INCPATH) -Werror -Wall -Wpedantic -Wextra --coverage -g3 -c
debug: LFLAGS = -lgcov
debug: dirs $(OUTPATH)debug.lastbuildstate app.exe

$(OUTPATH)debug.lastbuildstate:
	rm -fv *.exe
	rm -fv $(OUTPATH)*.o
	rm -fv $(OUTPATH)*.gcno
	rm -fv $(OUTPATH)*.gcda
	rm -fv $(OUTPATH)release.lastbuildstate
	touch $(OUTPATH)debug.lastbuildstate
	
$(OUTPATH)release.lastbuildstate:
	rm -fv *.exe
	rm -fv $(OUTPATH)*.o
	rm -fv $(OUTPATH)*.gcno
	rm -fv $(OUTPATH)*.gcda
	rm -fv $(OUTPATH)debug.lastbuildstate
	touch $(OUTPATH)release.lastbuildstate

clean: 
	rm -fv *.exe
	rm -fv $(OUTPATH)*.o
	rm -fv $(OUTPATH)*.gcno
	rm -fv $(OUTPATH)*.gcda
	rm -fv $(OUTPATH)*.lastbuildstate
	
app.exe: dirs $(OUTPATH)main.o $(OUTPATH)memory_manager.o $(OUTPATH)list.o $(OUTPATH)chronicle.o 
	gcc -o $@ $(OUTPATH)main.o $(OUTPATH)memory_manager.o $(OUTPATH)list.o $(OUTPATH)chronicle.o  $(LFLAGS)

$(OUTPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OUTPATH)memory_manager.o: $(SRCPATH)memory_manager.c $(INCPATH)memory_manager.h
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPATH)list.o: $(SRCPATH)list.c $(INCPATH)list.h
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPATH)chronicle.o: $(SRCPATH)chronicle.c $(INCPATH)chronicle.h
	$(CC) $(CFLAGS) -o $@ $<

	
unit: unit_tests.exe
	drmemory -lib_blacklist "*" -brief -batch -- ./unit_tests.exe
	
unit_tests.exe: dirs $(OUTPATH)check_main.o $(OUTPATH)check_list.o $(OUTPATH)list.o $(OUTPATH)memory_manager.o
	gcc -o $@ $(OUTPATH)check_main.o $(OUTPATH)check_list.o $(OUTPATH)list.o $(OUTPATH)memory_manager.o $(ULFLAGS)
	
$(OUTPATH)check_main.o: $(UNITTESTPATH)check_main.c
	$(CC) $(UCFLAGS) -o $@ $<

$(OUTPATH)check_list.o: $(UNITTESTPATH)check_list.c $(INCPATH)list.h
	$(CC) $(UCFLAGS) -o $@ $<
	
dirs: $(INCPATH) $(OUTPATH) $(SRCPATH) $(FUNCTESTPATH) $(UNITTESTPATH)

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
	