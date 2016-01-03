#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::ServerFeed^>^ P23::MetaTrader4::Manager::ClrWrapper::SrvFeeders()
{
	int total = 0;
	ServerFeed* feeders = _manager->Manager->SrvFeeders(&total);
	IList<P23::MetaTrader4::Manager::Contracts::ServerFeed^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::ServerFeed^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&feeders[i]));

	_manager->Manager->MemFree(feeders);

	return result;
}

String^ P23::MetaTrader4::Manager::ClrWrapper::SrvFeederLog(String^ name)
{
	char* n = Convert(name);
	int total = 0;
	LPCSTR result = _manager->Manager->SrvFeederLog(n, &total);
	return gcnew String(result);
}