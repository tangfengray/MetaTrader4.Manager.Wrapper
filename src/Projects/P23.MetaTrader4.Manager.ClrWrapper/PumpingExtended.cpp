#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::PumpingSwitchEx()
{
	if (_callBackHandler.IsAllocated)
		throw gcnew MetaTrader4::Manager::Contracts::MetaTraderException("Callback handler alread allocated");
	
	_extendedPumpingCallBack = gcnew ExtendedCallBackDelegate(this, &ClrWrapper::ExtendedPumpingNotify);
	_callBackHandler = GCHandle::Alloc(_extendedPumpingCallBack);
	
	return _manager->Manager->PumpingSwitchEx((MTAPI_NOTIFY_FUNC_EX)Marshal::GetFunctionPointerForDelegate(_extendedPumpingCallBack).ToPointer(), 0, NULL);
}

void P23::MetaTrader4::Manager::ClrWrapper::ExtendedPumpingNotify(int code, int type, void *data, void *param)
{
	if (code != 15)
		System::Console::WriteLine(code);
	switch (code)
	{
		case PUMP_START_PUMPING:
			PumpingStarted(this, nullptr);
			break;
		case PUMP_STOP_PUMPING:
			PumpingStopped(this, nullptr);
			break;
		case PUMP_UPDATE_BIDASK:
			BidAskUpdated(this, nullptr);
			break;
		case PUMP_UPDATE_SYMBOLS:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_GROUPS:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_USERS:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_ONLINE:
			if (data != NULL)
			{
				OnlineRecord *online = (OnlineRecord*)data;
				P23::MetaTrader4::Manager::Contracts::OnlineRecord^ onlineRecord = P23::MetaTrader4::Manager::ClrWrapper::Convert(online);
				OnlineUpdated(this, onlineRecord);
			}
			break;
		case PUMP_UPDATE_TRADES:
			if (data != NULL)
			{
				TradeRecord *trade = (TradeRecord*)data;
				P23::MetaTrader4::Manager::Contracts::TradeRecord^ tradeRecordStruct = P23::MetaTrader4::Manager::ClrWrapper::Convert(trade);

				switch (type)
				{
					case TRANS_ADD:
						TradeAdded(this, tradeRecordStruct);
						break;
					case TRANS_DELETE:
						TradeClosed(this, tradeRecordStruct);
						break;
					case TRANS_UPDATE:
						if (trade->login == 0) 
							TradeDeleted(this, tradeRecordStruct);
						else
							TradeUpdated(this, tradeRecordStruct);
						break;
				}
			}
			break;
		case PUMP_UPDATE_ACTIVATION:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_MARGINCALL:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_REQUESTS:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_PLUGINS:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_NEWS:
			//Needs to be implemented
			break;
		case PUMP_UPDATE_MAIL:
			//Needs to be implemented
			break;
		default: 
			break;
	}
}

int P23::MetaTrader4::Manager::ClrWrapper::UsersSyncStart(UInt32 timestamp)
{
	return _manager->Manager->UsersSyncStart(timestamp);
}

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::UsersSyncRead()
{
	int total = 0;
	UserRecord* result = _manager->Manager->UsersSyncRead(&total);

	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

IList<int>^ P23::MetaTrader4::Manager::ClrWrapper::UsersSnapshot()
{
	int total = 0;
	int* result = _manager->Manager->UsersSnapshot(&total);

	IList<int>^ output = gcnew List<int>();
	for (int i = 0; i < total; i++)
		output->Add(result[i]);
	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::TradesSyncStart(UInt32 timestamp)
{
	return _manager->Manager->TradesSyncStart(timestamp);
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradesSyncRead()
{
	int total = 0;
	TradeRecord* result = _manager->Manager->TradesSyncRead(&total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

IList<int>^ P23::MetaTrader4::Manager::ClrWrapper::TradesSnapshot()
{
	int total = 0;
	int* result = _manager->Manager->TradesSnapshot(&total);

	IList<int>^ output = gcnew List<int>();
	for (int i = 0; i < total; i++)
		output->Add(result[i]);
	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::DailySyncStart(UInt32 timestamp)
{
	return _manager->Manager->DailySyncStart(timestamp);
}

IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ P23::MetaTrader4::Manager::ClrWrapper::DailySyncRead()
{
	int total = 0;
	DailyReport* result = _manager->Manager->DailySyncRead(&total);

	IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::DailyReport^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}