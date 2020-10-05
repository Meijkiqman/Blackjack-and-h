#include <iostream>
#include<vector>
#include<ctime>
#include<conio.h>
#include<chrono>
#include <windows.h>





int playerCash = 100;
int houseCash = 100;
int houseCardsValue = 0;
int cardsValue = 0;
int pool = 0;

void startBet();
void houseDraw();

void playerLose()
{	
	if (cardsValue > 21)								//if the cards value are higher than 21, this message will play
	{
		std::cout << "Your card value exceeded 21, you lose this round :("	"\n";
		houseCash = houseCash + pool;
		startBet();
	}
	else if (cardsValue < houseCardsValue)
	{
		std::cout << "the house got closer to 21 than you, the house wins" "\n"; // if the player has a higher value than the house and this value is equal or lower than 21 this masseage plays
		houseCash = houseCash + pool;
		startBet();
	}
}

void houseLose()
{
	if (houseCardsValue > 21)
	{
		std::cout << "the house exceeded 21, you win" "\n";
		playerCash = playerCash + pool;
		startBet();
	}
	else if (houseCardsValue < cardsValue)
	{
		std::cout << "you got closer to 21 than the house, you win" "\n";
		playerCash = playerCash + pool;
		startBet();
	}
	
}

void tie()
{
	std::cout << "your card values and the houses' are the same, it's a tie." "\n"; //this plays when the house and the players card value are the same
	pool = pool / 2;											//devides by 2 to splitt the pool 50/50 then gives both the player and the house the their money back
	playerCash = playerCash + pool;
	houseCash = houseCash + pool;
	startBet();
}

void draw()
{


	while (true)										//this loop makes it so tht the player draws can draw a card as many times as it wants untill it reaches 21
	{
		std::cout << "Press any key to draw a card." "\n";
		_getch();
		int drawnCard;								
		srand(time(0));
		drawnCard = rand() % 10 + 1;										// randomly selects a number from 1 to 10	
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

	if (cardsValue > 21) // if the player exceeds 21 then player lose function plays
	{
		playerLose();
	}
	else if (cardsValue <= 21) // plays if the card value is equal to or below 21 and when the player has decided to stop drawing cards
	{
		std::cout << "you have a card value of " << cardsValue << "\n";
		std::cout << "would you like to bet additional money on your cards? y/n" "\n"; // asks of the player wants to bet more money.
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
				if (bet > playerCash && bet > houseCash) // you cant bet if either you or the house cant afford to
				{
					std::cout << "you cannot afford to bet that amount, please enter a valid bet" "\n";
				}
				else if (bet <= playerCash && bet <= houseCash) 
				{
					playerCash -= bet; // substracts bet from the players allowence and adds it to the pool
					pool = bet + pool;
					std::cout << "the house matches your bet" "\n"; //does the same with the house
					houseCash -= bet;
					pool = bet + pool;
					std::cout << "the pool has now a value of " << pool << "$" "\n";

					break;
				}
			}


		}

		std::cout << "house will now draw " "\n";
		houseDraw();

	}

}

void startBet()
{
	pool = 0;													//resets all relevant values.
	houseCardsValue = 0;
	cardsValue = 0;
	std::cout << "your balance is " << playerCash << "$" "\n";
	std::cout << "the houses balance is " << houseCash << "$" "\n";
	std::cout << "the the starting bid is 10$, press any key to confirm your bet" "\n";
	_getch();
	if (playerCash >= 10 && houseCash >= 10) //the player or the house can only play if they can afford to
	{
		playerCash -= 10;
		pool += 10;
		houseCash -= 10;
		pool += 10;
		std::cout << "the pool is now worth " << pool << "$, time to draw your cards!" "\n";

		draw();
	}
	else if (playerCash < 10)				//checks if weather the  player or the house can afford to play
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
	std::cout << "whoever has all of the opponents moey at the end wins!" "\n" << "press any key to continue" "\n";
	_getch();

	startBet();
}



void playerWin()
{
	std::cout << "Your card value was closest to 21, you win this round :)" "\n";
	playerCash = pool + playerCash; // adds the pool the the players allowence
	startBet();
}
void houseDraw()
{

	int houseCard;

	do
	{
		Sleep(1000); // puts in a 1 sec delay so that srand time prints differant numbers, it also looks better when you play.
		srand(time(0));
		houseCard = rand() % 10 + 1;

		std::cout << "the House drew a " << houseCard << "\n";
		if (houseCard == 1)
		{
			int low = houseCardsValue + 1;
			int high = houseCardsValue + 11;

			if (abs(low - 21) < abs(high - 21)) //abs makes the answer to the equation an absulute number, so no negaive numbers. the equation will be for instance if
												// the value of the cards are 16. then 16 + 1 -21 = -4, which will be a 4 or 16 + 11 - 21 = 6. which is allready a positive number. 
												//the equation will then choose 1 because 4 is lower than 6.
			{
				houseCard = 1;
			}
			else
			{
				houseCard = 11;
			}
		}
		
		houseCardsValue = houseCard + houseCardsValue;

	} while (houseCardsValue < cardsValue);										//it will only continue if the house i lower than the player. this way it will play it sage aswell never go above 21
	std::cout << "the house has a card value of " << houseCardsValue << "\n";
	if (houseCardsValue > 21)
	{
		houseLose();
	}
	else if (houseCardsValue < cardsValue)
	{
		houseLose();
	}
	else if (houseCardsValue > cardsValue)
	{
		playerLose();
	}
	else if (houseCardsValue == cardsValue)
	{
		tie();
	}
}




int main()
{
	setUp();
	
}
