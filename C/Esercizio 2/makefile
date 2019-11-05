#
# Makefile progetto algoritmi - Esercizio 2
# Per sistema operativo GNU/Linux
#

EXEC = alg_es2

CC = gcc
CFLAGS = -Wall

RM = rm -rf

SRCDIR = src
OBJDIR = obj
BINDIR = bin

#
$(BINDIR)/$(EXEC): $(OBJDIR)/main.o $(OBJDIR)/edit_distance_dyn.o
	$(CC) $(CFLAGS) $^ -o $@

#
$(OBJDIR)/main.o: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

#
$(OBJDIR)/main_test.o: $(SRCDIR)/main_test.c
	$(CC) $(CFLAGS) -c $< -o $@

#
$(OBJDIR)/unity.o: $(SRCDIR)/unity.c
	$(CC) $(CFLAGS) -c $< -o $@

#
$(OBJDIR)/edit_distance.o: $(SRCDIR)/modules/edit_distance/edit_distance.c
	$(CC) $(CFLAGS) -c $< -o $@


#
$(OBJDIR)/edit_distance_dyn.o: $(SRCDIR)/modules/edit_distance_dyn/edit_distance_dyn.c
	$(CC) $(CFLAGS) -c $< -o $@

#
test: $(OBJDIR)/main_test.o $(OBJDIR)/unity.o $(OBJDIR)/edit_distance_dyn.o $(OBJDIR)/edit_distance.o
	$(CC) $(CFLAGS) $^ -o $(BINDIR)/$(EXEC)_test

#
.PHONY: clean
clean:
	$(RM) $(OBJDIR)/* $(BINDIR)/*
