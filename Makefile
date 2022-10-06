TARGET=number_guessing
$(TARGET): main.c
	gcc -W -Wall -Wextra -pedantic -o $(TARGET) main.c io_functions.c get_random.c
