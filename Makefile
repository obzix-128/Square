FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
         -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
		-Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions \
		-Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security \
		-Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
		-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 \
		-Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla \
		-D_DEBUG -D_EJUDGE_CLIENT_SIDE

CC=g++

all: hello

hello: MainQwadratka.o TeloQwadratka.o
	@$(CC) MainQwadratka.o TeloQwadratka.o $(FLAGS) -o do

MainQwadratka.o: MainQwadratka.cpp
	@$(CC) -c MainQwadratka.cpp -o MainQwadratka.o

TeloQwadratka.o: TeloQwadratka.cpp
	@$(CC) -c TeloQwadratka.cpp -o TeloQwadratka.o
clean:
	@rm -rf *.o hello
