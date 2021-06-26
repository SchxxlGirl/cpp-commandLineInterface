CC = g++

CXXFLAGS = -Wall

SRCS = main.cpp cli.cpp args.cpp

# OBJS = $(SRCS:.cpp=.o)
OBJS = main.o cli.o args.o

INC = -I./inc/

OBJ_DIR = ./obj

TARGET = out

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.cpp.o :
	$(CC) $(CXXFLAGS) $(INC) -c $<

clean :
	rm -rf $(OBJS) $(TARGET)
