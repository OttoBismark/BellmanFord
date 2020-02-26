OBJ = bellmanFord.out
FOLDER = /home/kineton/BellmanFord/Bellman-Ford/Sorgenti
OUT_DIR = out
SRC = src
HEADER = include
TEXT_DIR = text
DIRECTORY = $(PWD)
SSS = $(shell echo $(SHELL))


source := $(wildcard *.cpp)
header := $(wildcard *h)
output := $(wildcard $(OUT_DIR)/*.out)
text := $(wildcard *.txt)
#$(addprefix $(FOLDER)/$(SRC)/, $(OBJ))


ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
$(shell mkdir -p $(FOLDER)/$(OUT_DIR)/)
endif

ifeq ("$(wildcard ../$(SRC))", "")
$(shell mkdir -p ../$(SRC))
$(shell cp $(wildcard *cpp) ../$(SRC))
endif

ifeq ("$(wildcard ../$(HEADER))", "")
$(shell mkdir -p ../$(HEADER))
$(shell cp $(wildcard *h) ../$(HEADER))
endif

ifeq ("$(wildcard ../$(TEXT_DIR))", "")
$(shell mkdir -p ../$(TEXT_DIR))
$(shell cp $(wildcard *txt) ../$(TEXT_DIR))
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
	#Ottiene il path della cartella presa di riferimento dalla variabile
	@echo "Dir -> " $(dir $(FOLDER))
	@echo "Wildcard -> " $(wildcard *.cpp)
	@echo "Current folder = "$(DIRECTORY)
	@echo "Dir 2 -> "$(dir $(FOLDER)/*.cpp)
	#Trova il suffisso in un determinato file
	@echo "Suffix -> "$(suffix $(FOLDER)/*.cpp $(FOLDER)/*.h)
	#Aggiunge il prefisso al file di riferimento
	@echo "Addprefix -> "$(addprefix $(FOLDER)/obj/, $(OBJ)) 
	#Aggiunge il suffisso al file di riferimento
	@echo "Addsuffix -> " $(addsuffix :, main)
	#Bourne Again SHell
	@echo "Bourne Again SHell --> " $(SSS)
	rm -rf *.gch

ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
		$(shell echo "is empty or does not exist... "1>&2)
else
		$(shell echo "is NOT empty or ALREADY exist!" 1>&2)
endif

destroy:
	@echo "destroy..."
	rm -rf $(OBJ)
	rm -rf *.i
	rm -rf src/
	rm -rf $(OUT_DIR)
	rm -rf ../$(HEADER)
	rm -rf ../$(SRC)
	rm -rf ../$(TEXT_DIR)


# ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
# 	@echo "is empty or does not exist... "
# else
# 	@echo "is NOT empty or ALREADY exist!"
# endif
