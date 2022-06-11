CXX = gcc

OBJ_DIR = obj

# INCPATH =
LIBPATH = -lpthread

TARGET := execProgram

OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(wildcard *.c)))

all: $(OBJ_DIR)
$(OBJ_DIR):
	$(shell if [ -d $(OBJ_DIR) ]; then echo "exist obj"; else mkdir $(OBJ_DIR); fi)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBPATH)

$(OBJ_DIR)/%.o: %.c
	$(CXX) -c $(CXXFLAGS) $(LIBPATH) -o $@ $<

.PHONY:clean
clean:
	$(shell if [ -f execProgram ]; then rm -f execProgram; fi)
	$(shell if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi)
	
