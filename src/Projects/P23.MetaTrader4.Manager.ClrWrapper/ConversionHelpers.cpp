#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"


#define COPY_STR(dst,src)  { strncpy_s(dst,src,sizeof(dst)-1); dst[sizeof(dst)-1]=0; }

P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration^ P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerConfiguration(ConManager* manager)
{
	P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration^ tManager = gcnew P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration();
	tManager->Admin = manager->admin;
	tManager->Broker = manager->broker;
	tManager->Email = manager->email;
	tManager->Groups = gcnew System::String(manager->groups);
	tManager->InfoDepth = manager->info_depth;
	tManager->IpFilter = manager->ipfilter;
	tManager->IpFrom = manager->ip_from;
	tManager->IpTo = manager->ip_to;
	tManager->Login = manager->login;
	tManager->Logs = manager->logs;
	tManager->Mailbox = gcnew System::String(manager->mailbox);
	tManager->Manager = manager->manager;
	tManager->MarketWatch = manager->market_watch;
	tManager->Money = manager->money;
	tManager->Name = gcnew System::String(manager->name);
	tManager->News = manager->news;
	tManager->Online = manager->online;
	tManager->Plugins = manager->plugins;
	tManager->Reports = manager->reports;
	tManager->Riskman = manager->riskman;

	tManager->SecGroups = gcnew System::Collections::Generic::List<P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^>();
	for (int i = 0; i < MAX_SEC_GROUPS; i++){
		tManager->SecGroups->Add(ConvertManagerSecurity(&manager->secgroups[i]));
	}
	
	tManager->SeeTrades = manager->see_trades;
	tManager->ServerReports = manager->server_reports;
	tManager->Trades = manager->trades;
	tManager->UserDetails = manager->user_details;
	return tManager;
}

ConManager* P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerConfiguration(P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration^ manager)
{
	ConManager* tManager = new ConManager();

	tManager->admin = manager->Admin;
	tManager->broker = manager->Broker;
	tManager->email = manager->Email;

	char* groups = ConvertStringToChar(manager->Groups);
	if (groups != NULL)
		COPY_STR(tManager->groups, groups);
	
	tManager->info_depth = manager->InfoDepth;
	tManager->ipfilter = manager->IpFilter;
	tManager->ip_from = (unsigned long)manager->IpFrom;
	tManager->ip_to = (unsigned long)manager->IpTo;
	tManager->login = manager->Login;
	tManager->logs = manager->Logs;

	char* mailbox = ConvertStringToChar(manager->Mailbox);
	if (mailbox != NULL)
		COPY_STR(tManager->mailbox, mailbox);
	
	tManager->manager = manager->Manager;
	tManager->market_watch = manager->MarketWatch;
	tManager->money = manager->Money;

	char* name = ConvertStringToChar(manager->Name);
	if (name != NULL)
		COPY_STR(tManager->name, name);
	
	tManager->news = manager->News;
	tManager->online = manager->Online;
	tManager->plugins = manager->Plugins;
	tManager->reports = manager->Reports;
	tManager->riskman = manager->Riskman;
	if (manager->SecGroups->Count != MAX_SEC_GROUPS)
		throw gcnew ArgumentException("Invalid number of securities");
		
	for (int i = 0; i < MAX_SEC_GROUPS; i++){
		tManager->secgroups[i] = *ConvertManagerSecurity(manager->SecGroups[i]);
	}

	tManager->see_trades = manager->SeeTrades;
	tManager->server_reports = manager->ServerReports;
	tManager->trades = manager->Trades;
	tManager->user_details = manager->UserDetails;
	return tManager;

	throw gcnew NotImplementedException();
}

P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerSecurity(ConManagerSec* security)
{
	P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ sec = gcnew P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity();
	sec->Enable = security->enable;
	sec->MaximumLots = security->maximum_lots;
	sec->MinimumLots = security->minimum_lots;
	return sec;
}

ConManagerSec* P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerSecurity(P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ security)
{
	ConManagerSec* sec = new ConManagerSec();
	sec->enable = security->Enable;
	sec->maximum_lots = security->MaximumLots;
	sec->minimum_lots = security->MinimumLots;
	return sec;
}