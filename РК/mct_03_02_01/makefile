CC = gcc
INCPATH = ./inc/
SRCPATH = ./src/

CFLAGS = -std=c99 -I$(INCPATH) -Wall -Wextra -Wpedantic -Werror -c
LFLAGS = 

.PHONY: clean
.NOTPARALLEL: release debug

build: app.exe

run: build
	./app.exe
	
clean: 
	rm -fv *.exe
	rm -fv $(OUTPATH)*.o
	
app.exe: $(OUTPATH)main.o $(OUTPATH)io.o $(OUTPATH)arr.o
	gcc -o $@ $(OUTPATH)main.o $(OUTPATH)io.o $(OUTPATH)arr.o $(LFLAGS)

$(OUTPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OUTPATH)io.o: $(SRCPATH)io.c $(INCPATH)io.h
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPATH)arr.o: $(SRCPATH)arr.c $(INCPATH)arr.h
	$(CC) $(CFLAGS) -o $@ $<

	