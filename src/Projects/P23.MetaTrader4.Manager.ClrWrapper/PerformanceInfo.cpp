#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::PerformanceInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::PerformaneRequest(UInt32 from)
{
	int total = 0;
	PerformanceInfo* infos = _manager->Manager->PerformaneRequest(from, &total);
	IList<P23::MetaTrader4::Manager::Contracts::PerformanceInfo^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::PerformanceInfo^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&infos[i]));
	return result;
}
