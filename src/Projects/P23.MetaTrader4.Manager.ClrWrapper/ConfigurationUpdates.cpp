
#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateCommon(Common^ configuration)
{
	return _manager->Manager->CfgUpdateCommon(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateAccess(Access^ configuration, int position)
{ 
	return _manager->Manager->CfgUpdateAccess(Convert(configuration), position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateDataServer(DataServer^ configuration, int position)
{
	return _manager->Manager->CfgUpdateDataServer(Convert(configuration), position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateTime(Time^ configuration)
{
	return _manager->Manager->CfgUpdateTime(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateHoliday(Holiday^ configuration, int position)
{ 
	return _manager->Manager->CfgUpdateHoliday(Convert(configuration), position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateSymbol(Symbol^ configuration)
{
	return _manager->Manager->CfgUpdateSymbol(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateSymbolGroup(SymbolGroup^ configuration, int position)
{
	return _manager->Manager->CfgUpdateSymbolGroup(Convert(configuration), position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGroup(Group^ configuration)
{
	return _manager->Manager->CfgUpdateGroup(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateManager(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ configuration)
{
	return _manager->Manager->CfgUpdateManager(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateFeeder(Feeder^ configuration)
{
	return _manager->Manager->CfgUpdateFeeder(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateBackup(Backup^ configuration)
{
	return _manager->Manager->CfgUpdateBackup(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateLiveUpdate(LiveUpdate^ configuration)
{
	return _manager->Manager->CfgUpdateLiveUpdate(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateSync(Synchronization^ configuration)
{
	return _manager->Manager->CfgUpdateSync(Convert(configuration));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdatePlugin(Plugin^ configuration, IList<PluginConfigurationParameter^>^ parameters)
{
	PluginCfg* params = new PluginCfg[parameters->Count];

	for (int i = 0; i < parameters->Count; i++)
		params[i] = *Convert(parameters[i]);

	return _manager->Manager->CfgUpdatePlugin(Convert(configuration), params, parameters->Count);
}