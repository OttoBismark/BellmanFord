OBJ = bellmanFord.out
FOLDER = /home/kineton/BellmanFord
OUT_DIR = out
SRC = src
HEADER = include
TEXT_DIR = text
CC = g++

source := $(wildcard $(FOLDER)/$(SRC)/*.cpp)
header := $(wildcard $(FOLDER)/$(HEADER)/*.h)
text := $(wildcard $(FOLDER)/$(TEXT_DIR)/*.txt)

ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
$(shell mkdir -p $(FOLDER)/$(OUT_DIR)/)
endif

ifeq ("$(wildcard $(FOLDER)/$(SRC))", "")
$(shell mkdir -p $(FOLDER)/$(SRC))
endif

ifeq ("$(wildcard $(FOLDER)/$(HEADER))", "")
$(shell mkdir -p $(HEADER))
endif

ifeq ("$(wildcard $(FOLDER)/$(TEXT_DIR))", "")
$(shell mkdir -p $(FOLDER)/$(TEXT_DIR))
endif


all: build clean head
.PHONY: all

# all: preproc build clean

# preproc:
# 	g++ *.cpp -E -o *.i

build:
	@echo "build..."
	$(CC) $(source) -o $(addprefix $(FOLDER)/$(OUT_DIR)/, $(OBJ))
	@echo " "
	@echo "Compilazione completata"
	@echo " "

head:
	@echo "head..."
	@echo $(source)
	@echo $(header)
	@echo $(text)
	@echo "Out folder -> " $(wildcard $(OUT_DIR)/*.out)

clean:
	@echo "Clean... "
	rm -rf *.gch

destroy:
	@echo "destroy..."
	rm -rf $(OBJ)
	rm -rf $(FOLDER)/$(OUT_DIR)/*.out
	rm -rf *.i