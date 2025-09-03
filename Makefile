# Nome del compilatore C che vogliamo usare (es. gcc o clang)
CC = gcc

# Flag per il compilatore:
# -Wall:      Attiva quasi tutti i warning (molto consigliato)
# -Wextra:    Attiva warning aggiuntivi
# -std=c11:   Usa lo standard C del 2011
# -g:         Includi informazioni di debug (per usare un debugger come gdb)
CFLAGS = -Wall -Wextra -pedantic -std=c11 -g

# Nome dell'eseguibile che vogliamo creare
TARGET = hello

# Lista di tutti i file sorgente (.c)
SRCS = hello.c

# Lista dei file oggetto (.o) derivata automaticamente dai file sorgente
OBJS = $(SRCS:.c=.o)

# La "ricetta" di default, che viene eseguita quando si lancia solo "make"
# Dipende dal nostro eseguibile TARGET
.PHONY: all
all: $(TARGET)

# Ricetta per creare l'eseguibile finale (linking)
# Dipende da tutti i file oggetto (.o)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Ricetta per pulire la directory dai file generati
# .PHONY dice a make che "clean" non è un file da creare
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
