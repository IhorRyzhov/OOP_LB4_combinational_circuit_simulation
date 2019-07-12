#pragma once

#include "Element.h"
#include "InputPort.h"

class InputPortElement final : public Element
{

public:

	~InputPortElement() override = default;

	InputPortElement(const InputPort &_input_port);

	bool evaluate(void) const override;

private:

	InputPortElement(const InputPortElement &) = delete;
	InputPortElement & operator = (const InputPortElement &) = delete;

	const InputPort &input_port;

};