#include <iostream>
#include<vector>
#include<ctime>


void lose()
{
	std::cout << "Your card value exceeded 21, you lose";
}

void draw()
{
	std::vector <int> card = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // vector assigns card values
	int cardsValue = 0;

	while (true)
	{
		std::cout << "please draw a card from 1 to 10" "\n";
		int choice;									//which card you decide to draw (this is pretty redundant since its not an actuall deck of cards)
		int drawnCard;								//value of what card was drawn

		std::cin >> choice;
		srand(time(0));
		drawnCard = rand() % card.size();			// randomly selects a card from the vector
		std::cout << "you drew a " << drawnCard << "\n";
		cardsValue = drawnCard + cardsValue;		// adds together total  value of your cards
		std::cout << "Your total value of cards are now: " << cardsValue << "\n";
		if (cardsValue > 21)						// if the total value of your cards is higher than 21 then you lose
		{
			lose();
		}
		std::cout << "would you like to draw another card? y/n" "\n";
		char answer;
		std::cin >> answer;
		if (answer != 'y')
			break;
	}

	if (cardsValue > 21)
	{
		lose();
	}
	else if(cardsValue <= 21)
	{
		houseDraw();
	}

}

void houseDraw()
{
	std::vector <int> card = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int houseCardsValue = 0;
	int houseCard;

	while (true)
	{
		srand(time(0));
		houseCard = rand() % card.size();

	}

	
}

int main()
{
	draw();
	
}
