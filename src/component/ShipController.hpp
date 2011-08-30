//
//  ShipController.h
//  kocmoc
//
//  Created by Simon Wallner on 30.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef KOCMOC_COMPONENT_SHIP_CONTROLLER_HPP
#define KOCMOC_COMPONENT_SHIP_CONTROLLER_HPP

#include <kocmoc-core/componentSystem/Component.hpp>

namespace kocmoc
{
	namespace component
	{
		class ShipBehaviour;
		
		class ShipController : public core::componentSystem::Component
		{
		public:
			void onUpdate(void);
			
			void init(void);

		private:
			ShipBehaviour* shipBehaviour;
		};
	}
}

#endif
