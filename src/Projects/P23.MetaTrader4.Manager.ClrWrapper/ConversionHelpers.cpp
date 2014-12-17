#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"


#define COPY_STR(dst,src)  { strncpy_s(dst,src,sizeof(dst)-1); dst[sizeof(dst)-1]=0; }

ManagerConfiguration^ P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerConfiguration(ConManager* manager)
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

ConManager* P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerConfiguration(ManagerConfiguration^ manager)
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

ManagerSecurity^ P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerSecurity(ConManagerSec* security)
{
	P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ sec = gcnew P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity();
	sec->Enable = security->enable;
	sec->MaximumLots = security->maximum_lots;
	sec->MinimumLots = security->minimum_lots;
	return sec;
}

ConManagerSec* P23::MetaTrader4::Manager::ClrWrapper::ConvertManagerSecurity(ManagerSecurity^ security)
{
	ConManagerSec* sec = new ConManagerSec();
	sec->enable = security->Enable;
	sec->maximum_lots = security->MaximumLots;
	sec->minimum_lots = security->MinimumLots;
	return sec;
}

Common^ P23::MetaTrader4::Manager::ClrWrapper::ConvertCommonConfiguration(ConCommon* configuration)
{
	Common^ newConfiguration = gcnew Common();

	newConfiguration->Adapters = gcnew String(configuration->adapters);
	newConfiguration->Address = configuration->address;
	newConfiguration->AntiFlood = configuration->antiflood;
	for (int i = 0; i < 8; i++)
		newConfiguration->BindAdresses->Add(configuration->bind_adresses[i]);

	newConfiguration->DayLightCorrection = configuration->daylightcorrection;
	newConfiguration->EndHour = configuration->endhour;
	newConfiguration->EndMinute = configuration->endminute;
	newConfiguration->FeederTimeout = configuration->feeder_timeout;
	newConfiguration->FloodControl = configuration->floodcontrol;
	newConfiguration->KeepEmails = configuration->keepemails;
	newConfiguration->KeepTicks = configuration->keepticks;
	newConfiguration->LastLogin = configuration->lastlogin;
	newConfiguration->LastOrder = configuration->lastorder;
	newConfiguration->LiveUpdateMode = configuration->liveupdate_mode;
	newConfiguration->LostLogin = configuration->lostlogin;
	newConfiguration->MinClient = configuration->minclient;
	newConfiguration->MinApi = configuration->minapi;
	newConfiguration->MonthlyStateMode = configuration->monthly_state_mode;
	newConfiguration->Name = gcnew String(configuration->name);
	newConfiguration->OptimizationCounter = configuration->optimization_counter;
	newConfiguration->OptimizationLasttime = configuration->optimization_lasttime;
	newConfiguration->OptimizationTime = configuration->optimization_time;
	newConfiguration->OverMonthLastMonth = configuration->overmonth_last_month;
	newConfiguration->OverNightLastDay = configuration->overnight_last_day;
	newConfiguration->OverNightLastTime = configuration->overnight_last_time;
	newConfiguration->OverNightPrevTime = configuration->overnight_prev_time;
	newConfiguration->Owner = gcnew String(configuration->owner);
	newConfiguration->PathDatabase = gcnew String(configuration->path_database);
	newConfiguration->PathHistory = gcnew String(configuration->path_history);
	newConfiguration->PathLog = gcnew String(configuration->path_log);
	newConfiguration->Port = configuration->port;
	newConfiguration->RolloversMode = configuration->rollovers_mode;
	newConfiguration->ServerBuild = configuration->server_build;
	newConfiguration->ServerVersion = configuration->server_version;
	newConfiguration->StatementMode = configuration->statement_mode; 
	newConfiguration->StatementWeekend = configuration->statement_weekend;
	newConfiguration->TimeOfDemo = configuration->timeofdemo;
	newConfiguration->Timeout = configuration->timeout;
	newConfiguration->TimeSync = gcnew String(configuration->timesync);
	newConfiguration->TimeZone = configuration->timezone;
	newConfiguration->TypeOfDemo = configuration->typeofdemo;

	for (int i = 0; i < 8; i++)
		newConfiguration->WebAdresses->Add(configuration->web_adresses[i]);
			
	return newConfiguration;
}

