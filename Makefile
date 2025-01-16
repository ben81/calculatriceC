


#ddddcomp/%.o: %.c
#	gcc -ansi -Wall -c  -o $@ $^

# Compilateur C
CC = gcc

# Drapeaux du compilateur
CFLAGS = -MMD -MP

# Nom de l'exécutable
TARGET = cal

# Répertoire pour les fichiers objets
OBJDIR = comp

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

# Dependency files
DEPS = $(OBJS:$(OBJDIR)/%.o=$(OBJDIR)/%.d)


# Règle par défaut
all: $(TARGET)

# Règle pour lier les fichiers objets en un exécutable
$(TARGET): $(OBJS)
	gcc $(OBJS) -o cal -lm



$(OBJDIR)/%.o: %.c Makefile
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Inclure les fichiers de dépendance
-include $(DEPS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all clean
