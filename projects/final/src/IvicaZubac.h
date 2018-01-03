/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the IvicaZubac class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#ifndef IVICA_ZUBAC
#define IVICA_ZUBAC

#include "Player.h" // Player header

class IvicaZubac : public Player
{
	public:
		IvicaZubac(); // default constructor
		~IvicaZubac(); // destructor
};

#endif