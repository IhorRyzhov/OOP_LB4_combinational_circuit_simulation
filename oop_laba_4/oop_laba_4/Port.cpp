#include "stdafx.h"
#include "Port.h"


Port :: Port(const std::string & _port_name, port_type _type)
	: port_name(_port_name), type(_type)
{
	
}

const std::string & Port :: getName(void) const
{
	return port_name;
}