#include <iostream>
#include <fstream>
#include "tower.h"

std::ofstream os;

int main(){
	int option, gamesize;
	std::string filename;
	std::ofstream os;
	std::string move, to;
	int fromTower, toTower;

	std::cout << "Welcome to Towers of Hanoi!" << std::endl << std::endl
		<< "Please choose from the following options..." << std::endl
		<< "1. Play a game" << std::endl
		<< "2. Generate a solution" << std::endl
		<< "3. Quit" << std::endl
		<< "?: ";
	std::cin >> option;

	// Option 1: Play
	if (option == 1){
		std::cout << "Game Size: ";
		std::cin >> gamesize;
		Tower t (gamesize);

		// if the tower3 has the number of disks the user wish to play
		// then game over
		while (t.get_tower3().size() != t.get_disknumber()){
			std::cout << "Enter a command (eg \"move 1 to 2\" or \"quit\")" << std::endl
				<< "?: ";

			std::cin >> move >> fromTower >> to >> toTower;
			if (t.check(fromTower, toTower)){
				t.move(fromTower, toTower);
			}
			drawTowers(t);
		}
		std::cout << "Congratulations! You've won!!!" << std::endl;
	}

	// Option 2: Solution
	else if (option == 2){
		std::cout << "Game Size: ";
		std::cin >> gamesize;
		Tower t (gamesize);
		std::cout << "Enter a file name to save moves: ";
		std::cin >> filename;
		os.open(filename.c_str());
		t.printsolution(1, 2, 3,os);
	}

	// Option 3: Quit
	else if (option == 3){
		std::cout << "Goodbye!" << std::endl;
	}
	
	return 0;
}