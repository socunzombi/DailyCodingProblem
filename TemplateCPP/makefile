# Makefile general purpose for a C++ program
# @Author: Joan Francesc Pedro Garcia

# region variables
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
HDR_FILES = $(wildcard $(INC_DIR)/*.h)
# endregion variables

# region all
all: clean_prestart $(BIN_DIR)/SOLUTION clean
# endregion all

# region tests
run: all
	./$(BIN_DIR)/SOLUTION

tests: all test1 test2 test3

test1:
	./$(BIN_DIR)/SOLUTION

test2:
	./$(BIN_DIR)/SOLUTION

test3:
	./$(BIN_DIR)/SOLUTION
# endregion tests

# region compiler
$(BIN_DIR)/SOLUTION: $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	g++ -Wall -Wextra $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDR_FILES)
	mkdir -p $(OBJ_DIR)
	g++ -Wall -Wextra -I $(INC_DIR) -c $< -o $@
# endregion compiler

# region clean
.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)

clean_prestart: 
	rm -rf $(OBJ_DIR) $(BIN_DIR)
# endregion clean
