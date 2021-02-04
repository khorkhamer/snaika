COMPILER=g++
o_FLAG=-o
c_FLAG=-c
Wall_g_FLAGS=-Wall -g
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system



all: snaika
		./snaika

snaika: out/main.o out/game.o out/snake.o out/food.o out/graphics.o out/user.o out/mode.o
		$(COMPILER) $(Wall_g_FLAGS) $(SFML_FLAGS) out/main.o out/game.o out/snake.o out/food.o out/graphics.o out/user.o out/mode.o $(o_FLAG) snaika

out/main.o: main.cpp
		$(COMPILER) $(Wall_g_FLAGS) $(c_FLAG) $(o_FLAG) out/main.o main.cpp

out/game.o: logic/game.cpp
		$(COMPILER) $(Wall_g_FLAGS) $(c_FLAG) $(o_FLAG) out/game.o logic/game.cpp

out/snake.o: logic/snake.cpp
		$(COMPILER) $(Wall_g_FLAGS) $(c_FLAG) $(o_FLAG) out/snake.o logic/snake.cpp

out/food.o: logic/food.cpp
		$(COMPILER) $(Wall_g_FLAGS) $(c_FLAG) $(o_FLAG) out/food.o logic/food.cpp

out/graphics.o: view/graphics.cpp
		$(COMPILER) $(Wall_g_FLAGS) $(c_FLAG) $(o_FLAG) out/graphics.o view/graphics.cpp

out/user.o: controller/user.cpp
		$(COMPILER) $(Wall_g_FLAGS) $(c_FLAG) $(o_FLAG) out/user.o controller/user.cpp

out/mode.o: logic/mode.cpp
		$(COMPILER) $(Wall_g_FLAGS) $(c_FLAG) $(o_FLAG) out/mode.o logic/mode.cpp
