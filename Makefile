CC = gcc
CFLAGS = -Wall -Wextra -O2
SRCDIR = src
BINDIR = bin
INPUTDIR = input

# Find all .c files in src/ except template
SOURCES = $(filter-out $(SRCDIR)/template.c,$(wildcard $(SRCDIR)/*.c))
TARGETS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%,$(SOURCES))

all: $(TARGETS)

$(BINDIR)/%: $(SRCDIR)/%.c
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $< -o $@

# Compile and run with test input (e.g., make test-day1)
test-day%:
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(SRCDIR)/day$*.c -o $(BINDIR)/day$*
	@echo "Running day $* with test input..."
	@$(BINDIR)/day$* $(INPUTDIR)/day$*_test.txt

# Compile and run with real input (e.g., make run-day1)
run-day%:
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(SRCDIR)/day$*.c -o $(BINDIR)/day$*
	@echo "Running day $* with real input..."
	@$(BINDIR)/day$* $(INPUTDIR)/day$*.txt

# Compile and run with debugging
debug-day%:
	@mkdir -p $(BINDIR)
	$(CC) -g -Wall -Wextra $(SRCDIR)/day$*.c -o $(BINDIR)/day$*
	gdb $(BINDIR)/day$*

clean:
	rm -rf $(BINDIR)/*

.PHONY: all clean run-day% test-day% debug-day%
