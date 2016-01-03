#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

char* P23::MetaTrader4::Manager::ClrWrapper::Convert(System::String^ inputString)
{
	return (char*)Marshal::StringToHGlobalAnsi(inputString).ToPointer();
}

int* P23::MetaTrader4::Manager::ClrWrapper::Convert(IList<int>^ input)
{
	int* output = new int[input->Count];
	for (int i = 0; i < input->Count; i++)
		output[i] = input[i];
	return output;
}