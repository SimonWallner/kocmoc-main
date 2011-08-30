//
//  Ship.pp
//  kocmoc
//
//  Created by Simon Wallner on 30.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef KOCMOC_COMPONENT_SHIP_HPP
#define KOCMOC_COMPONENT_SHIP_HPP

#include <kocmoc-core/componentSystem/Object.hpp>

namespace kocmoc
{
	namespace component
	{
		class Ship : public kocmoc::core::componentSystem::Object
		{
			void onMessage(void);
			
			void init(void);
		};
	}
}

#endif