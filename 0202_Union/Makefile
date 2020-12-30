

CFLAGS=-Wall -o2
cc=gcc
objects= SqList.o Union.o Union-main.o
VPATH=../../Status

#不需要修改
INCPATH=-I$(VPATH)
LIBS= -L$(VPATH) -lScanf_lib
main:$(objects)
	$(CC) $^ -o $@ $(LIBS)
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ $(INCPATH)

.PHONY: clean
clean:
	-rm main $(objects)
