#
# 'make depend' uses makedepend to automaitcally generate dependencies
#
# 'make'	build executable file 'play_game'
#
# 'make clean;  remove all .o and executable files 
#
#

# compiler
CC = g++ -std=c++11


# define library paths in addition to /usr/include
INCLUDES = 

#define paths in addition to /usr/lib
LFLAGS = -L


# define any libraries to link into executable
LIBS = -l


# source files 
SRCS = deck.cpp decksort.cpp game.cpp simplecard.cpp stdcard.cpp



# object files
OBJS = $(SRCS:.c=.o)

# executable 
MAIN = play_cards

.PHONY: depend clean

all:	$(MAIN)
	@echo  play_cards has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# THIS is a suffix replacement rule for building .o's from .c's
# it uses automatic variabls $<:  the name of the prerequisite of 
# the rul(a .c file)  and $@: the number of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variable) 

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean: 
	$(RM) *.o $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^


# DO NOT DELETE THIS LINE
