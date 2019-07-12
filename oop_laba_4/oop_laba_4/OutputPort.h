#pragma once

#include "Port.h"
#include "Element.h"

class OutputPort final : public Port
{

public:
	
	~OutputPort() override = default;

	OutputPort(Element *_element, const std::string & _port_name);

	bool getValue(void) const override;

private:

	OutputPort(const OutputPort &) = delete;
	OutputPort & operator = (const OutputPort &) = delete;

	port_type getPortType(void) const override;

	Element *element = nullptr;

};