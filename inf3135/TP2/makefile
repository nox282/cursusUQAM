include makefile.inc
SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

all: link

compile : $(OBJ)
	@$(ECHO) Building Application... :
	$(CC) $(FLAGS) $(OBJ) -o $(EXEC)

$(OBJ) : $(SRC) $(HEAD)
	$(CC) $(FLAGS) -c $(SRC) 

link: compile

debug: $(SRC) $(HEAD)
	@$(ECHO) Building debugable executable ... :
	$(CC) -g $(FLAGS) $(SRC) -o $(EXEC)

clean :
	rm -f $(EXEC)
	rm -f $(OBJ)
