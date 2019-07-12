#pragma once

#include <iostream>
#include "definitions.h"

class Element
{

protected:

	Element(void) = default;

public:

	virtual ~Element(void) {}

	virtual bool evaluate(void) const = 0;

};