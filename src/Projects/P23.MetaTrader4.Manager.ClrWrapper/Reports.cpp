#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::ReportsRequest(P23::MetaTrader4::Manager::Contracts::ReportGroupRequest^ request, IList<int>^ logins)
{
	int total = logins->Count;
	TradeRecord* records = _manager->Manager->ReportsRequest(Convert(request), Convert(logins), &total);
	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&records[i]));
	return result;
}

IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ P23::MetaTrader4::Manager::ClrWrapper::DailyReportsRequest(P23::MetaTrader4::Manager::Contracts::DailyGroupRequest^ request, IList<int>^ logins)
{
	int total = logins->Count;
	DailyReport* records = _manager->Manager->DailyReportsRequest(Convert(request), Convert(logins), &total);
	IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::DailyReport^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&records[i]));
	return result;
}

//--- external command
int P23::MetaTrader4::Manager::ClrWrapper::ExternalCommand(String^ dataIn, int sizeIn, String^ dataOut, int sizeOut)
{
	throw gcnew NotImplementedException();
	//return _manager->Manager->ExternalCommand(Convert(dataIn), sizeIn,, Convert(dataOut), sizeOut);
}

//--- plugins
int P23::MetaTrader4::Manager::ClrWrapper::PluginUpdate(PluginWithParameters^ plugin)
{
	return _manager->Manager->PluginUpdate(Convert(plugin));
}
