

#include "stdafx.h"
#include "CombinationCircuit.h"
#include "read_file.h"
#include "testlib.hpp"

DECLARE_OOP_TEST(ELEMENT_OR)
{
	InputPort p_in_1("p_in_1");
	InputPort p_in_2("p_in_2");

	InputPortElement p1(p_in_1);
	InputPortElement p2(p_in_2);

	BinaryElement el(OR, &p1, &p2);

	OutputPort p_out(&el, "p_out");

	p_in_1.setValue(false);
	p_in_2.setValue(false);
	assert(p_out.getValue() == false);

	p_in_1.setValue(true);
	p_in_2.setValue(false);
	assert(p_out.getValue() == true);

	p_in_1.setValue(false);
	p_in_2.setValue(true);
	assert(p_out.getValue() == true);

	p_in_1.setValue(true);
	p_in_2.setValue(true);
	assert(p_out.getValue() == true);
}

DECLARE_OOP_TEST(ELEMENT_AND)
{
	InputPort p_in_1("p_in_1");
	InputPort p_in_2("p_in_2");

	InputPortElement p1(p_in_1);
	InputPortElement p2(p_in_2);

	BinaryElement el(AND, &p1, &p2);

	OutputPort p_out(&el, "p_out");

	p_in_1.setValue(false);
	p_in_2.setValue(false);
	assert(p_out.getValue() == false);

	p_in_1.setValue(true);
	p_in_2.setValue(false);
	assert(p_out.getValue() == false);

	p_in_1.setValue(false);
	p_in_2.setValue(true);
	assert(p_out.getValue() == false);

	p_in_1.setValue(true);
	p_in_2.setValue(true);
	assert(p_out.getValue() == true);
}

DECLARE_OOP_TEST(ELEMENT_XOR)
{
	InputPort p_in_1("p_in_1");
	InputPort p_in_2("p_in_2");

	InputPortElement p1(p_in_1);
	InputPortElement p2(p_in_2);

	BinaryElement el(XOR, &p1, &p2);

	OutputPort p_out(&el, "p_out");

	p_in_1.setValue(false);
	p_in_2.setValue(false);
	assert(p_out.getValue() == false);

	p_in_1.setValue(true);
	p_in_2.setValue(false);
	assert(p_out.getValue() == true);

	p_in_1.setValue(false);
	p_in_2.setValue(true);
	assert(p_out.getValue() == true);

	p_in_1.setValue(true);
	p_in_2.setValue(true);
	assert(p_out.getValue() == false);
}

DECLARE_OOP_TEST(ELEMENT_BUFFER)
{
	InputPort p_in("p_in");

	InputPortElement p(p_in);

	UnaryElement el(BUFFER, &p);

	OutputPort p_out(&el, "p_out");

	p_in.setValue(false);
	assert(p_out.getValue() == false);

	p_in.setValue(true);
	assert(p_out.getValue() == true);
}

DECLARE_OOP_TEST(ELEMENT_NOT)
{
	InputPort p_in("p_in");

	InputPortElement p(p_in);

	UnaryElement el(NOT, &p);

	OutputPort p_out(&el, "p_out");

	p_in.setValue(false);
	assert(p_out.getValue() == true);

	p_in.setValue(true);
	assert(p_out.getValue() == false);
}

DECLARE_OOP_TEST(ELEMENT_BUFFER_NO_INPUT_PORTS)
{
	UnaryElement el(BUFFER, nullptr);

	OutputPort p_out(&el, "p_out");
	
	assert(p_out.getValue() == false);
}

DECLARE_OOP_TEST(ELEMENT_NOT_NO_INPUT_PORTS)
{
	UnaryElement el(NOT, nullptr);

	OutputPort p_out(&el, "p_out");

	assert(p_out.getValue() == true);
}

