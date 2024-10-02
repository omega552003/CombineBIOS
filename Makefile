EXE = combineBIOS
CFLAGS = -O2
LDFLAGS =

$(EXE):	combineBIOS.c
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -f $(EXE)
