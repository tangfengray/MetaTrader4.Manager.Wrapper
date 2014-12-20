
#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

Common^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestCommon()
{
	ConCommon configuration;
	int result = _manager->Manager->CfgRequestCommon(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}

Time^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestTime()
{
	ConTime configuration;
	int result = _manager->Manager->CfgRequestTime(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}

Backup^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestBackup()
{
	ConBackup configuration;
	int result = _manager->Manager->CfgRequestBackup(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}
SymbolGroup^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestSymbolGroup()
{
	ConSymbolGroup configuration;
	int result = _manager->Manager->CfgRequestSymbolGroup(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}

IList<Access^>^      P23::MetaTrader4::Manager::ClrWrapper::CfgRequestAccess()
{
	IList<Access^>^ configurations = gcnew List<Access^>();
	int total = 0;
	ConAccess* result = _manager->Manager->CfgRequestAccess(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<DataServer^>^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestDataServer()
{
	IList<DataServer^>^ configurations = gcnew List<DataServer^>();
	int total = 0;
	ConDataServer* result = _manager->Manager->CfgRequestDataServer(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<Holiday^>^     P23::MetaTrader4::Manager::ClrWrapper::CfgRequestHoliday()
{
	IList<Holiday^>^ configurations = gcnew List<Holiday^>();
	int total = 0;
	ConHoliday* result = _manager->Manager->CfgRequestHoliday(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<Symbol^>^      P23::MetaTrader4::Manager::ClrWrapper::CfgRequestSymbol()
{
	IList<Symbol^>^ configurations = gcnew List<Symbol^>();
	int total = 0;
	ConSymbol* result = _manager->Manager->CfgRequestSymbol(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<Group^>^       P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGroup()
{
	IList<Group^>^ configurations = gcnew List<Group^>();
	int total = 0;
	ConGroup* result = _manager->Manager->CfgRequestGroup(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>^     P23::MetaTrader4::Manager::ClrWrapper::CfgRequestManager()
{
	IList<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>^ configurations = gcnew List<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>();
	int total = 0;
	ConManager* result = _manager->Manager->CfgRequestManager(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<Feeder^>^      P23::MetaTrader4::Manager::ClrWrapper::CfgRequestFeeder()
{
	IList<Feeder^>^ configurations = gcnew List<Feeder^>();
	int total = 0;
	ConFeeder* result = _manager->Manager->CfgRequestFeeder(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<LiveUpdate^>^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestLiveUpdate()
{
	IList<LiveUpdate^>^ configurations = gcnew List<LiveUpdate^>();
	int total = 0;
	ConLiveUpdate* result = _manager->Manager->CfgRequestLiveUpdate(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<Synchronization^>^        P23::MetaTrader4::Manager::ClrWrapper::CfgRequestSync()
{
	IList<Synchronization^>^ configurations = gcnew List<Synchronization^>();
	int total = 0;
	ConSync* result = _manager->Manager->CfgRequestSync(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}

IList<PluginWithParameters^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestPlugin()
{
	IList<PluginWithParameters^>^ configurations = gcnew List<PluginWithParameters^>();
	int total = 0;
	ConPluginParam* result = _manager->Manager->CfgRequestPlugin(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	return configurations;
}