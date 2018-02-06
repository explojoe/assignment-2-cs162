#ifndef CARD_HPP
#define CARD_HPP

extern std::string ranks[13];
extern std::string ranks_p[13];
extern std::string ranks_choice[13];

class Card {
	private:
		int rank;	// Should be in the range 0-12
		int suit;	// Should be in the range 0-3
		bool booked;
	public:
		// must have constructors, destructor, accessor methods, and mutator methods
		
	Card();
	Card(int, int);
	
	void initialize(int, int);
	
	int getRank();
	int getSuit();
	bool getIsBooked();
	void book();
};
#endif