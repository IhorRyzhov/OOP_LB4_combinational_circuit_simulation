#include "stdafx.h"
#include "UnaryElement.h"

UnaryElement :: UnaryElement(element_type _operation_code, Element *_element)
{
	if (_element == nullptr)
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

	if ( (_operation_code != BUFFER)&&(_operation_code != NOT) )
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
	element = _element;
}

bool UnaryElement :: evaluate(void) const
{
	if (operation_code == BUFFER)
	{
		if (element == nullptr)
		{
			return false;
		}
		return element->evaluate();
	}

	if (operation_code == NOT)
	{
		if (element == nullptr)
		{
			return true;
		}
		return !element->evaluate();
	}
}
