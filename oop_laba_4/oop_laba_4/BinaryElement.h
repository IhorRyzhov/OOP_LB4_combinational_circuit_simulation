#pragma once

#include "Element.h"

class BinaryElement final : public Element
{

public:	

	~BinaryElement() override = default;

	BinaryElement(element_type _operation_code, Element *_element1, Element *_element2);

	bool evaluate(void) const override;


private:

	BinaryElement(const BinaryElement &) = delete;
	BinaryElement & operator = (const BinaryElement &) = delete;

	Element *element1 = nullptr;
	Element *element2 = nullptr;

	element_type operation_code;

};