OBJ = bellmanFord.out
FOLDER = $(shell pwd)
OUT_DIR = out
SRC = src
HEADER = include
TEXT_DIR = text
CC = g++

source := $(wildcard $(FOLDER)/$(SRC)/*.cpp)
header := $(wildcard $(FOLDER)/$(HEADER)/*.h)
text := $(wildcard $(FOLDER)/$(TEXT_DIR)/*.txt)
directory := $(wildcard */)
# directory := $(foreach d, $(FOLDER), $(wildcard */))
# sdir := $(wildcard $(directory)/ *.cpp)
sdir := $(shell find $(SRC)/ -name "main.cpp")

ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
$(shell mkdir -p $(FOLDER)/$(OUT_DIR)/)
endif

ifeq ("$(wildcard $(FOLDER)/)", "")
$(shell mkdir -p $(FOLDER)/$(SRC))
endif

ifeq ("$(wildcard $(FOLDER)/$(HEADER))", "")
$(shell mkdir -p $(HEADER))
endif

ifeq ("$(wildcard $(FOLDER)/$(TEXT_DIR))", "")
$(shell mkdir -p $(FOLDER)/$(TEXT_DIR))
endif


all: build clean
.PHONY: all

# preproc:
# 	g++ *.cpp -E -o *.i

build:
	@echo "build..."
	$(CC) $(source) -o $(addprefix $(FOLDER)/$(OUT_DIR)/, $(OBJ))
	@echo " "
	@echo "Compilazione completata"
	@echo " "


clean:
	@echo "Clean... "
	@echo "dir -> " $(directory)
	@echo "dir2 -> " $(sdir)
	@echo "root dir" $(basename $(FOLDER) $<)
	@echo "not dir" $(basename $(notdir $(FOLDER) $<))
	@echo "Out folder -> " $(wildcard $(OUT_DIR)/*.out)
	@echo "source --> " $(notdir $(wildcard $(SRC)/main.cpp))
	rm -rf *.gch

destroy:
	@echo "destroy..."
	rm -rf $(OBJ)
	rm -rf $(FOLDER)/$(OUT_DIR)/*.out
	rm -rf *.i
