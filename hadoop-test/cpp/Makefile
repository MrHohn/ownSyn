.SUFFIXES:.h .c .cpp .o

CC=g++
# CPPFLAGS = -m64 
RM = rm
SRCS = wordcount.cpp main.cpp
PROGRAM = wordcount
OBJS=$(SRCS:.cpp=.o)

INC_PATH = -I$(HADOOP_HOME)/include
LIB_PATH = -L$(HADOOP_HOME)/lib/native
LIBS = -lhadooppipes -lcrypto -lhadooputils -lpthread

#$?表示依赖项 $@表示目的项
$(PROGRAM):$(OBJS)
	$(CC) $? -Wall $(LIB_PATH) $(LIBS)  -g -O2 -o $@

$(OBJS):$(SRCS)
	$(CC) $(CPPFLAGS) -c $(SRCS)  $(INC_PATH)
	
.PHONY:clean
clean:
	$(RM) -rf $(PROGRAM) $(OBJS)
