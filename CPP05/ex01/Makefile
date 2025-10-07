CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Iinclude
TARGET   := Form
SRCS     := main.cpp \
			Bureaucrat.cpp \
			Form.cpp \

OBJS     := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean