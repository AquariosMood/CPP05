CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Iinclude
TARGET   := Form
SRCS     := main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \

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
	rm -f *_shrubbery
	find . -type f -name "*_shrubbery" -delete

re: fclean all

.PHONY: all clean fclean re rm_shrubbery