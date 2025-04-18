FC = gcc
FFLAGS = -O2

all: C_licker

bin/main.o: src/main.c
	mkdir -p bin
	$(FC) $(FFLAGS) $< -o $@

./C_licker: bin/main.o
	ln -s $< $@

#clean:
#	rm *mod
