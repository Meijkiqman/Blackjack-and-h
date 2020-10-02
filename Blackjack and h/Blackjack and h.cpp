#include <iostream>
#include<vector>
#include<ctime>
#include<conio.h>


std::vector <int> card = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // vector assigns card values

int playerCash = 100;
int houseCash = 100;
int houseCardsValue = 0;
int cardsValue = 0;
int pool = 0;


void playerLose()
{
	std::cout << "Your card value exceeded 21, you lose this round :("	"\n";
	houseCash = houseCash + pool;
	startBet();
}

void draw()
{


	while (true)
	{
		std::cout << "please draw a card from 1 to 10" "\n";
		int choice;									//which card you decide to draw (this is pretty redundant since its not an actuall deck of cards)
		int drawnCard;								//value of what card was drawn

		std::cin >> choice;
		srand(time(0));
		drawnCard = rand() % card.size();
		card.push_back(drawnCard);								// randomly selects a card from the vector
		std::cout << "you drew a " << drawnCard << "\n";
		if (drawnCard == 1)
		{
			std::cout << "you drew a 1( an ace) you now get to choose if this card is worth 1 or 11" "\n"; // gets the player to choose between 1 or 11.
			while (true)
			{
				int ace;
				std::cin >> ace;
				if (ace == 1)
				{
					drawnCard = 1;
					break;
				}
				else if (ace == 11)
				{
					drawnCard = 11;
					break;
				}

				else if (ace != 1 && ace != 11)
				{
					std::cout << "that isnt 1 or 11, please choose a 1 or an 11" "\n";
				}

			}
		}
		else(drawnCard != 1);
		card.push_back(drawnCard);

		cardsValue = drawnCard + cardsValue;		// adds together total  value of your cards
		std::cout << "Your total value of cards are now: " << cardsValue << "\n";
		if (cardsValue > 21)						// if the total value of your cards is higher than 21 then you lose
		{
			playerLose();
		}
		std::cout << "would you like to draw another card? y/n" "\n";
		char answer;
		std::cin >> answer;
		if (answer != 'y')
			break;
	}

	if (cardsValue > 21)
	{
		playerLose();
	}
	else if (cardsValue <= 21)
	{
		std::cout << "you have a card value of " << cardsValue << "\n";
		std::cout << "would you like to bet additional money on your cards? y/n";
		char ans;
		std::cin >> ans;
		if (ans == 'y')
		{
			std::cout << "your balance is " << playerCash << "$" "\n";
			std::cout << "please enter your desired bet: " "\n";
			while (true)
			{
				int bet;
				std::cin >> bet;
				if (bet > playerCash && bet > houseCash)
				{
					std::cout << "you cannot afford to bet that amount, please enter a valid bet" "\n";
				}
				else if (bet < playerCash && bet < houseCash)
				{
					playerCash - bet;
					pool = bet + pool;
					std::cout << "the house matches your bet" "\n";
					houseCash - bet;
					pool = bet + pool;
					std::cout << "the pool has now a value of" << pool << "$" "\n";

					break;
				}
			}


		}

		std::cout << "house will now draw";
		houseDraw();

	}

}

void startBet()
{
	pool = 0;				//resets all relevant values.
	houseCardsValue = 0;
	cardsValue = 0;
	std::cout << "your balance is " << playerCash << "$" "\n";
	std::cout << "the houses balance is " << houseCash << "$" "\n";
	std::cout << "the the starting bid is 10$, press any key to confirm your bet" "\n";
	char any;
	std::cin >> any;
	if (playerCash >= 10 && houseCash >= 10)
	{
		playerCash - 10;
		pool + 10;
		houseCash - 10;
		pool + 10;
		std::cout << "the pool is now worth" << pool << "$, time to draw your cards!" "\n";

		draw();
	}
	else if (playerCash < 10)
	{
		std::cout << "player is out of cash, you lose. the house allways wins!";
	}
	else if (houseCash < 10)
	{
		std::cout << "the house is out of cash. you win! Seems like the house doesn't allways win.";

	}

};
void setUp()
{
	std::cout << "welcome to blackjack you and the house has a total of $100 to play for, each round has a starting bid of $10" "\n";
	std::cout << "you will then be asked to draw a card from a deck ranging from 1 to 10, to goal is to come as close to 21 has possible. if you exceed 21 you lose." << "\n";
	std::cout << "you are allowed to draw has many cards as you want. after you are satisfied with your cards you can bet again on your cards, the house will match your bid. so you cannot bet more then the house" "\n";
	std::cout << "whoever has all of the opponents moey at the end wins!" "\n" << "press any key to continue";
	char any;
	std::cin >> any;

	startBet();
}

void playerWin()
{
	std::cout << "Your card value was closest to 21, you win this round :)" "\n";
	playerCash = pool + playerCash;
	startBet();
}
void houseDraw()
{

	int houseCard;

	do
	{
		srand(time(0));
		houseCard = rand() % card.size();
		card.push_back(houseCard);
		std::cout << "the House drew a " << houseCard << "\n";
		if (houseCard == 1)
		{
			int low = 1;
			int high = 11;

			if (abs(low - 21) < abs(high - 21))
			{
				houseCard = 1;
			}
			else
			{
				houseCard = 11;
			}
		}
	} while (houseCardsValue < cardsValue);
}




int main()
{
	setUp();
	
}
