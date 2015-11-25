include makefile.inc

FILES := $(wildcard *.c)
HEADERS := $(wildcard *.h)

$(EXEC) : $(FILES) $(HEADERS)
	@$(ECHO) Building Executable... :
	@$(ECHO) $(CC) $(CFLAGS) $(FILES) -o $(EXEC)
	@$(CC) $(FILES) -o $(EXEC)

clean :
	rm -f $(EXEC)
