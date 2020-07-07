
DIR = .
CXX = g++
CFFLAGS = -std=c++11 -Wall -I$(INCDIR)

SRCDIR = $(DIR)/src
INCDIR = $(DIR)/inc
OBJDIR = $(DIR)/obj
EXE = programa

OBJECT = $(OBJDIR)/main.o 

all: $(EXE)

$(EXE): $(OBJECT)
	$(CXX) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	@rm $(EXE) $(OBJDIR)/*


