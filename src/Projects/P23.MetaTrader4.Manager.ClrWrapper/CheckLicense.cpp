#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::LicenseCheck(System::String^ licenseName)
{
	if (System::String::IsNullOrEmpty(licenseName))
		throw gcnew ArgumentNullException("licenseName");
	
	return _manager->Manager->LicenseCheck(Convert(licenseName));
}