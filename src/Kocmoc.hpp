//
//  Kocmoc.hpp
//  kocmoc
//
//  Created by Simon Wallner on 28.08.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef KOCMOC_KOCMOC_HPP
#define KOCMOC_KOCMOC_HPP


namespace kocmoc
{
	namespace core
	{
		namespace util
		{
			class Properties;
		}
	}
	
	/**
	 * The main game class. It is created in main() and does everything from
	 * there.
	 */
	class Kocmoc
	{
	public:
		
		/**
		 * Create a new kocmoc.
		 * @param props basic properties with all relevant startup information
		 *			like command line arguments and so on
		 */
		Kocmoc(core::util::Properties* props);
		
		/**
		 * print the awesome ASCII art intro.
		 */
		void printIntro(void);

	private:
		core::util::Properties* props;
	};
}

#endif
