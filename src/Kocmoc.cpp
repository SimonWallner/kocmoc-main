//
//  Kocmoc.cpp
//  kocmoc
//
//  Created by Simon Wallner on 28.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Kocmoc.hpp"

#include <iostream>
#include <string>

#include <kocmoc-core/util/Properties.hpp>
#include <kocmoc-core/util/util.hpp>
#include <kocmoc-core/types/Symbol.hpp>
#include <kocmoc-core/renderer/Context.hpp>
#include <kocmoc-core/input/InputManager.hpp>

using namespace kocmoc;
using namespace kocmoc::core::types;
using namespace kocmoc::core::input;

using namespace kocmoc::component;

using std::string;

using kocmoc::core::util::Properties;
using kocmoc::core::renderer::Context;


Kocmoc::Kocmoc(Properties* _props)
	: props(_props)
	, running(true)
	, quit(symbolize("quit"))
	, kw(this)
{
	string configFile = props->getString(symbolize("config-file"));
	core::util::parseConfigXMLFileIntoProperties(configFile, props);
	props->dumpCache();
	
	
	Context context;
	context.getInfo();
	
	InputManager inputManager(context.getWindowHandle());
	
	inputManager.registerButtonEventListener(quit, &kw);
	inputManager.bindButtonEventToKey(quit, 81);	// q
	inputManager.bindButtonEventToKey(quit, 256);	// ESC (not working ???)
	
	init();
	
	while (running == true && context.isAlive())
	{
		inputManager.poll();
		
		ship->update();
		ship->render();
		
		context.swapBuffers();
	}
}

void Kocmoc::printIntro()
{
	std::cout	<< "//////////////////////////////////////////////////////////////////////////////" << std::endl
	<< "   *           .                          .                          .        " << std::endl
	<< "                             .                   .                         " << std::endl
	<< "           .                                                    *           " << std::endl  
	<< ".                                        .                               " << std::endl 
	<< "                    .              .                  .                 .        " << std::endl
	<< "                                                                      " << std::endl
	<< "                                                                             " << std::endl
	<< "         .           *                      .                 .                " << std::endl
	<< "                               .           *                                   " << std::endl
	<< "                                                                         .    " << std::endl
	<< "                      .             .                         .                 " << std::endl
	<< "*          .                                                                   " << std::endl
	<< "                                                 .         0                   " << std::endl
	<< "                             .                            /|\\                    " << std::endl
	<< "          .                                                           .        " << std::endl
	<< "                                                .                             " << std::endl
	<< "                     *               .                    .                     " << std::endl
	<< "   .                                                                 *         " << std::endl
	<< "                                      .                                       " << std::endl
	<< "//// kocmoc //////////////////////////////////////////////////////////////////" << std::endl;
}

void Kocmoc::init()
{
	ship = new Ship("the player ship", props);
	ship->init();
}

