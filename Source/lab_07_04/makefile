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
	
app.exe: dirs $(OUTPATH)main.o $(OUTPATH)file_io.o $(OUTPATH)arr_handling.o
	gcc -o $@ $(OUTPATH)main.o $(OUTPATH)file_io.o $(OUTPATH)arr_handling.o $(LFLAGS)

$(OUTPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OUTPATH)file_io.o: $(SRCPATH)file_io.c $(INCPATH)file_io.h
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPATH)arr_handling.o: $(SRCPATH)arr_handling.c $(INCPATH)arr_handling.h
	$(CC) $(CFLAGS) -o $@ $<
	
func: debug 
	cd $(FUNCTESTPATH) && cmd //C all_test.cmd
	gcov -n $(OUTPATH)main.o
	gcov -n $(OUTPATH)file_io.o
	gcov -n $(OUTPATH)arr_handling.o
	
unit: unit_tests.exe
	./unit_tests.exe
	
unit_tests.exe: dirs $(OUTPATH)arr_handling.o $(OUTPATH)check_arr_handling.o
	gcc -o $@ $(OUTPATH)arr_handling.o $(OUTPATH)check_arr_handling.o $(ULFLAGS)
	
$(OUTPATH)check_arr_handling.o: $(UNITTESTPATH)check_arr_handling.c $(INCPATH)arr_handling.h
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
	