OBJ = bellmanFord.out
FOLDER = /home/kineton/BellmanFord
OUT_DIR = out
SRC = src
HEADER = include
TEXT_DIR = text
DIRECTORY = /home/kineton/BellmanFord/Bellman-Ford/Sorgenti
# SSS = $(shell echo $(SHELL))

source := $(wildcard $(DIRECTORY)/*.cpp)
header := $(wildcard $(DIRECTORY)/*.h)
output := $(wildcard $(DIRECTORY)/$(OUT_DIR)/*.out)
text := $(wildcard $(DIRECTORY)/*.txt)

ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
$(shell mkdir -p $(FOLDER)/$(OUT_DIR)/)
endif

ifeq ("$(wildcard $(FOLDER)/$(SRC))", "")
$(shell mkdir -p $(FOLDER)/$(SRC))
$(shell cp $(wildcard $(DIRECTORY)/*.cpp) $(FOLDER)/$(SRC))
endif

ifeq ("$(wildcard $(FOLDER)/$(HEADER))", "")
$(shell mkdir -p $(HEADER))
$(shell cp $(wildcard *.h) $(DIRECTORY)/*.h $(FOLDER)/$(HEADER))
endif

ifeq ("$(wildcard $(FOLDER)/$(TEXT_DIR))", "")
$(shell mkdir -p $(FOLDER)/$(TEXT_DIR))
$(shell cp $(wildcard *.txt) $(DIRECTORY)/*.txt $(FOLDER)/$(TEXT_DIR))
endif


all: build clean head
.PHONY: all

# all: preproc build clean

# preproc:
# 	g++ *.cpp -E -o *.i

build:
	@echo "build..."
	g++ $(source) -o $(addprefix $(FOLDER)/$(OUT_DIR)/, $(OBJ))
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
	@echo "Wildcard -> " $(wildcard *.cpp)
	@echo "Current folder = "$(DIRECTORY)
	@echo "Dir 2 -> "$(dir $(FOLDER)/*.cpp)
	#Trova il suffisso in un determinato file
	@echo "Suffix -> "$(suffix $(FOLDER)/*.cpp $(FOLDER)/*.h)
	#Aggiunge il prefisso al file di riferimento
	@echo "Addprefix -> "$(addprefix $(FOLDER)/obj/, $(OBJ))
	rm -rf *.gch

destroy:
	@echo "destroy..."
	rm -rf $(OBJ)
	rm -rf *.i
	rm -rf src/
	rm -rf $(OUT_DIR)
	rm -rf ../../$(HEADER)
	rm -rf ../../$(SRC)
	rm -rf ../../$(TEXT_DIR)
	rm -rf $(HEADER)
	rm -rf $(SRC)
	rm -rf $(TEXT_DIR)
