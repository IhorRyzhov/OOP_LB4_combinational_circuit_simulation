#pragma once

#include "CombinationCircuit.h"
#include <iostream>
#include <fstream>

void ReadFile(CombinationCircuit * circuit, const std::string & path_to_file)
{
	std::ifstream file(path_to_file);

	if (!file.is_open())
	{
		try
		{
			throw std::logic_error("File can not be opened!");
		}
		catch (std::exception const & _e)
		{
			std::cout << _e.what() << std::endl;
		}

		return;
	}

	std::string s;
	std::string port_name;

	while (!file.eof())
	{
		file >> s;

		if (s == "SET_INPUT")
		{
			file >> s;
			if (circuit->FindInputPort(s))
			{
				port_name = s;
				file >> s;

				if (s == "true")
				{
					circuit->FindInputPort(port_name)->setValue(true);
				}
				else
					if (s == "false")
					{
						circuit->FindInputPort(port_name)->setValue(false);
					}
					else
					{
						try
						{
							throw std::logic_error("Incorrect  format");
						}
						catch (std::exception const & _e)
						{
							std::cout << _e.what() << std::endl;
						}
					}
			}
			else
			{
				try
				{
					file >> s;
					throw std::logic_error("Input Port can not be find");
				}
				catch (std::exception const & _e)
				{
					std::cout << _e.what() << std::endl;
				}
			}

		}
		else
			if (s == "SHOW_PORT")
			{
				file >> s;
				if (circuit->FindPort(s))
				{
					std::cout << s << " : " << circuit->FindPort(s)->getValue() << std::endl;
				}
				else
				{
					try
					{
						throw std::logic_error("Port can not be find");
					}
					catch (std::exception const & _e)
					{
						std::cout << _e.what() << std::endl;
					}
				}

			}
			else
			if (s == "n")
			{
				std::cout << std::endl;
			}
			else
			{
				try
				{
					throw std::logic_error("Incorrect  format");
				}
				catch (std::exception const & _e)
				{
					std::cout << _e.what() << std::endl;
				}
			}

	}

	file.close();
}

