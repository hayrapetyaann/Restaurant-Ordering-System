# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror

# Source files
SRCS = Appetizer.cpp Dessert.cpp Entree.cpp Order.cpp main.cpp \
       Customer.cpp Dish.cpp Menu.cpp Restaurant.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = restaurant_app

# Default rule: build the program
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule: remove compiled files
clean:
	rm -f $(OBJS) $(TARGET)
