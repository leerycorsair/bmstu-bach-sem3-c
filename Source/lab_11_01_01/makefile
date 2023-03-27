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
	

$(OUTPATH)my_snprintf.o: $(SRCPATH)my_snprintf.c $(INCPATH)my_snprintf.h
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPATH)str_tools.o: $(SRCPATH)str_tools.c $(INCPATH)str_tools.h
	$(CC) $(CFLAGS) -o $@ $<
	
unit: unit_tests.exe
	./unit_tests.exe
	
unit_tests.exe: dirs $(OUTPATH)check_main.o $(OUTPATH)check_my_snprintf.o $(OUTPATH)my_snprintf.o $(OUTPATH)str_tools.o 
	gcc -o $@ $(OUTPATH)check_main.o $(OUTPATH)check_my_snprintf.o $(OUTPATH)my_snprintf.o  $(OUTPATH)str_tools.o  $(ULFLAGS)
	
$(OUTPATH)check_main.o: $(UNITTESTPATH)check_main.c
	$(CC) $(UCFLAGS) -o $@ $<

$(OUTPATH)check_my_snprintf.o: $(UNITTESTPATH)check_my_snprintf.c $(INCPATH)my_snprintf.h
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
	