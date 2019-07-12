#include "stdafx.h"
#include "InputPortElement.h"

InputPortElement :: InputPortElement(const InputPort &_input_port)
	: input_port(_input_port)
{

}

bool InputPortElement :: evaluate(void) const
{
	return input_port.getValue();
}
