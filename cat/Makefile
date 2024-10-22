SHELL=/bin/bash
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
INCLUDES = s21_cat.h
SRCS = main.c flg_parser.c process_char.c read_file.c
OBJS = $(SRCS:.c=.o)
TARGET = s21_cat
FILE=cat_test.txt
CHECK=2>&1 valgrind --tool=memcheck --leak-check=yes
CPP=cppcheck --enable=all --suppress=missingIncludeSystem
SRCS = main.c flg_parser.c process_char.c read_file.c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

tests:
	-diff -s <(./s21_cat -n $(FILE)) <(cat -n $(FILE))
	-diff -s <(./s21_cat -b $(FILE)) <(cat -b $(FILE))
	-diff -s <(./s21_cat -s $(FILE)) <(cat -s $(FILE))
	-diff -s <(./s21_cat -E $(FILE)) <(cat -E $(FILE))
	-diff -s <(./s21_cat -e $(FILE)) <(cat -e $(FILE))
	-diff -s <(./s21_cat -T $(FILE)) <(cat -T $(FILE))
	-diff -s <(./s21_cat -t $(FILE)) <(cat -t $(FILE))
	-diff -s <(./s21_cat -v $(FILE)) <(cat -v $(FILE))
	-diff -s <(./s21_cat -nbsetv $(FILE)) <(cat -nbsetv $(FILE))
	-diff -s <(./s21_cat --number $(FILE)) <(cat --number $(FILE))
	-diff -s <(./s21_cat --number-nonblank $(FILE)) <(cat --number-nonblank $(FILE))
	-diff -s <(./s21_cat --squeeze-blank $(FILE)) <(cat --squeeze-blank $(FILE))

valgrind:
	$(CHECK) ./s21_cat $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -n $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -b $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -s $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -E $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -e $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -T $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -t $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -v $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -netbsv $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -number $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -number-nonblank $(FILE) | grep ERROR
	$(CHECK) ./s21_cat -squeeze-blank $(FILE) | grep ERROR

cppcheck:
	$(CPP) main.c flg_parser.c process_char.c read_file.c s21_cat.h

# Правило очистки (clean)
clean:
	rm -f $(OBJS) $(TARGET)

# Правило для повторной сборки (rebuild)
rebuild: clean all