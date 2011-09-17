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
#include <kocmoc-core/renderer/Shader.hpp>

#include <kocmoc-core/input/InputManager.hpp>

#include <kocmoc-core/scene/FilmCamera.hpp>

#include <kocmoc-core/time/Timer.hpp>


using namespace kocmoc;
using namespace kocmoc::core::types;
using namespace kocmoc::core::input;
using namespace kocmoc::component;

using std::string;

using kocmoc::core::util::Properties;
using kocmoc::core::renderer::Context;
using kocmoc::core::renderer::Shader;
using kocmoc::core::scene::FilmCamera;
using kocmoc::core::time::Timer;

using glm::vec3;


Kocmoc::Kocmoc(Properties* _props)
	: props(_props)
	, running(true)
	, quit(symbolize("quit"))
	, kw(this)
{
	string configFile = props->getString(symbolize("config-file"));
	core::util::parser::parseConfigXMLFileIntoProperties(configFile, props);
	props->dumpCache();
	
	
	Context context;
	context.getInfo();
	
	InputManager inputManager(context.getWindowHandle());
	
	inputManager.registerButtonEventListener(quit, &kw);
	inputManager.bindButtonEventToKey(quit, 81);	// q
	inputManager.bindButtonEventToKey(quit, 256);	// ESC (not working ???)
	
	init();
	
	FilmCamera* camera = new FilmCamera(vec3(-10, 0, 0), vec3(0, 0, 0), vec3(0, 0, 1));
	
	Timer* timer = new Timer();
	
	while (running == true && context.isAlive())
	{
		timer->tick();
		inputManager.poll();
		
		ship->update(timer->getDeltaT());
		ship->render(camera);
		
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
	// try out a shader
	Symbol mediaPath = symbolize("media-path");
	string vert = props->getString(mediaPath) + "shaders/base.vert";
	string frag = props->getString(mediaPath) + "shaders/base.frag";
	
	Shader shader(vert, frag);
	shader.prepare();
	if (shader.isPrepared())
	{
		std::cout << "shader is ready to roll" << std::endl;
	}
	
	
	ship = new Ship("the player ship", props);
	ship->init();
}

