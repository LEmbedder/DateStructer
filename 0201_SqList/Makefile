

CFLAGS=-Wall -o2
cc=gcc

VPATH=../../Status

objects= SqList.o  SqList-main.o
INCPATH=-I$(VPATH)
LIBS= -L$(VPATH) -lScanf_lib
main:$(objects)
	$(CC) $^ -o $@ $(LIBS)
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ $(INCPATH)

.PHONY: clean
clean:
	-rm main $(objects)
