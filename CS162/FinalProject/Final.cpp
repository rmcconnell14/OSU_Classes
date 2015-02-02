/*********************************************************************
** Program Filename: final.cpp
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
#include "final.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//This function displays which directions the player can go in the zoo
void Exhibits::displayDirections()
{
	if (getDirection3() == "")
		cout << "You can go " << getDirection1() << " or " << getDirection2() << ". Which way do you want to go?" << endl;
	else
		cout << "You can go " << getDirection1() << ", " << getDirection2() << ", or " << getDirection3() << ". Which way do you want to go?" << endl;
}
