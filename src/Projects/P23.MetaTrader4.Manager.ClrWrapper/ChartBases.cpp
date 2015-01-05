#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::ChartRequest(P23::MetaTrader4::Manager::Contracts::ChartInfo^ chart, UInt32 timesign)
{
	throw gcnew NotImplementedException();
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartAdd(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	throw gcnew NotImplementedException();
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartUpdate(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	throw gcnew NotImplementedException();
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartDelete(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	throw gcnew NotImplementedException();
}

IList<P23::MetaTrader4::Manager::Contracts::TickRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TicksRequest(P23::MetaTrader4::Manager::Contracts::TickRequest^ request)
{
	throw gcnew NotImplementedException();
}
