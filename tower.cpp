////////////////////////////////////////////////////////////////////////////////
// @file tower.cpp
// @author Jiahao Huo	
// @date 2016-04-28
//
// Description: This is the implementation file for tower.h
//
// Known bugs: None yet.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "tower.h"

Tower::Tower(){
	tower1_ = { 1 };
	tower2_ = { 0 };
	tower3_ = { 0 };
	disknum_ = 1;
}

Tower::Tower(int a){
	// tower1 has "a" number of disks
	tower1_.resize(a);
	
	// largest disk size is store in the first index of a vector
	// the size decreases as the index increase
	for (int i = tower1_.size()-1; i >= 0; --i){
		tower1_[i] = tower1_.size()-i;
	}
	disknum_ = a;
}

void Tower::printsolution(int currentT, int tempT, int finalT,std::ostream &os){
	// using recursion to solve the problem of Towers of Hanoi
	if (tower1_.size() != 0){
		Tower(tower1_.size() - 1).printsolution(currentT, finalT, tempT,os);
		// print the moves to a file
		os << "move " << currentT << " to " << finalT << std::endl;
		Tower(tower1_.size() - 1).printsolution(tempT, currentT, finalT,os);
	}
}

bool Tower::check(int formtower, int totower){
	if (formtower == 1 && totower == 2){
		// if the fromtower has no disk, cannot move
		if (tower1_.size() == 0){
			std::cout << "There is no floor to move from Tower " << formtower << "."<< std::endl;
			return false;
		}
		// if the topdisk of fromtower is larger than the top disk of totower, cannot move
		else if (tower1_.size()>0 && tower2_.size() >0 && tower1_[tower1_.size() - 1] > tower2_[tower2_.size() - 1]){
			std::cout << "Cannot move from Tower " << formtower << " to Tower " << totower << "." << std::endl;
			return false;
		}
		else {
			return true;
		}
	}
	else if (formtower == 2 && totower == 1){
		if (tower2_.size() == 0){
			std::cout << "There is no floor to move from Tower " << formtower << "." << std::endl;
			return false;
		}
		else if (tower1_.size()>0 && tower2_.size() >0 && tower2_[tower2_.size() - 1] > tower1_[tower1_.size() - 1]){
			std::cout << "Cannot move from Tower " << formtower << " to Tower " << totower << "." << std::endl;
			return false;
		}
		else {
			return true;
		}
	}
	else if (formtower == 1 && totower == 3) {
		if (tower1_.size() == 0){
			std::cout << "There is no floor to move from Tower " << formtower << "." << std::endl;
			return false;
		}
		else if (tower1_.size()>0 && tower3_.size() >0 && tower1_[tower1_.size() - 1] > tower3_[tower3_.size() - 1]){
			std::cout << "Cannot move from Tower " << formtower << " to Tower " << totower << "." << std::endl;
			return false;
		}
		else {
			return true;
		}
	}
	else if (formtower == 2 && totower == 3) {
		if (tower2_.size() == 0){
			std::cout << "There is no floor to move from Tower " << formtower << "." << std::endl;
			return false;
		}
		else if (tower3_.size()>0 && tower2_.size() >0 && tower2_[tower2_.size() - 1] > tower3_[tower3_.size() - 1]){
			std::cout << "Cannot move from Tower " << formtower << " to Tower " << totower << "." << std::endl;
			return false;
		}
		else {
			return true;
		}
	}
	else if (formtower == 3 && totower == 2) {
		if (tower3_.size() == 0){
			std::cout << "There is no floor to move from Tower " << formtower << "." << std::endl;
			return false;
		}
		else if (tower3_.size()>0 && tower2_.size() >0 && tower3_[tower3_.size() - 1] > tower2_[tower2_.size() - 1]){
			std::cout << "Cannot move from Tower " << formtower << " to Tower " << totower << "." << std::endl;
			return false;
		}
		else {
			return true;
		}
	}
	else if (formtower == 3 && totower == 1) {
		if (tower3_.size() == 0){
			std::cout << "There is no floor to move from Tower " << formtower << "." << std::endl;
			return false;
		}
		else if (tower1_.size()>0 && tower3_.size() >0 && tower3_[tower3_.size() - 1] > tower1_[tower1_.size() - 1]){
			std::cout << "Cannot move from Tower " << formtower << " to Tower " << totower << "." << std::endl;
			return false;
		}
		else {
			return true;
		}
	}
}

void Tower::move(int formtower, int totower){
	if (formtower == 1 && totower == 2){
		// the disk to move is always the smallest disk
		// so the index of the smallest disk is (the size of the vector -1)
		// add the value of the disk size to the totower's vector
		// remove the value of disk size from the fromtower's vector
		tower2_.push_back(tower1_[tower1_.size() - 1]);
		tower1_.pop_back();
	}
	else if (formtower == 2 && totower == 1){
		tower1_.push_back(tower2_[tower2_.size() - 1]);
		tower2_.pop_back();
	}
	else if (formtower == 1 && totower == 3) {
		tower3_.push_back(tower1_[tower1_.size() - 1]);
		tower1_.pop_back();
	}
	else if (formtower == 2 && totower == 3) {
		tower3_.push_back(tower2_[tower2_.size() - 1]);
		tower2_.pop_back();
	}
	else if (formtower == 3 && totower == 2) {
		tower2_.push_back(tower3_[tower3_.size() - 1]);
		tower3_.pop_back();
	}
	else if (formtower == 3 && totower == 1) {
		tower1_.push_back(tower3_[tower3_.size() - 1]);
		tower3_.pop_back();
	}
}

std::string drawdisk(int times){

	// if times is 0, there is no disk
	if (times == 0){
		return "";
	}

	char diskcomp = '*';
	std::string s = "[";
	for (int i = 0; i < times; ++i){
		s += diskcomp;
	}
	s += "]";
	return s;
}

std::string drawbase(int times){
	char basecomp = '_';
	std::string s = "";
	for (int i = 0; i < times; ++i){
		s += basecomp;
	}
	return s;
}

void drawTowers(Tower t){

	// the width between each tower
	const int WIDTH = t.get_disknumber() + 8;
	std::vector<int> tower1 = t.get_tower1();
	std::vector<int> tower2 = t.get_tower2();
	std::vector<int> tower3 = t.get_tower3();

	// if the vectors of towers are of different length
	// resize the vectors, so that if there is no disk at that level of floor
	// the smallest disk is of size 0 (the largest indices is 0)
	// then the towers is drawen at the same horizon
	tower1.resize(t.get_disknumber());
	tower2.resize(t.get_disknumber());
	tower3.resize(t.get_disknumber());

	// draw the disks for three towers
	for (int i = t.get_disknumber() - 1; i >= 0; --i){
		std::cout << std::setw(WIDTH) << std::left << drawdisk(tower1[i])
			<< std::setw(WIDTH) << std::left << drawdisk(tower2[i])
			<< std::setw(WIDTH) << std::left << drawdisk(tower3[i])
			<< std::endl;
	}

	// draw the bases for three towers
	for (int i = 0; i < 3; ++i){
		std::cout << std::setw(WIDTH) << std::left << drawbase(t.get_disknumber() + 5);
	}
	std::cout << std::endl;

	// label the towers
	for (int i = 1; i <= 3; ++i){
		std::string name = "Tower " + std::to_string(i);
		std::cout << std::setw(WIDTH) << std::left << name;
	}
	std::cout << std::endl;
}