DECLARE_OOP_TEST(ELEMENT_OR_NO_INPUT_PORTS)
{
	BinaryElement el_1(OR, nullptr, nullptr);
	OutputPort p_out_1(&el_1, "p_out_1");
	assert(p_out_1.getValue() == false);

	InputPort p_in("p_in");
	InputPortElement p(p_in);

	BinaryElement el_2(OR, nullptr, &p);
	OutputPort p_out_2(&el_2, "p_out_2");
	p_in.setValue(false);
	assert(p_out_2.getValue() == false);
	p_in.setValue(true);
	assert(p_out_2.getValue() == true);

	BinaryElement el_3(OR, &p, nullptr);
	OutputPort p_out_3(&el_3, "p_out_3");
	p_in.setValue(false);
	assert(p_out_3.getValue() == false);
	p_in.setValue(true);
	assert(p_out_3.getValue() == true);

}

DECLARE_OOP_TEST(ELEMENT_AND_NO_INPUT_PORTS)
{
	BinaryElement el_1(AND, nullptr, nullptr);
	OutputPort p_out_1(&el_1, "p_out_1");
	assert(p_out_1.getValue() == false);

	InputPort p_in("p_in");
	InputPortElement p(p_in);

	BinaryElement el_2(AND, nullptr, &p);
	OutputPort p_out_2(&el_2, "p_out_2");
	p_in.setValue(false);
	assert(p_out_2.getValue() == false);
	p_in.setValue(true);
	assert(p_out_2.getValue() == false);

	BinaryElement el_3(AND, &p, nullptr);
	OutputPort p_out_3(&el_3, "p_out_3");
	p_in.setValue(false);
	assert(p_out_3.getValue() == false);
	p_in.setValue(true);
	assert(p_out_3.getValue() == false);

}

DECLARE_OOP_TEST(ELEMENT_XOR_NO_INPUT_PORTS)
{
	BinaryElement el_1(XOR, nullptr, nullptr);
	OutputPort p_out_1(&el_1, "p_out_1");
	assert(p_out_1.getValue() == false);

	InputPort p_in("p_in");
	InputPortElement p(p_in);

	BinaryElement el_2(XOR, nullptr, &p);
	OutputPort p_out_2(&el_2, "p_out_2");
	p_in.setValue(false);
	assert(p_out_2.getValue() == false);
	p_in.setValue(true);
	assert(p_out_2.getValue() == true);

	BinaryElement el_3(XOR, &p, nullptr);
	OutputPort p_out_3(&el_3, "p_out_3");
	p_in.setValue(false);
	assert(p_out_3.getValue() == false);
	p_in.setValue(true);
	assert(p_out_3.getValue() == true);

}

DECLARE_OOP_TEST(OUTPUT_PORT_NO_ELEMENT)
{
	OutputPort p(nullptr, "p");
	assert(p.getValue() == false);
}

DECLARE_OOP_TEST(SH1)
{
	InputPort p_in_1("p_in_1");
	InputPort p_in_2("p_in_2");
	InputPort p_in_3("p_in_3");

	InputPortElement p1(p_in_1);
	InputPortElement p2(p_in_2);
	InputPortElement p3(p_in_3);

	BinaryElement b_el_1(AND, &p1, &p2);
	UnaryElement u_el_1(NOT, &b_el_1);
	BinaryElement b_el_2(OR, &u_el_1, &p3);
	UnaryElement u_el_2(NOT, &u_el_1);
	
	OutputPort p_out_1(&u_el_2, "p_out_1");
	OutputPort p_out_2(&b_el_2, "p_out_2");

	p_in_1.setValue(false);
	p_in_2.setValue(false);
	p_in_3.setValue(false);
	assert(p_out_1.getValue() == 0);
	assert(p_out_2.getValue() == 1);

	p_in_1.setValue(false);
	p_in_2.setValue(false);
	p_in_3.setValue(true);
	assert(p_out_1.getValue() == 0);
	assert(p_out_2.getValue() == 1);

	p_in_1.setValue(false);
	p_in_2.setValue(true);
	p_in_3.setValue(false);
	assert(p_out_1.getValue() == 0);
	assert(p_out_2.getValue() == 1);

	p_in_1.setValue(false);
	p_in_2.setValue(true);
	p_in_3.setValue(true);
	assert(p_out_1.getValue() == 0);
	assert(p_out_2.getValue() == 1);

	p_in_1.setValue(true);
	p_in_2.setValue(false);
	p_in_3.setValue(false);
	assert(p_out_1.getValue() == 0);
	assert(p_out_2.getValue() == 1);

	p_in_1.setValue(true);
	p_in_2.setValue(false);
	p_in_3.setValue(true);
	assert(p_out_1.getValue() == 0);
	assert(p_out_2.getValue() == 1);

	p_in_1.setValue(true);
	p_in_2.setValue(true);
	p_in_3.setValue(false);
	assert(p_out_1.getValue() == 1);
	assert(p_out_2.getValue() == 0);

	p_in_1.setValue(true);
	p_in_2.setValue(true);
	p_in_3.setValue(true);
	assert(p_out_1.getValue() == 1);
	assert(p_out_2.getValue() == 1);

}

