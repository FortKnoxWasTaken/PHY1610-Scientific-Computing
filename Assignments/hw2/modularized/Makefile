# flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# file variables
SRCS = modularized_gameof1d.cpp initialize.cpp update.cpp output.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = modularized_gameof1d

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $<

clean:
	rm -f $(OBJS) $(TARGET)
