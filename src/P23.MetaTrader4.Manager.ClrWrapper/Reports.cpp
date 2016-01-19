#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::ReportsRequest(P23::MetaTrader4::Manager::Contracts::ReportGroupRequest^ request, IList<int>^ logins)
{
	if (request == nullptr)
		throw gcnew ArgumentNullException("request");

	if (logins == nullptr)
		throw gcnew ArgumentNullException("logins");

	if (logins->Count == 0)
		throw gcnew ArgumentException("At least one login should be provided", "logins");

	int total = 0;
	ReportGroupRequest* convertedRequest = Convert(request);
	convertedRequest->total = logins->Count;

	TradeRecord* records = _manager->Manager->ReportsRequest(convertedRequest, Convert(logins), &total);
	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&records[i]));

	_manager->Manager->MemFree(records);

	return result;
}

IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ P23::MetaTrader4::Manager::ClrWrapper::DailyReportsRequest(P23::MetaTrader4::Manager::Contracts::DailyGroupRequest^ request, IList<int>^ logins)
{
	if (request == nullptr)
		throw gcnew ArgumentNullException("request");

	if (logins == nullptr)
		throw gcnew ArgumentNullException("logins");

	if (logins->Count == 0)
		throw gcnew ArgumentException("At least one login should be provided", "logins");

	if (request->To - request->From < (unsigned int)NumberOfSecondsInDay)
		throw gcnew ArgumentException("Minimum difference between To and From should be 24 hours", "request");

	int total = 0;
	DailyGroupRequest* convertedRequest = Convert(request);
	convertedRequest->total = logins->Count;

	DailyReport* records = _manager->Manager->DailyReportsRequest(convertedRequest, Convert(logins), &total);
	IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::DailyReport^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&records[i]));

	_manager->Manager->MemFree(records);

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
	if (plugin == nullptr)
		throw gcnew ArgumentNullException("plugin");

	return _manager->Manager->PluginUpdate(Convert(plugin));
}
