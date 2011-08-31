//
//  Ship.cpp
//  kocmoc
//
//  Created by Simon Wallner on 30.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Ship.hpp"

using namespace kocmoc::component;

void Ship::init()
{
	objectBehaviour = new ObjectBehaviour();
	shipBehaviour = new ShipBehaviour();
	renderable = new Renderable();
	shipController = new ShipController();
	
	addComponent(objectBehaviour);
	addComponent(shipBehaviour);
	addComponent(renderable);
	addComponent(shipController);
	
	registerUpdateReceiver(shipController);
	registerRenderReceiver(renderable);
	
	shipController->init();
	objectBehaviour->init();
	shipBehaviour->init();
	renderable->init();
}