CC = g++
PROGRAM = main

all: 	$(PROGRAM)

run:	$(PROGRAM)
		./$(PROGRAM)

.PHONY: clean

clean:
		rm -f *.o *~ $(PROGRAM)