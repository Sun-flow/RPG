CXX=g++



INC_DIR		=./include
SRC_DIR		=./src
BIN_DIR		=./bin
OBJ_DIR		=./obj
TESTBIN_DIR	=./testbin


CXXFLAGS 		= -I $(INC_DIR) -Wall --std=c++14
TESTLDFLAGS 	= -lgtest -lgtest_main -lpthread
PROG_NAME 		= rpg
INCLUDE 		+= -I $(INC_DIR)


MAIN_OBJ 	= $(OBJ_DIR)/main.o

TEST_OBJ 	= $(OBJ_DIR)/testRPG.o

PROJ_OBJS	= $(OBJ_DIR)/Character.o	\
			  $(OBJ_DIR)/Injuries.o		\
			  $(OBJ_DIR)/MenuFuncs.o	\
			  $(OBJ_DIR)/Menu.o

TEST_NAME	= testRPG


$(BIN_DIR)/$(PROG_NAME): $(PROJ_OBJS) $(MAIN_OBJ)
	$(CXX) $(MAIN_OBJ) $(PROJ_OBJS) -o $(BIN_DIR)/$(PROG_NAME) $(CXXFLAGS)

$(TESTBIN_DIR)/$(TEST_NAME): $(PROJ_OBJS) $(TEST_OBJ)
	$(CXX) $(PROJ_OBJS) $(TEST_OBJ) -o $(TESTBIN_DIR)/$(TEST_NAME) $(CXXFLAGS) $(TESTLDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

$(MAIN_OBJ): $(SRC_DIR)/main.cpp $(OBJ_DIR)/main.o
	$(CXX) $(SRC_DIR)/main.cpp -c -o $(OBJ_DIR)/main.o $(CXXFLAGS)


directories: $(BIN_DIR) $(OBJ_DIR)

$(BIN_DIR): 
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) 


clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TESTBIN_DIR)/*