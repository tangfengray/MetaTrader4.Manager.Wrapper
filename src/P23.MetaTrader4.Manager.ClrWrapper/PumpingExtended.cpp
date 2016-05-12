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
			if (data != NULL)
			{
				ConSymbol *conSymbol = (ConSymbol*)data;
				P23::MetaTrader4::Manager::Contracts::Configuration::Symbol^ symbolConfiguration = P23::MetaTrader4::Manager::ClrWrapper::Convert(conSymbol);
				SymbolUpdated(this, symbolConfiguration);
			}
			break;
		case PUMP_UPDATE_GROUPS:
			if (data != NULL)
			{
				ConGroup *conGroup = (ConGroup*)data;
				P23::MetaTrader4::Manager::Contracts::Configuration::Group^ groupConfiguration = P23::MetaTrader4::Manager::ClrWrapper::Convert(conGroup);
				GroupUpdated(this, groupConfiguration);
			}
			break;
		case PUMP_UPDATE_USERS:
			if (data != NULL)
			{
				UserRecord *user = (UserRecord*)data;
				P23::MetaTrader4::Manager::Contracts::UserRecord^ userRecord = P23::MetaTrader4::Manager::ClrWrapper::Convert(user);
				UserUpdated(this, userRecord);
			}
			break;
		case PUMP_UPDATE_ONLINE:
			if (data != NULL)
			{
				int onlineLogin = (int)data;
				OnlineUpdated(this, onlineLogin);
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
		case PUMP_UPDATE_REQUESTS:
			if (data != NULL)
			{
				RequestInfo *requestInfo = (RequestInfo*)data;
				P23::MetaTrader4::Manager::Contracts::RequestInfo^ ri = P23::MetaTrader4::Manager::ClrWrapper::Convert(requestInfo);
				RequestInfoUpdated(this, ri);
			}
			break;
		case PUMP_UPDATE_NEWS:
			if (data != NULL)
			{
				NewsTopic *newsTopic = (NewsTopic *)data;
				P23::MetaTrader4::Manager::Contracts::NewsTopic^ nt = P23::MetaTrader4::Manager::ClrWrapper::Convert(newsTopic);
				NewsTopicUpdated(this, nt);
			}
			break;
		case PUMP_UPDATE_NEWS_NEW:
			if (data != NULL)
			{
				NewsTopicNew *newsTopic = (NewsTopicNew*)data;
				P23::MetaTrader4::Manager::Contracts::NewsTopicNew^ nt = P23::MetaTrader4::Manager::ClrWrapper::Convert(newsTopic);
				NewNewsTopicUpdated(this, nt);
			}
			break;
		case PUMP_UPDATE_MAIL:
			if (data != NULL)
			{
				MailBox *mailBox = (MailBox*)data;
				P23::MetaTrader4::Manager::Contracts::MailBox^ mb = P23::MetaTrader4::Manager::ClrWrapper::Convert(mailBox);
				MailBoxUpdated(this, mb);
			}
			break;
		case PUMP_UPDATE_ACTIVATION:
			ActivationUpdated(this, nullptr);
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

	_manager->Manager->MemFree(result);

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

	_manager->Manager->MemFree(result);

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

	_manager->Manager->MemFree(result);

	return output;
}