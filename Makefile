CXX = g++
CXXFLAGS = -Wall -Wextra -g -I./include
RM = rm -f                       
TARGET = bank-simulation       

SRCS = main.cpp
include src/Makefile

OBJS = $(SRCS:.cpp=.o)                    

.PHONY: all
all: ${TARGET}

$(TARGET): $(OBJS)
	$(CXX) ${LDFLAGS} -o $@ $^

$(SRCS:.cpp=.d):%.d:%.cpp
	$(CXX) $(CXXFLAGS) -MM $< >$@
include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET} ${OBJS} $(SRCS:.cpp=.d)
