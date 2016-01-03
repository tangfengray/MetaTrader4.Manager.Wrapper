#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

char* P23::MetaTrader4::Manager::ClrWrapper::Convert(System::String^ inputString)
{
	return (char*)Marshal::StringToHGlobalAnsi(inputString).ToPointer();
}

const wchar_t* P23::MetaTrader4::Manager::ClrWrapper::ConvertToLPCWSTR(System::String^ inputString)
{
	//pin_ptr<const wchar_t> convertedValue = PtrToStringChars(metaquotesIds);  // <-- #include <vcclr.h>
	//const wchar_t *constValue = convertedValue;                     // <-- Unnecessary, but to be completely verbose
	return (const wchar_t*)Marshal::StringToHGlobalAnsi(inputString).ToPointer();
}

wchar_t* P23::MetaTrader4::Manager::ClrWrapper::ConvertToLPWSTR(System::String^ inputString)
{
	return (wchar_t*)Marshal::StringToHGlobalAnsi(inputString).ToPointer();
}

int* P23::MetaTrader4::Manager::ClrWrapper::Convert(IList<int>^ input)
{
	int* output = new int[input->Count];
	for (int i = 0; i < input->Count; i++)
		output[i] = input[i];
	return output;
}