########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = 

# Makefile settings - Can be customized.
APPNAME = main
EXT = .cpp
SRCDIR = src
OBJDIR = obj

TESTAPPNAME = testWarehouse
TESTSRCDIR = test
TESTOBJDIR = testobj


############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)

TESTSRC = $(wildcard $(TESTSRCDIR)/*$(EXT))
TESTOBJ = $(TESTSRC:$(TESTSRCDIR)/%$(EXT)=$(TESTOBJDIR)/%.o)
TESTDEP = $(TESTOBJ:$(TESTOBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ) $(TESTOBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)
WDELTESTOBJ = $(TESTSRC:$(TESTSRCDIR)/%$(EXT)=$(TESTOBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME) $(TESTAPPNAME)

# Builds the app
$(APPNAME): $(OBJ) main.cpp
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TESTAPPNAME): $(OBJ) $(TESTOBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT) $(TESTSRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)
-include $(TESTDEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT) main.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

$(TESTOBJDIR)/%.o: $(TESTSRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<  -Isrc/

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DELTESTOBJ)  $(DEP) $(TESTDEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP) $(TESTDEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(WDELTESTOBJ) $(DEP) $(TESTDEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP) $(TESTDEP)