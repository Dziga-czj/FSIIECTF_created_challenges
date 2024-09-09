CHALLENGE=orc_wars
USER=pwn3r

CC=gcc
CFLAGS=-fPIE -fstack-protector-all -D_FORTIFY_SOURCE=2
LDFLAGS=-Wl,-z,now -Wl,-z,relro

SRC=$(CHALLENGE).c
OBJ=$(SRC:.c=.o)
BIN=$(CHALLENGE)

.DEFAULT_GOAL := challenge
.PHONY : clean all

$(BIN):
	@echo "Compiling..."
	$(CC) -o $@ $(SRC) $(LDFLAGS) $(CFLAGS)

challenge: $(BIN)
	rm -f $(OBJ)
