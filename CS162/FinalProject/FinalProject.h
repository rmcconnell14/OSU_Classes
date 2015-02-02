/*********************************************************************
** Program Filename: final.h
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

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#ifndef FINAL_H
#define FINAL_H

class Player
{
protected:
	int bucket;
public:
	void setBucket(int b)
	{
		bucket = b;
	}

	int getBucket()
	{
		return bucket;
	}
};

class Exhibits
{
protected:
	string name;			//name of the room
	string direction1;		//first direction that is linked to another room
	string direction2;		//second direction that is linked to another room
	string direction3;		//third direction that is linked to another room
	string foodType;
public:
	Exhibits *north;			//pointer for north
	Exhibits *east;				//pointer for east
	Exhibits *south;			//pointer for south
	Exhibits *west;				//pointer for west

	Exhibits(string name1, string directiona, string directionb, string directionc, Exhibits *north1 = NULL, Exhibits *east1 = NULL, Exhibits *south1 = NULL, Exhibits *west1 = NULL)
	{
		name = name1;
		direction1 = directiona;
		direction2 = directionb;
		direction3 = directionc;
		north = north1;
		east = east1;
		south = south1;
		west = west1;
	}
	string getDirection1()
	{
		return direction1;
	}
	string getDirection2()
	{
		return direction2;
	}
	string getDirection3()
	{
		return direction3;
	}
	string getname()
	{
		return name;
	}
	virtual string getFoodType() const = 0;
	void displayDirections();
	~Exhibits() { }		//Destructor
};

class Zookeeper : public Exhibits
{
public:
	Zookeeper(string i, string a, string b, string c, Exhibits *n = NULL, Exhibits *e = NULL, Exhibits *s = NULL, Exhibits *w = NULL) : Exhibits(i, a, b, c, n, e, s, w)
	{
	}
	string getFoodType() const
	{
		foodType == "none";
		return foodType;
	}
	~Zookeeper() { }
};

class Mammals : public Exhibits
{
public:
	Mammals(string i, string a, string b, string c, Exhibits *n = NULL, Exhibits *e = NULL, Exhibits *s = NULL, Exhibits *w = NULL) : Exhibits(i, a, b, c, n, e, s, w)
	{
	}
	string getFoodType() const
	{
		foodType == "plants";
		return foodType;
	}
	~Mammals() { }
};

class Birds : public Exhibits
{
public:
	Birds(string i, string a, string b, string c, Exhibits *n = NULL, Exhibits *e = NULL, Exhibits *s = NULL, Exhibits *w = NULL) :Exhibits(i, a, b, c, n, e, s, w)
	{
	}
	string getFoodType() const
	{
		foodType == "birdseed";
		return foodType;
	}
	~Birds() { }
};

class Reptiles : public Exhibits
{
public:
	Reptiles(string i, string a, string b, string c, Exhibits *n = NULL, Exhibits *e = NULL, Exhibits *s = NULL, Exhibits *w = NULL) :Exhibits(i, a, b, c, n, e, s, w)
	{
	}
	string getFoodType() const
	{
		foodType == "mice";
		return foodType;
	}
	~Reptiles() { }
};

class FeedCenter : public Exhibits
{
public:
	FeedCenter(string i, string a, string b, string c, Exhibits *n = NULL, Exhibits *e = NULL, Exhibits *s = NULL, Exhibits *w = NULL) :Exhibits(i, a, b, c, n, e, s, w)
	{
	}
	string getFoodType() const
	{
		foodType == "";
		return foodType;
	}
	~FeedCenter() { }
};


#endif
