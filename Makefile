CXX := clang++
FLEX := flex
BISON := bison
LLVM_CONFIG := llvm-config

BUILD := build
TARGET := $(BUILD)/minipas

LLVM_CXXFLAGS := $(shell $(LLVM_CONFIG) --cxxflags)
LLVM_LIBS := $(shell $(LLVM_CONFIG) --ldflags --system-libs --libs core support)
CXXFLAGS := $(LLVM_CXXFLAGS) -std=c++17 -frtti -Wall -Wextra -Wpedantic -Iinclude -I$(BUILD)

OBJECTS := $(BUILD)/main.o $(BUILD)/semantic.o $(BUILD)/codegen.o \
           $(BUILD)/parser.o $(BUILD)/lexer.o

.PHONY: all clean test environment

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LLVM_LIBS) -o $@

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/parser.cpp $(BUILD)/parser.hpp: parser.y | $(BUILD)
	$(BISON) -Wall -d -v --defines=$(BUILD)/parser.hpp -o $(BUILD)/parser.cpp parser.y

$(BUILD)/lexer.cpp: lexer.l $(BUILD)/parser.hpp | $(BUILD)
	$(FLEX) -o $@ lexer.l

$(BUILD)/main.o: src/main.cpp include/ast.hpp include/codegen.hpp \
                 include/semantic.hpp include/parser_state.hpp $(BUILD)/parser.hpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD)/semantic.o: src/semantic.cpp include/ast.hpp include/semantic.hpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD)/codegen.o: src/codegen.cpp include/ast.hpp include/codegen.hpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD)/parser.o: $(BUILD)/parser.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD)/lexer.o: $(BUILD)/lexer.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -Wno-deprecated-register -c $< -o $@

test: $(TARGET)
	bash scripts/test.sh

environment:
	bash scripts/check-env.sh

clean:
	rm -rf $(BUILD) artifacts
