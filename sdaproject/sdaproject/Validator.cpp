#include "Validator.h"

void valid(Plate & s)
{
	if (s.getNumber() < 10 || s.getNumber() > 99)
		throw Exception("Invalid number");
	
	if (s.getJud()[0]<'A' || s.getJud()[1]<'A' || s.getJud()[0]>'Z' || s.getJud()[1]>'Z')
		throw Exception("Invalid county");
	
	
	if (s.getRand()[0]<'A' || s.getRand()[0]>'Z' || s.getRand()[1]<'A' || s.getRand()[1]>'Z' || s.getRand()[2]<'A' || s.getRand()[2]>'Z')
		throw Exception("Invalid random chars");
}
