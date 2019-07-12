#include "stdafx.h"
#include "InputPort.h"

InputPort :: InputPort(const std::string & _port_name)
	: Port(_port_name, INPUT_PORT)
{

}

void InputPort :: setValue(bool _value)
{
	value = _value;
}

bool InputPort :: getValue(void) const
{
	return value;
}

port_type InputPort:: getPortType(void) const
{
	return INPUT_PORT;
}
