//
//  Ship.cpp
//  kocmoc
//
//  Created by Simon Wallner on 30.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Ship.hpp"

#include "ObjectBehaviour.hpp"
#include "ShipBehaviour.hpp"

using namespace kocmoc::component;

void Ship::init()
{
	addComponent(new ObjectBehaviour());
	addComponent(new ShipBehaviour());
}