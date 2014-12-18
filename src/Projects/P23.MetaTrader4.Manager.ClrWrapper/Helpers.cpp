#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

char* P23::MetaTrader4::Manager::ClrWrapper::Convert(System::String^ inputString)
{
	return (char*)Marshal::StringToHGlobalAnsi(inputString).ToPointer();
}