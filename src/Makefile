CC = g++

HADOOP_INSTALL = /usr/local/hadoop

CFLAGS = -c -g -O0 -Wall -I$(HADOOP_INSTALL)/include -I$(HADOOP_INSTALL)/lib/native/

LFLAGS = -L$(HADOOP_INSTALL)/lib/native -lhadooputils -lpthread -I$(HADOOP_INSTALL)/include

SOURCES = wordcount.cpp main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = wordcount

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
