#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

char* P23::MetaTrader4::Manager::ClrWrapper::ConvertStringToChar(System::String^ inputString)
{
	return (char*)Marshal::StringToHGlobalAnsi(inputString).ToPointer();
}