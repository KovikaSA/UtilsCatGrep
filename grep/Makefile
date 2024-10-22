SHELL=/bin/bash
FLAG=-Wall -Wextra -Werror -std=c11 -g3 -pedantic
FILE=s21_grep.c
CHECK=2>&1 valgrind --tool=memcheck --leak-check=yes
CPP=cppcheck --enable=all --suppress=missingIncludeSystem
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
INCLUDES = s21_grep.h
SRCS = s21_grep.c flag_parser.c regex_utils.c file_processing.c
OBJS = $(SRCS:.c=.o)
TARGET = s21_grep
CHECK=2>&1 valgrind --tool=memcheck --leak-check=yes
CPP=cppcheck --enable=all --suppress=missingIncludeSystem

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@
	
tests:
	echo -en he'\n'for'\n'main > patterns.reg
	-diff -s <(./s21_grep e $(FILE)) <(grep e $(FILE))
	-diff -s <(./s21_grep -e for $(FILE)) <(grep -e for $(FILE))
	-diff -s <(./s21_grep -i FOR $(FILE)) <(grep -i FOR $(FILE))
	-diff -s <(./s21_grep -v for $(FILE)) <(grep -v for $(FILE))
	-diff -s <(./s21_grep -c for $(FILE)) <(grep -c for $(FILE))
	-diff -s <(./s21_grep -l for *.*) <(grep -l for *.*)
	-diff -s <(./s21_grep -n for $(FILE)) <(grep -n for $(FILE))
	-diff -s <(./s21_grep -h for $(FILE)) <(grep -h for $(FILE))
	-diff -s <(./s21_grep -s for error.c) <(grep -s for error.c)
	-diff -s <(./s21_grep -e for -e FOR $(FILE)) <(grep -e for -e FOR $(FILE))
	-diff -s <(./s21_grep -f patterns.reg $(FILE)) <(grep -f patterns.reg $(FILE))
	-diff -s <(./s21_grep -iv FOR $(FILE)) <(grep -iv FOR $(FILE))
	-diff -s <(./s21_grep -in FOR $(FILE)) <(grep -in FOR $(FILE))
	-diff -s <(./s21_grep -noe ing -e as -e the -e not -e is $(FILE)) <(grep -noe ing -e as -e the -e not -e is $(FILE))
	-diff -s <(./s21_grep -c -e . $(FILE) -e '.') <(grep -c -e . $(FILE) -e '.')
	-diff -s <(./s21_grep -f test_files/test_1_grep.txt test_files/test_1_grep.txt) <(grep -f test_files/test_1_grep.txt test_files/test_1_grep.txt)
	-diff -s <(./s21_grep -f test_files/test_3_grep.txt test_files/test_3_grep.txt) <(grep -f test_files/test_3_grep.txt test_files/test_3_grep.txt)

valgrind:
	$(CHECK) ./s21_grep e $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -e for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -i FOR $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -v for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -c for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -l for *.* | grep ERROR
	$(CHECK) ./s21_grep -n for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -h for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -s for error.c | grep ERROR
	$(CHECK) ./s21_grep -iv for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -in for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -iv for $(FILE) | grep ERROR
	$(CHECK) ./s21_grep -in for $(FILE) | grep ERROR

cppcheck:
	$(CPP) s21_grep.c flag_parser.c regex_utils.c file_processing.c s21_grep.h

clean:
	rm -f $(OBJS) $(TARGET) *.reg

rebuild: clean all