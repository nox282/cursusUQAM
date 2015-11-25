include makefile.inc
SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)

all: $(SRC) $(HEAD)
	@$(ECHO) Building Application... :
	@$(CC) $(FLAGS) $(SRC) -o $(EXEC)
	$(CC) $(FLAGS) $(SRC) -o $(EXEC)

clean :
	rm -f $(EXEC)
