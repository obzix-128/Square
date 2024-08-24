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

hello: Main.o Other.o SkipLine.o UserInteraction.o WorkWithDouble.o
	@$(CC) Main.o Other.o SkipLine.o UserInteraction.o WorkWithDouble.o $(FLAGS) -o do

Main.o: Main.cpp
	@$(CC) -c Main.cpp -o Main.o

Other.o: Other.cpp
	@$(CC) -c Other.cpp -o Other.o
SkipLine.o: SkipLine.cpp
	@$(CC) -c SkipLine.cpp -o SkipLine.o
UserInteraction.o: UserInteraction.cpp
	@$(CC) -c UserInteraction.cpp -o UserInteraction.o
WorkWithDouble.o: WorkWithDouble.cpp
	@$(CC) -c WorkWithDouble.cpp -o WorkWithDouble.o
clean:
	@rm -rf *.o hello
