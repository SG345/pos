OBJS = inventory.o pos.o sale.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

p : $(OBJS)
  $(CC) $(LFLAGS) $(OBJS) -o p

inventory.o : inventory.h inventory.cpp pos.h sale.h
  $(CC) $(CFLAGS) inventory.cpp

Movie.o : sale.h sale.cpp pos.h inventory.h
  $(CC) $(CFLAGS) sale.cpp

NameList.o : pos.h pos.cpp sale.h inventory.h
  $(CC) $(CFLAGS) pos.cpp

Name.o : main.cpp inventory.h pos.h sale.h 
  $(CC) $(CFLAGS) main.cpp
clean:
  \rm *.o *~ p
