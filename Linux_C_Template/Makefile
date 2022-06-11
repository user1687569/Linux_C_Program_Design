CXX = gcc

OBJ_DIR = obj

TARGET := execProgram

OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(wildcard *.c)))

all: $(OBJ_DIR)
$(OBJ_DIR):
	$(shell if [ -d $(OBJ_DIR) ]; then echo "exist obj"; else mkdir $(OBJ_DIR); fi)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY:clean
clean:
	$(shell if [ -f execProgram ]; then rm -f execProgram; fi)
	$(shell if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi)
	
