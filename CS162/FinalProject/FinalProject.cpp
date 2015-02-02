/*********************************************************************
** Program Filename: finalproject.cpp
** Author: Rachael McConnell
** Date: 12/4/2014
** Description: This program takes a user through a zoo. The user is the zookeeper and it is his/her job
** to feed the mammals, the birds, OR the reptiles. The player must find the food room for the animals then go to each exhibit
** of the chosen animal type and feed the animals. Animal Types are: Mammals (Elephants, giraffes, zebras), Reptiles (Snakes,
** turtles, alligators), and Birds(Flamingos, penguins, toucans).
** Input: User chooses what type of animals they would like to feed
** Output: Each exhibit that the user goes to is output to the screen. The game is over when the user feeds all of the animals
********************************************************************/

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "final.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int main()
{
	char cDirection;		//player enters this to choose which way to go
	char choice;			//player enters this to choose what type of animal to feed
	string sChoice;			//this is set to the type of animal that the player chooses (mammal, reptile, or bird)
	bool bFed = false;		//false if the animal has not been fed
	Player player1;
	int feedCount = 0;		//starts at 0, increments each time an animal is fed
	vector<string> vFed;		//stores the names of the animals that have been fed already
	
	//create exhibits
	Zookeeper *zookeeperRoom = NULL;
	zookeeperRoom = new Zookeeper("Zookeeper Room", "East", "West", "");
	Mammals *zebra = new Mammals("Zebra", "North", "East", "West");
	Mammals *elephant = new Mammals("Elephant", "North", "East", "");
	Mammals *giraffe = new Mammals("Giraffe", "East", "South", "West");
	Birds *toucan = new Birds("Toucan", "North", "South", "West");
	Birds *penguin = new Birds("Penguin", "East", "South", "West");
	Birds *flamingo = new Birds("Flamingo", "East", "South", "");
	Reptiles *turtle = new Reptiles("Turtle", "North", "East", "South");
	Reptiles *snake = new Reptiles("Snake", "North", "South", "West");
	Reptiles *alligator = new Reptiles("Alligator", "North", "East", "West");
	FeedCenter *mammalFeedCenter = new FeedCenter("Mammal Feed Room", "North", "East", "West");
	FeedCenter *reptileFeedCenter = new FeedCenter("Reptile Feed Room", "South", "West", "");
	FeedCenter *birdFeedCenter = new FeedCenter("Bird Feed Room", "North", "West", "");
	Exhibits *current = zookeeperRoom;

	//link the exhibits together
	zookeeperRoom->west = elephant;
	zookeeperRoom->east = mammalFeedCenter;
	zebra->north = reptileFeedCenter;
	zebra->east = snake;
	zebra->west = penguin;
	elephant->north = turtle;
	elephant->east = zookeeperRoom;
	alligator->east = giraffe;
	alligator->north = penguin;
	alligator->west = turtle;
	flamingo->east = penguin;
	flamingo->south = turtle;
	penguin->east = zebra;
	penguin->west = flamingo;
	penguin->south = alligator;
	toucan->west = giraffe;
	toucan->north = snake;
	toucan->south = birdFeedCenter;
	snake->west = zebra;
	snake->south = toucan;
	snake->north = reptileFeedCenter;
	giraffe->east = toucan;
	giraffe->south = mammalFeedCenter;
	giraffe->west = alligator;
	turtle->south = elephant;
	turtle->east = alligator;
	turtle->north = flamingo;
	reptileFeedCenter->west = zebra;
	reptileFeedCenter->south = snake;
	mammalFeedCenter->west = zookeeperRoom;
	mammalFeedCenter->east = birdFeedCenter;
	mammalFeedCenter->north = giraffe;
	birdFeedCenter->west = mammalFeedCenter;
	birdFeedCenter->north = toucan;
	birdFeedCenter->west = mammalFeedCenter;

	cout << "Welcome to the Zoo! You are a zookeeper and it is your job to feed the mammals, the birds, or the reptiles.\n"
		<< "Please choose a creature category to feed: \n\tmammals(m) \n\tbirds(b) \n\treptiles(r)" << endl;
	cin >> choice;
	while (choice != 'm' && choice != 'b' && choice != 'r')
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Please enter a valid category: (m, b, r) ";
		cin >> choice;
	}

	if (choice == 'm')
		sChoice = "mammals";
	else if (choice == 'b')
		sChoice = "birds";
	else if (choice == 'r')
		sChoice = "reptiles";
	cout << "You will be feeding the " << sChoice << " today! "
		<< "In your bucket, you can only carry enough food for one exhibit at a time.\n"
		<< "There are 3 " << sChoice << " that you need to feed. To start the game, you must fill your "
		<< "bucket with food by finding the correct feed center for the " << sChoice << ".\n";
	cout << endl;
	cout << "The four directions are North(N), East(E), South(S), and West(W)."
		<< " To move between exhibits, type N, E, S, or W to choose your direction.\n";
	cout << endl;

	while (feedCount != 3)
	{
		if ((current->getname() == "Mammal Feed Room" && choice == 'm') || (current->getname() == "Reptile Feed Room" && choice == 'r') ||
			(current->getname() == "Bird Feed Room" && choice == 'b'))
			cout << "";
		else if (current->getname() == "Mammal Feed Room" || current->getname() == "Reptile Feed Room" ||
			current->getname() == "Bird Feed Room" || current->getname() == "Zookeeper Room")
			cout << "You are in the " << current->getname() << ".\n";
		else
			cout << "You are in the " << current->getname() << " exhibit.\n ";
			current->displayDirections();
			cin >> cDirection;
			cout << endl;
			if (cDirection == 'E' || cDirection == 'e')
			{
				if (current->east == NULL)
				{
					cout << "You cannot go East!\n";
				}
				else
				{
					current = current->east;
				}
			}
			else if (cDirection == 'N' || cDirection == 'n')
			{
				if (current->north == NULL)
				{
					cout << "You cannot go North!\n";
				}
				else
				{
					current = current->north;
				}
			}
			else if (cDirection == 'S' || cDirection == 's')
			{
				if (current->south == NULL)
				{
					cout << "You cannot go South!\n";
				}
				else
				{
					current = current->south;
				}
			}
			else if (cDirection == 'W' || cDirection == 'w')
			{
				if (current->west == NULL)
				{
					cout << "You cannot go West!\n";
				}
				else
				{
					current = current->west;
				}
			}
			else
			{
				"Sorry, that is not a valid option. Please choose again.\n";
			}

			//player's bucket is full
			if (player1.getBucket() == 1)
			{
				if ( (choice == 'm' && (current->getname() == "Giraffe" || current->getname() == "Elephant" || current->getname() == "Zebra")) ||
					(choice == 'b' && (current->getname() == "Flamingo" || current->getname() == "Penguin" || current->getname() == "Toucan")) ||
					(choice == 'r' && (current->getname() == "Turtle" || current->getname() == "Snake" || current->getname() == "Alligator")) )
				{
					for (int j = 0; j < vFed.size(); j++)
					{
						if (current->getname() == vFed.at(j))
						{
							bFed = true;	//set to true if the animal has already been fed
						}
					}
					if (bFed == false)
					{
						vFed.push_back(current->getname());
						player1.setBucket(0);
						cout << "Thanks for feeding the " << current->getname() << "s!\n";
						cout << "Your bucket is now empty. Return to the feed center.\n";
						feedCount++;
					}
					else
					{
						cout << "The " << current->getname() << "s have already been fed.\n";
						bFed = false;
					}
				}
			}

			if (feedCount == 3)
				break;

			if (choice == 'm' && current->getname() == "Mammal Feed Room" || choice == 'b' && current->getname() == "Bird Feed Room"
				|| choice == 'r' && current->getname() == "Reptile Feed Room")
			{
				cout << "You have found the " << current->getname() << "! Your bucket is now full of food.\n";
				player1.setBucket(1);
			}
	}

	if (feedCount == 3)
	{
		cout << "\nThanks for feeding the 3 animals. You have completed the feedings! Good job!\n";
	}

	return 0;
}
