//
//  Ship.cpp
//  kocmoc
//
//  Created by Simon Wallner on 30.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Ship.hpp"

#include <kocmoc-core/scene/AssetLoader.hpp>

using namespace kocmoc::component;
using namespace kocmoc::core::component;

using kocmoc::core::scene::AssetLoader;
using kocmoc::core::types::symbolize;

void Ship::init()
{
	objectBehaviour = new ObjectBehaviour();
	shipBehaviour = new ShipBehaviour();
	shipController = new ShipController();
	
	AssetLoader loader;
	loader.addResourcePath(props->getString(symbolize("media-path")));
	
	renderable = loader.load(props->getString(symbolize("test-model-name")));
	
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