ConCommon* P23::MetaTrader4::Manager::ClrWrapper::ConvertCommonConfiguration(Common^ configuration)
{
	ConCommon* newConfiguration = new ConCommon();
	
	char* adapters = ConvertStringToChar(configuration->Adapters);
	if (adapters != NULL)
		COPY_STR(newConfiguration->adapters, adapters);

	newConfiguration->address = configuration->Address;
	newConfiguration->antiflood = configuration->AntiFlood;

	if (configuration->BindAdresses->Count > 8)
		throw gcnew ArgumentException("BindAddresses count exceed 8");
	for (int i = 0; i < configuration->BindAdresses->Count; i++)
		newConfiguration->bind_adresses[i] = configuration->BindAdresses[i];

	newConfiguration->daylightcorrection = configuration->DayLightCorrection;
	newConfiguration->endhour = configuration->EndHour;
	newConfiguration->endminute = configuration->EndMinute;
	newConfiguration->feeder_timeout = configuration->FeederTimeout;
	newConfiguration->floodcontrol = configuration->FloodControl;
	newConfiguration->keepemails = configuration->KeepEmails;
	newConfiguration->keepticks = configuration->KeepTicks;
	newConfiguration->lastlogin = configuration->LastLogin;
	newConfiguration->lastorder = configuration->LastOrder;
	newConfiguration->liveupdate_mode = configuration->LiveUpdateMode;
	newConfiguration->lostlogin = configuration->LostLogin;
	newConfiguration->minclient = configuration->MinClient;
	newConfiguration->minapi = configuration->MinApi;
	newConfiguration->monthly_state_mode = configuration->MonthlyStateMode;

	char* name = ConvertStringToChar(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);
	
	newConfiguration->optimization_counter = configuration->OptimizationCounter;
	newConfiguration->optimization_lasttime = configuration->OptimizationLasttime;
	newConfiguration->optimization_time = configuration->OptimizationTime;
	newConfiguration->overmonth_last_month = configuration->OverMonthLastMonth;
	newConfiguration->overnight_last_day = configuration->OverNightLastDay;
	newConfiguration->overnight_last_time = configuration->OverNightLastTime;
	newConfiguration->overnight_prev_time = configuration->OverNightPrevTime;

	char* owner = ConvertStringToChar(configuration->Owner);
	if (owner != NULL)
		COPY_STR(newConfiguration->owner, owner);
	
	char* path_database = ConvertStringToChar(configuration->PathDatabase);
	if (path_database != NULL)
		COPY_STR(newConfiguration->path_database, path_database);
	
	char* path_history = ConvertStringToChar(configuration->PathHistory);
	if (path_history != NULL)
		COPY_STR(newConfiguration->path_history, path_history);
	
	char* path_log = ConvertStringToChar(configuration->PathLog);
	if (path_log != NULL)
		COPY_STR(newConfiguration->path_log, path_log);
	
	newConfiguration->port = configuration->Port;
	newConfiguration->rollovers_mode = configuration->RolloversMode;
	newConfiguration->server_build = configuration->ServerBuild;
	newConfiguration->server_version = configuration->ServerVersion;
	newConfiguration->statement_mode = configuration->StatementMode;
	newConfiguration->statement_weekend = configuration->StatementWeekend;
	newConfiguration->timeofdemo = configuration->TimeOfDemo;
	newConfiguration->timeout = configuration->Timeout;

	char* timesync = ConvertStringToChar(configuration->TimeSync);
	if (timesync != NULL)
		COPY_STR(newConfiguration->timesync, timesync);
	
	newConfiguration->timezone = configuration->TimeZone;
	newConfiguration->typeofdemo = configuration->TypeOfDemo;

	if (configuration->WebAdresses->Count > 8)
		throw gcnew ArgumentException("WebAdresses count exceed 8");
	for (int i = 0; i < configuration->WebAdresses->Count; i++)
		newConfiguration->web_adresses[i] = configuration->WebAdresses[i];
	
	return newConfiguration;
}

Time^ P23::MetaTrader4::Manager::ClrWrapper::ConvertTimeConfiguration(ConTime* configuration)
{
	Time^ newConfiguration = gcnew Time();
	newConfiguration->Days = gcnew System::Collections::Generic::List<System::Collections::Generic::IList<int>^>();
	for (int day = 0; day < 7; day++){
		System::Collections::Generic::IList<int>^ dayValues = gcnew System::Collections::Generic::List<int>();
		for (int hour = 0; hour < 24; hour++)
			dayValues->Add(configuration->days[day][hour]);
		newConfiguration->Days->Add(dayValues);
	}
	
	return newConfiguration;
}

ConTime* P23::MetaTrader4::Manager::ClrWrapper::ConvertTimeConfiguration(Time^ configuration)
{
	ConTime* newConfiguration = new ConTime();
	if (configuration->Days->Count != 7)
		throw gcnew ArgumentException("Invalid number of days");
	for (int day = 0; day < 7; day++){
		if (configuration->Days[day]->Count != 24)
			throw gcnew ArgumentException("Invalid number of hours");
		for (int hour = 0; hour < 24; hour++)
		{
			System::Collections::Generic::IList<int>^ intraDayValues = configuration->Days[day];
			newConfiguration->days[day][hour] = intraDayValues[hour];
		}		
	}
	return newConfiguration;
}