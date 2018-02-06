CC=g++
EXE_FILE=gofish
HEADERS=Card.hpp Player.hpp Deck.hpp Hand.hpp Game.hpp
OBJS=Card.o Player.o Deck.o Hand.o Game.o gofish.o
CXXFLAGS=-std=c++11 -g

all: $(EXE_FILE)

$(EXE_FILE): $(OBJS)
	$(CC) $^ -o $@ $(CXXFLAGS)

%.o: %.cpp $(HEADERS)
	$(CC) -c $< -o $@ $(CXXFLAGS)
	
clean: 
	rm -f $(OBJS) $(EXE_FILE)