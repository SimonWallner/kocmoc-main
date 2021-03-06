
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
#include <kocmoc-core/scene/OrthoCamera.hpp>

#include <kocmoc-core/time/Timer.hpp>

#include <kocmoc-core/component/CameraController.hpp>

using namespace kocmoc;
using namespace kocmoc::core::types;
using namespace kocmoc::core::input;
using namespace kocmoc::core::component;
using namespace kocmoc::component;

using std::string;

using kocmoc::core::util::Properties;
using kocmoc::core::renderer::Context;
using kocmoc::core::renderer::Shader;
using kocmoc::core::scene::FilmCamera;
using kocmoc::core::scene::OrthoCamera;
using kocmoc::core::time::Timer;


using glm::vec3;


Kocmoc::Kocmoc(Properties* _props)
	: props(_props)
	, running(true)
	, quit(symbolize("quit"))
	, screenShot(symbolize("screen-shot"))
	, kw(this)
{
	string configFile = props->getString(symbolize("config-file"));
	string coreConfigFile = props->getString(symbolize("core-config-file"));
	core::util::parser::parseConfigXMLFileIntoProperties(configFile, props);
	core::util::parser::parseConfigXMLFileIntoProperties(coreConfigFile, props);
	props->dumpCache();
	
	
	Context context;
	context.getInfo();
	
	InputManager inputManager(context.getWindowHandle());
	
	inputManager.registerButtonEventListener(quit, &kw);
	inputManager.bindKeyToButtonEvent(256, quit);	// ESC

	inputManager.registerButtonEventListener(screenShot, &kw);
	inputManager.bindKeyToButtonEvent(',', screenShot);

	
	init();
	
	FilmCamera* camera = new FilmCamera(vec3(0, 0, 4), vec3(0, 0, 0), vec3(0, 1, 0));
	camera->setGateInPixel(720, 432);
	camera->setFilterMarginInPixel(0, 0);
	camera->setAngleOfView(1.5f);
	
	CameraController cameraController(camera, &inputManager);
	inputManager.dumpBindings();	
	
	Timer* timer = new Timer();
	
	while (running == true && context.isAlive())
	{	
		float deltaT = timer->getDeltaT();
		
		// pre update
		timer->tick();
		cameraController.onUpdate(deltaT);
		inputManager.poll();
		
		// update
		ship->update(deltaT);
		
		
		// post update
		camera->updateMatrixes();
		
		// render
		ship->render(camera);
		
		// post render
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

Kocmoc::~Kocmoc()
{
	std::cout << "destroying kocmoc" << std::endl;
}
