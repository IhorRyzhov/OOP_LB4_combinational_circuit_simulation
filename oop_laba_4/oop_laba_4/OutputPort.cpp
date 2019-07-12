#include "stdafx.h"
#include "OutputPort.h"

OutputPort :: OutputPort(Element *_element, const std::string & _port_name)
	: Port(_port_name, OUTPUT_PORT)
{
	element = _element;
}

bool OutputPort :: getValue(void) const
{
	if (element != nullptr)
	{
		return element->evaluate();
	}
	else
	{
		return false;
	}
}

port_type OutputPort::getPortType(void) const
{
	return type;
}



