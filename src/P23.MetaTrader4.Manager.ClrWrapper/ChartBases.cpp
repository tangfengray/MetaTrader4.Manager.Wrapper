#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::ChartRequest(P23::MetaTrader4::Manager::Contracts::ChartInfo^ chart, UInt32 timesign)
{
	int total = 0;
	__time32_t time = (__time32_t)timesign;
	RateInfo* result = _manager->Manager->ChartRequest(Convert(chart), &time, &total);
	IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::RateInfo^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return output;	
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartAdd(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	int total = rates->Count;
	RateInfo* unmanagedRates = new RateInfo[total];
	for (int i = 0; i < total; i++)
		unmanagedRates[i] = *Convert(rates[i]);
	return _manager->Manager->ChartAdd(Convert(symbol), period, unmanagedRates, &total);
	
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartUpdate(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	int total = rates->Count;
	RateInfo* unmanagedRates = new RateInfo[total];
	for (int i = 0; i < total; i++)
		unmanagedRates[i] = *Convert(rates[i]);
	return _manager->Manager->ChartUpdate(Convert(symbol), period, unmanagedRates, &total);
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartDelete(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	int total = rates->Count;
	RateInfo* unmanagedRates = new RateInfo[total];
	for (int i = 0; i < total; i++)
		unmanagedRates[i] = *Convert(rates[i]);
	return _manager->Manager->ChartDelete(Convert(symbol), period, unmanagedRates, &total);
}

IList<P23::MetaTrader4::Manager::Contracts::TickRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TicksRequest(P23::MetaTrader4::Manager::Contracts::TickRequest^ request)
{
	int total = 0;	
	TickRecord* result = _manager->Manager->TicksRequest(Convert(request), &total);
	IList<P23::MetaTrader4::Manager::Contracts::TickRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TickRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}
