// Maze Runners.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "CommonToEntities.h"
using namespace std;

int main()
{
    CommonToEntities o1 = CommonToEntities(15, 15, 2);
    cout << "Collision Box Height: " << o1.getCollisionBoxHeight() << "\n" 
        << "Collision Box Width: "  << o1.getCollisionBoxWidth() << "\n"
        << "Movement Speed: " << o1.getMovementSpeed()<< endl;
    
}
