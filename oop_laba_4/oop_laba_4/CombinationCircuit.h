#pragma once

#include <unordered_map>

#include "InputPortElement.h"
#include "BinaryElement.h"
#include "UnaryElement.h"
#include "InputPort.h"
#include "OutputPort.h"

#include <memory>

class CombinationCircuit final
{

public:

	CombinationCircuit(void) = default;

	~CombinationCircuit(void);

	void AddElement(Element * element);

	void AddPort(Port *port);

	InputPort * FindInputPort(const std::string & port_name);

	Port * FindPort(const std::string & port_name);
	
private:

	CombinationCircuit & operator = (const CombinationCircuit &) = delete;
	
	std::unordered_map<Element*, bool > elements;
	std::unordered_map< std::string , Port* > ports;

};
