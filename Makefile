ifeq ($(OS), Windows_NT)
	RM := del -f
	OUTPATH := ./out
	OBJPATH := ./obj
	SRCPATH := ./src
	EXE := .exe
	MKDIR_OBJ := mkdir obj
else ifeq ($(shell uname), Linux)
	RM := rm -f
	OUTPATH := ./out
	OBJPATH := ./obj
	SRCPATH := ./src
	EXE :=
	MKDIR_OBJ := mkdir -p obj
endif

CLANG := clang++
TARGET := main$(EXE)

SRCS := $(wildcard $(SRCPATH)/*.cpp)
OBJS := $(patsubst $(SRCPATH)/%.cpp, obj/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CLANG) $^ -o $(OUTPATH)/$@ 

obj/%.o: $(SRCPATH)/%.cpp | $(OBJPATH)
	$(shell $(MKDIR_OBJ))
	$(CLANG) -c $< -o $@

clean:
	$(RM) $(OUTPATH)/* $(OBJPATH)/*

run:
	$(OUTPATH)/$(TARGET)

.PHONY: all clean run

# THX GEMINI