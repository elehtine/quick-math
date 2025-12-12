SOURCE = main
OUTPUT = quick-math
BUILD_DIR = build
TEST_DIR = test
SRC_DIR = src

# LaTeX Tools
LATEXMK_FLAGS = -pdf -outdir=$(BUILD_DIR) -interaction=nonstopmode -shell-escape -jobname=$(OUTPUT)

# C++ Tools
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2 -I$(SRC_DIR)

# File Lists
TEX_SOURCES = $(SOURCE).tex \
              quick-math.sty \
              topics/probability.tex \
              topics/analysis.tex \
              topics/numbers.tex \
              topics/matrix.tex \
              topics/geometry.tex \
              topics/strings.tex \
              topics/graphs.tex \
              topics/approximation.tex \
              topics/puzzles.tex \
              topics/np.tex \
              topics/intro.tex

# Standard PDF Build
all: $(OUTPUT).pdf

$(OUTPUT).pdf: $(TEX_SOURCES) | $(BUILD_DIR)
	latexmk $(LATEXMK_FLAGS) $(SOURCE).tex
	cp $(BUILD_DIR)/$@ $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

test: $(TEST_DIR)/test_runner.cpp
	$(CXX) $(CXXFLAGS) -o $(TEST_DIR)/runner $(TEST_DIR)/test_runner.cpp
	./$(TEST_DIR)/runner

# Cleanup
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OUTPUT).pdf
	rm -f $(TEST_DIR)/runner

.PHONY: all clean test
