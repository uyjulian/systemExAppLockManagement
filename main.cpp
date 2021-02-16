#include "ncbind/ncbind.hpp"

struct System
{
	static void setArgument(ttstr name, ttstr value)
	{
		TVPSetCommandLine(name.c_str(), value);
	}
};

NCB_ATTACH_FUNCTION(setArgument, System, System::setArgument);
