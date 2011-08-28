#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include <kocmoc-core/util/Properties.hpp>
#include <kocmoc-core/util/util.hpp>

using namespace kocmoc::core::util;
namespace po = boost::program_options;

int main(int argc, char *argv[])
{	
	// parse command line args
	
	std::string configFile;

	try
	{
		po::options_description options("kocmoc program options");
		options.add_options()
			("version,v", "print version string")
			("help,h", "produce help message")
			("config-file,c", po::value(&configFile), "xml config file to parse");
		
		po::variables_map vars;        
		po::store(po::parse_command_line(argc, argv, options), vars);
		po::notify(vars);

		
		if (vars.count("help")) {
			std::cout << options << "\n";
			return 1;
		}


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
		} // kocmoc ASCII intro
		
		
		Properties props;
		if (vars.count("config-file"))
			parseConfigXMLFileIntoProperties(configFile, &props);
		else
			parseConfigXMLFileIntoProperties("kocmoc-config.xml", &props);
		
		props.dumpCache();
		
	}
    catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
    }
	
}