////////////////////////////////////////////////////////////////////////////////
// @file tower.h
// @author Jiahao Huo
// @date 2016-04-28
//
// Description: This is the header file of Tower class and related non-member
// functions to draw the towers. 
// The class can construct a Tower of Hanoi give the number of floors; move the 
// floors according to user's instructions; determine if it is legal to move the
// floor and print the required move to a file for a give number of floors.
//
// The functions can draw the disks of the tower, draw the base of tower and then
// draw the tower. 
// 
// Known bugs: None yet.
////////////////////////////////////////////////////////////////////////////////
#ifndef TOWER_H
#define TOWER_H

#include <string>
#include <vector>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// @class Tower
// @brief Construct a Tower of Hanoi and move the floors.
//
// The Tower class can move the floors according to user's input and determine
// if it is legal to move the floor. The class can return the respective heights 
// of tower 1 2 and 3. 
////////////////////////////////////////////////////////////////////////////////

class Tower{
public:

	// Default constructor - default level of floors is 1
	Tower();

	// Construct a Tower of Hanoi of height a
	Tower(int a);

	// Print the required moves to move from Tower 1 to 3
	// @param the current location of the disk
	// @param the tower where the disk is temporaily stored
	// @param the final destination of the disk
	void printsolution(int currentT, int tempT, int finalT, std::ostream &os);

	// Move a floor from a Tower to another Tower
	// @param the current location of the disk
	// @param the location the disk is gonna move to
	void move(int formtower, int totower);

	// Check whether it is legal to move a floor from a Tower to another
	// If there is no disk in fromtower or the top disk fromtower is larger than
	// the one of totower, it is illegal.
	// @param the current location of the disk
	// @param the location the disk is gonna move to
	// @return true:able to move; false: unable to move
	bool check(int formtower, int totower);

	// return the vectors containing the disk information for tower 1 2 and 3 respectively
	std::vector<int> get_tower1() const { return tower1_; }
	std::vector<int> get_tower2() const { return tower2_; }
	std::vector<int> get_tower3() const { return tower3_; }

	// return the number of disks the user wants to play
	int get_disknumber() const { return disknum_; }
	
private:
	// stores the disk information of the tower. The fisrt index contains the largest disk.
	// The size of the disk decreases as the index of the vector increase.
	std::vector<int> tower1_;
	std::vector<int> tower2_;
	std::vector<int> tower3_;

	// the number of disks the user wish to play
	int disknum_;
};

// draw the graphic representation of three Towers of Hanoi
// @param the information of towers
void drawTowers(Tower t);

// draw the graphic representation of disks in Towers
// @param the size of a disk
// @return a string that looks like a disk 
std::string drawdisk(int times);

// draw the graphic representation of the base of a Tower
// @param the length of the base
// @return a string that looks like a base of a Tower
std::string drawbase(int times);

#endif