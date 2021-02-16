#include "ncbind/ncbind.hpp"

struct System
{
	static tTVInteger createAppLock(ttstr lockname)
	{
		// lock application using mutex
		HANDLE mutex = CreateMutex(NULL, TRUE, lockname.c_str());

		if (GetLastError() == ERROR_ALREADY_EXISTS && mutex != NULL)
		{
			ReleaseMutex(mutex);
			return 0; // already running
		}
		return (tTVInteger)mutex;
	}

	static bool releaseAppLock(tTVInteger lock)
	{
		if (lock == 0)
		{
			return false;
		}
		return !!ReleaseMutex((HANDLE)lock);
	}
};

NCB_ATTACH_FUNCTION(createAppLock, System, System::createAppLock);
NCB_ATTACH_FUNCTION(releaseAppLock, System, System::releaseAppLock);