DECLARE_OOP_TEST(COMBINATION_CIRCUIT_MUX_4_TO_1)
{
	std::cout << std::endl << std::endl;

	CombinationCircuit *SH1 = new CombinationCircuit;

	InputPort *A0 = new InputPort("A0");
	InputPort *A1 = new InputPort("A1");
	InputPort *D0 = new InputPort("D0");
	InputPort *D1 = new InputPort("D1");
	InputPort *D2 = new InputPort("D2");
	InputPort *D3 = new InputPort("D3");

	SH1->AddPort(A0);
	SH1->AddPort(A1);
	SH1->AddPort(D0);
	SH1->AddPort(D1);
	SH1->AddPort(D2);
	SH1->AddPort(D3);

	InputPortElement *P_A0 = new InputPortElement(*A0);
	InputPortElement *P_A1 = new InputPortElement(*A1);
	InputPortElement *P_D0 = new InputPortElement(*D0);
	InputPortElement *P_D1 = new InputPortElement(*D1);
	InputPortElement *P_D2 = new InputPortElement(*D2);
	InputPortElement *P_D3 = new InputPortElement(*D3);
	UnaryElement *P_NOT_A0 = new UnaryElement(NOT, P_A0);
	UnaryElement *P_NOT_A1 = new UnaryElement(NOT, P_A1);

	SH1->AddElement(P_A0);
	SH1->AddElement(P_A1);
	SH1->AddElement(P_D0);
	SH1->AddElement(P_D1);
	SH1->AddElement(P_D2);
	SH1->AddElement(P_D3);
	SH1->AddElement(P_NOT_A0);
	SH1->AddElement(P_NOT_A1);

	/**********************************************************************************/

	BinaryElement *D1_1 = new BinaryElement(AND, P_NOT_A0, P_NOT_A1);
	BinaryElement *D1_2 = new BinaryElement(AND, D1_1, P_D0);
	BinaryElement *D2_1 = new BinaryElement(AND, P_NOT_A0, P_A1);
	BinaryElement *D2_2 = new BinaryElement(AND, D2_1, P_D1);
	BinaryElement *D3_1 = new BinaryElement(AND, P_A0, P_NOT_A1);
	BinaryElement *D3_2 = new BinaryElement(AND, D3_1, P_D2);
	BinaryElement *D4_1 = new BinaryElement(AND, P_A0, P_A1);
	BinaryElement *D4_2 = new BinaryElement(AND, D4_1, P_D3);
	BinaryElement *D5_1 = new BinaryElement(OR, D1_2, D2_2);
	BinaryElement *D5_2 = new BinaryElement(OR, D3_2, D4_2);
	BinaryElement *D6 = new BinaryElement(OR, D5_1, D5_2);

	SH1->AddElement(D1_1);
	SH1->AddElement(D1_2);
	SH1->AddElement(D2_1);
	SH1->AddElement(D2_2);
	SH1->AddElement(D3_1);
	SH1->AddElement(D3_2);
	SH1->AddElement(D4_1);
	SH1->AddElement(D4_2);
	SH1->AddElement(D5_1);
	SH1->AddElement(D5_2);
	SH1->AddElement(D6);

	OutputPort *Q = new OutputPort(D6, "Q");

	SH1->AddPort(Q);

	ReadFile(SH1, "C:\\Users\\Igor\\Documents\\Visual Studio 2015\\Projects\\oop_laba_4\\simulation.txt");

	delete SH1;
}

/*****************************************************************************/