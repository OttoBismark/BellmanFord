OBJ = bellmanFord.out
FOLDER = /home/kineton/BellmanFord/Bellman-Ford/Sorgenti
OUT_DIR = out
SRC = src
HEADER = include
TEXT_DIR = text
DIRECTORY = $(PWD)
# PHONY: build clean destroy


source := $(wildcard *.cpp)
header := $(wildcard *h)
output := $(wildcard $(OUT_DIR)/*.out)
text := $(wildcard *.txt)
#$(addprefix $(FOLDER)/$(SRC)/, $(OBJ))

# Add LIB folder in the root project directory
ifeq ("$(wildcard $(FOLDER)/lib/)", "")
$(shell mkdir -p $(FOLDER)/lib/)
endif

# Add BIN folder in the root project directory
ifeq ("$(wildcard $(FOLDER)/bin/)", "")
$(shell mkdir -p $(FOLDER)/bin/)
endif


# Add OPT folder in the root project directory
ifeq ("$(wildcard $(FOLDER)/opt/)", "")
$(shell mkdir -p $(FOLDER)/opt/)
endif

ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
$(shell echo "LA CARTELLA $(OUT_DIR) NON ESISTE " 1>&2)
$(shell mkdir -p $(FOLDER)/$(OUT_DIR)/)
endif

all: preset build clean head
.PHONY: all

# all: preproc build clean


# preproc:
# 	g++ *.cpp -E -o *.i

preset:
	@echo "preset... "
# ifeq ("$(wildcard $(FOLDER)/lib/)", "")
# 	@echo "is empty or does not exist... "
# 	mkdir -p $(FOLDER)/lib/

# else
# 	@echo "is NOT empty or ALREADY exist!"
# 	mkdir -p $(FOLDER)/lib/
# endif

	# mkdir -p $(FOLDER)/$(OUT_DIR)
	mkdir -p ../$(SRC)
	mkdir -p ../$(HEADER)
	mkdir -p ../$(TEXT_DIR)

	cp $(wildcard *cpp) ../$(SRC)
	cp $(wildcard *h) ../$(HEADER)
	cp $(wildcard *txt) ../$(TEXT_DIR)



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
	# @echo $(output)
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
	rm -rf *.gch

ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
	@echo "is empty or does not exist... "
else
	@echo "is NOT empty or ALREADY exist!"
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
	rm -rf lib/
	rm -rf bin/
	rm -rf opt/


# ifeq ("$(wildcard $(FOLDER)/$(OUT_DIR)/)", "")
# 	@echo "is empty or does not exist... "
# else
# 	@echo "is NOT empty or ALREADY exist!"
# endif
