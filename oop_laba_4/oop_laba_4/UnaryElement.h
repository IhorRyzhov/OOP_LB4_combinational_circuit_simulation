#pragma once

#include "Element.h"

class UnaryElement final : public Element
{

public:

	~UnaryElement() override = default;

	UnaryElement(element_type _operation_code, Element *_element);

	bool evaluate(void) const override;

private:

	UnaryElement(const UnaryElement &) = delete;
	UnaryElement & operator = (const UnaryElement &) = delete;

	Element *element = nullptr;  
	element_type operation_code;

};