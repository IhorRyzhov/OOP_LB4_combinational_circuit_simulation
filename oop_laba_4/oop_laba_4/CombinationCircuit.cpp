#include "stdafx.h"
#include "CombinationCircuit.h"

CombinationCircuit :: ~CombinationCircuit(void)
{
	for (auto it = ports.begin(); it != ports.end(); it++)
	{
		delete it->second;
	}

	for (auto it = elements.begin(); it != elements.end(); it++)
	{		
		delete it->first;		
	}
}

void CombinationCircuit :: AddElement(Element * element)
{
	if (elements.count(element))
	{
		try
		{
			throw std::logic_error("logical element already exists");
		}
		catch (std::exception const & _e)
		{
			std::cout << _e.what() << std::endl;
		}
	}
	else
	{
		elements[element] = true;
	}
}

void CombinationCircuit :: AddPort(Port *port)
{
	if (ports.count(port->getName()))
	{
		try
		{
			throw std::logic_error("port already exists");
		}
		catch (std::exception const & _e)
		{
			std::cout << _e.what() << std::endl;
		}		
	}
	else
	{
		ports[port->getName()] = port;
	}
}

InputPort * CombinationCircuit :: FindInputPort(const std::string & port_name)
{
	if (ports.count(port_name))
	{
		if (ports[port_name]->getPortType() == INPUT_PORT)
		{
			return static_cast<InputPort*>(ports[port_name]);
		}
	}
	
	return nullptr;
}

Port * CombinationCircuit :: FindPort(const std::string & port_name)
{
	if (ports.count(port_name))
	{
		return ports[port_name];
	}
	else
	{
		return nullptr;
	}
}


