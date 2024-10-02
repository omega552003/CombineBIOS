EXE = biosCombine
CFLAGS = -O2
LDFLAGS =

$(EXE):	biosCombine.c
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -f $(EXE)
