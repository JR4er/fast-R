CFLAGS = -O2

all: fast slow

common_obj = graph.o hda.o ra.o main.o
all_obj = $(common_obj) fast.o slow.o


$(all_obj): graph.h attack.h

fast: $(common_obj) fast.o
slow: $(common_obj) slow.o

.PHONY: clean
clean:
	rm $(all_obj) fast slow
