#pragma once

#include "Port.h"

class InputPort final : public Port 
{

public:

	~InputPort() override = default;

	InputPort(const std::string & _port_name);

	void setValue(bool _value);

	bool getValue(void) const override;

private:
	
	InputPort(const InputPort &) = delete;
	InputPort & operator = (const  InputPort &) = delete;

	port_type getPortType(void) const override;

	bool value = false;

};