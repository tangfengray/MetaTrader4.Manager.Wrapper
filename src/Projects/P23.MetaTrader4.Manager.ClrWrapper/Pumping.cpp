#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::PumpingSwitch(PumpingCallbackDelegate^ callBackDelegate)
{	
	if (_callBackHandler.IsAllocated)
		_callBackHandler.Free();

	_callBackHandler = GCHandle::Alloc(_callBackDelegate);
	return _manager->Manager->PumpingSwitchEx((MTAPI_NOTIFY_FUNC_EX)Marshal::GetFunctionPointerForDelegate(callBackDelegate).ToPointer(), 0, NULL);
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>^ P23::MetaTrader4::Manager::ClrWrapper::GroupsGet()
{
	int total = 0;
	ConGroup* groups = _manager->Manager->GroupsGet(&total);
	IList<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&groups[i]));
	return output;
}

P23::MetaTrader4::Manager::Contracts::Configuration::Group^ P23::MetaTrader4::Manager::ClrWrapper::GroupRecordGet(String^ name)
{
	ConGroup group;
	int result = _manager->Manager->GroupRecordGet(Convert(name), &group);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}
	return Convert(&group);
}

IList<P23::MetaTrader4::Manager::Contracts::SymbolInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::SymbolInfoUpdated()
{
	const int max = 32;
	SymbolInfo si[max];
	int total = _manager->Manager->SymbolInfoUpdated(si, max);
	
	IList<P23::MetaTrader4::Manager::Contracts::SymbolInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::SymbolInfo^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&si[i]));
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::UsersGet()
{
	int total = 0;
	UserRecord* result = _manager->Manager->UsersGet(&total);
	
	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

P23::MetaTrader4::Manager::Contracts::UserRecord^ P23::MetaTrader4::Manager::ClrWrapper::UserRecordGet(int login)
{
	UserRecord user;
	int result = _manager->Manager->UserRecordGet(login, &user);
	
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&user);
}

IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::OnlineGet()
{
	int total = 0;
	OnlineRecord* result = _manager->Manager->OnlineGet(&total);

	IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

P23::MetaTrader4::Manager::Contracts::OnlineRecord^ P23::MetaTrader4::Manager::ClrWrapper::OnlineRecordGet(int login)
{
	OnlineRecord user;
	int result = _manager->Manager->OnlineRecordGet(login, &user);

	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&user);
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradesGet()
{
	int total = 0;
	TradeRecord* result = _manager->Manager->TradesGet(&total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradesGetBySymbol(String^ symbol)
{
	int total = 0;
	TradeRecord* result = _manager->Manager->TradesGetBySymbol(Convert(symbol), &total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradesGetByLogin(int login, String^ group)
{
	int total = 0;
	TradeRecord* result = _manager->Manager->TradesGetByLogin(login, Convert(group), &total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradesGetByMarket()
{
	int total = 0;
	TradeRecord* result = _manager->Manager->TradesGetByMarket(&total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

P23::MetaTrader4::Manager::Contracts::TradeRecord^ P23::MetaTrader4::Manager::ClrWrapper::TradeRecordGet(int order)
{
	TradeRecord tradeRecord;
	int result = _manager->Manager->TradeRecordGet(order, &tradeRecord);

	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&tradeRecord);
}

int P23::MetaTrader4::Manager::ClrWrapper::TradeClearRollback(int order)
{
	return _manager->Manager->TradeClearRollback(order);
}

IList<P23::MetaTrader4::Manager::Contracts::MarginLevel^>^ P23::MetaTrader4::Manager::ClrWrapper::MarginsGet()
{
	int total = 0;
	MarginLevel* result = _manager->Manager->MarginsGet(&total);

	IList<P23::MetaTrader4::Manager::Contracts::MarginLevel^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::MarginLevel^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

P23::MetaTrader4::Manager::Contracts::MarginLevel^ P23::MetaTrader4::Manager::ClrWrapper::MarginLevelGet(int login, String^ group)
{
	MarginLevel level;
	int result = _manager->Manager->MarginLevelGet(login, Convert(group), &level);

	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&level);
}

IList<P23::MetaTrader4::Manager::Contracts::RequestInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::RequestsGet()
{
	int total = 0;
	RequestInfo* result = _manager->Manager->RequestsGet(&total);

	IList<P23::MetaTrader4::Manager::Contracts::RequestInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::RequestInfo^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

P23::MetaTrader4::Manager::Contracts::RequestInfo^ P23::MetaTrader4::Manager::ClrWrapper::RequestInfoGet(int position)
{
	RequestInfo ri;
	int result = _manager->Manager->RequestInfoGet(position, &ri);

	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&ri);
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::Plugin^>^ P23::MetaTrader4::Manager::ClrWrapper::PluginsGet()
{
	int total = 0;
	ConPlugin* result = _manager->Manager->PluginsGet(&total);

	IList<P23::MetaTrader4::Manager::Contracts::Configuration::Plugin^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::Configuration::Plugin^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

P23::MetaTrader4::Manager::Contracts::Configuration::PluginWithParameters^ P23::MetaTrader4::Manager::ClrWrapper::PluginParamGet(int position)
{
	ConPluginParam p;
	int result = _manager->Manager->PluginParamGet(position, &p);

	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&p);
}

int P23::MetaTrader4::Manager::ClrWrapper::MailLast(String^ path, int length)
{
	return _manager->Manager->MailLast(Convert(path), &length);
}

IList<P23::MetaTrader4::Manager::Contracts::NewsTopic^>^ P23::MetaTrader4::Manager::ClrWrapper::NewsGet()
{
	int total = 0;
	NewsTopic* result = _manager->Manager->NewsGet(&total);

	IList<P23::MetaTrader4::Manager::Contracts::NewsTopic^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::NewsTopic^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));
	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::NewsTotal()
{
	return _manager->Manager->NewsTotal();
}

P23::MetaTrader4::Manager::Contracts::NewsTopic^ P23::MetaTrader4::Manager::ClrWrapper::NewsTopicGet(int position)
{
	NewsTopic n;
	int result = _manager->Manager->NewsTopicGet(position, &n);

	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&n);
}

void P23::MetaTrader4::Manager::ClrWrapper::NewsBodyRequest(int key)
{
	_manager->Manager->NewsBodyRequest(key);
}

String^ P23::MetaTrader4::Manager::ClrWrapper::NewsBodyGet(int key)
{
	return gcnew String(_manager->Manager->NewsBodyGet(key));
}
