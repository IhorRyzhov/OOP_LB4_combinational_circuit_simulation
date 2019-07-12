#pragma once

#include <string>
#include "definitions.h"

class Port
{

protected:

	Port(const std::string & _port_name, port_type _type);

public:

	virtual ~Port(void) {}	

	const std::string & getName(void) const;

	virtual bool getValue(void) const = 0;

	virtual port_type getPortType(void) const = 0;

	port_type type;

private:	

	const std::string port_name;

};
