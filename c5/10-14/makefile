TARGET = main 
SOURCE = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCE))
CC = g++

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	
clean:
	rm $(OBJS) $(TARGET)
