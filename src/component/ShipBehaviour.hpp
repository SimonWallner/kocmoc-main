//
//  ShipBehaviour.h
//  kocmoc
//
//  Created by Simon Wallner on 30.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef KOCMOC_COMPONENT_SHIP_BEHAVIOUR
#define KOCMOC_COMPONENT_SHIP_BEHAVIOUR

#include <kocmoc-core/componentSystem/Component.hpp>

#include "ObjectBehaviour.hpp"

namespace kocmoc
{
	namespace component
	{
		class ShipBehaviour : public core::componentSystem::Component
		{
		public:
			ShipBehaviour(void) {};
			
			void left(void)
			{
				objectBehaviour->position += glm::vec3(-1, 0, 0);
			}
			
			void right(void)
			{
				objectBehaviour->position += glm::vec3(1, 0, 0);
			}
			
			void init(void);
			
		private:
			ObjectBehaviour* objectBehaviour;
		};
	}
}

#endif