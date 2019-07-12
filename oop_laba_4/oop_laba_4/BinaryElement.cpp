
#include "stdafx.h"
#include "BinaryElement.h"

BinaryElement :: BinaryElement(element_type _operation_code, Element *_element1, Element *_element2)
{

	if ((_element1 == nullptr) || (_element2 == nullptr))
	{
		try
		{
			throw std::logic_error("undefined value at the input");
		}
		catch (std::exception const & _e)
		{
			std::cout << _e.what() << std::endl;
		}
	}

	if ((_operation_code != OR) && (_operation_code != AND) && (_operation_code != XOR))
	{
		try
		{
			throw std::logic_error("invalid operation code");
		}
		catch (std::exception const & _e)
		{
			std::cout << _e.what() << std::endl;
		}
	}

	operation_code = _operation_code;
	element1 = _element1;
	element2 = _element2;
}

bool BinaryElement :: evaluate(void) const
{
	if (operation_code == AND)
	{
		if ((element1 != nullptr) && (element2 == nullptr))
		{
			return element1->evaluate() && false;
		}

		if ((element1 == nullptr) && (element2 != nullptr))
		{
			return element2->evaluate() && false;
		}

		if ((element1 == nullptr) && (element2 == nullptr))
		{
			return  false;
		}

		return element1->evaluate() && element2->evaluate();
	}

	if (operation_code == OR)
	{
		if ((element1 != nullptr) && (element2 == nullptr))
		{
			return element1->evaluate() || false;
		}

		if ((element1 == nullptr) && (element2 != nullptr))
		{
			return element2->evaluate() || false;
		}

		if ((element1 == nullptr) && (element2 == nullptr))
		{
			return  false;
		}

		return element1->evaluate() || element2->evaluate();
	}

	if (operation_code == XOR)
	{
		if ((element1 != nullptr) && (element2 == nullptr))
		{
			return element1->evaluate() ^ false;
		}

		if ((element1 == nullptr) && (element2 != nullptr))
		{
			return element2->evaluate() ^ false;
		}

		if ((element1 == nullptr) && (element2 == nullptr))
		{
			return  false;
		}

		return element1->evaluate() ^ element2->evaluate();
	}
}




