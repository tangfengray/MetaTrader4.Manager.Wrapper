#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"


#define COPY_STR(dst,src)  { strncpy_s(dst,src,sizeof(dst)-1); dst[sizeof(dst)-1]=0; }

ManagerConfiguration^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConManager* configuration)
{
	P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration^ tManager = gcnew P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration();
	tManager->Admin = configuration->admin;
	tManager->Broker = configuration->broker;
	tManager->Email = configuration->email;
	tManager->Groups = gcnew System::String(configuration->groups);
	tManager->InfoDepth = configuration->info_depth;
	tManager->IpFilter = configuration->ipfilter;
	tManager->IpFrom = configuration->ip_from;
	tManager->IpTo = configuration->ip_to;
	tManager->Login = configuration->login;
	tManager->Logs = configuration->logs;
	tManager->Mailbox = gcnew System::String(configuration->mailbox);
	tManager->Manager = configuration->manager;
	tManager->MarketWatch = configuration->market_watch;
	tManager->Money = configuration->money;
	tManager->Name = gcnew System::String(configuration->name);
	tManager->News = configuration->news;
	tManager->Online = configuration->online;
	tManager->Plugins = configuration->plugins;
	tManager->Reports = configuration->reports;
	tManager->Riskman = configuration->riskman;

	tManager->SecGroups = gcnew System::Collections::Generic::List<P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^>();
	for (int i = 0; i < MAX_SEC_GROUPS; i++){
		tManager->SecGroups->Add(Convert(&configuration->secgroups[i]));
	}
	
	tManager->SeeTrades = configuration->see_trades;
	tManager->ServerReports = configuration->server_reports;
	tManager->Trades = configuration->trades;
	tManager->UserDetails = configuration->user_details;
	return tManager;
}

ConManager* P23::MetaTrader4::Manager::ClrWrapper::Convert(ManagerConfiguration^ configuration)
{
	ConManager* tManager = new ConManager();

	tManager->admin = configuration->Admin;
	tManager->broker = configuration->Broker;
	tManager->email = configuration->Email;

	char* groups = Convert(configuration->Groups);
	if (groups != NULL)
		COPY_STR(tManager->groups, groups);
	
	tManager->info_depth = configuration->InfoDepth;
	tManager->ipfilter = configuration->IpFilter;
	tManager->ip_from = (unsigned long)configuration->IpFrom;
	tManager->ip_to = (unsigned long)configuration->IpTo;
	tManager->login = configuration->Login;
	tManager->logs = configuration->Logs;

	char* mailbox = Convert(configuration->Mailbox);
	if (mailbox != NULL)
		COPY_STR(tManager->mailbox, mailbox);
	
	tManager->manager = configuration->Manager;
	tManager->market_watch = configuration->MarketWatch;
	tManager->money = configuration->Money;

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(tManager->name, name);
	
	tManager->news = configuration->News;
	tManager->online = configuration->Online;
	tManager->plugins = configuration->Plugins;
	tManager->reports = configuration->Reports;
	tManager->riskman = configuration->Riskman;
	if (configuration->SecGroups->Count != MAX_SEC_GROUPS)
		throw gcnew ArgumentException("Invalid number of securities");
		
	for (int i = 0; i < MAX_SEC_GROUPS; i++){
		tManager->secgroups[i] = *Convert(configuration->SecGroups[i]);
	}

	tManager->see_trades = configuration->SeeTrades;
	tManager->server_reports = configuration->ServerReports;
	tManager->trades = configuration->Trades;
	tManager->user_details = configuration->UserDetails;
	return tManager;
}

ManagerSecurity^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConManagerSec* configuration)
{
	P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ sec = gcnew P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity();
	sec->Enable = configuration->enable;
	sec->MaximumLots = configuration->maximum_lots;
	sec->MinimumLots = configuration->minimum_lots;
	return sec;
}

ConManagerSec* P23::MetaTrader4::Manager::ClrWrapper::Convert(ManagerSecurity^ configuration)
{
	ConManagerSec* sec = new ConManagerSec();
	sec->enable = configuration->Enable;
	sec->maximum_lots = configuration->MaximumLots;
	sec->minimum_lots = configuration->MinimumLots;
	return sec;
}

Common^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConCommon* configuration)
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

ConCommon* P23::MetaTrader4::Manager::ClrWrapper::Convert(Common^ configuration)
{
	ConCommon* newConfiguration = new ConCommon();
	
	char* adapters = Convert(configuration->Adapters);
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

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);
	
	newConfiguration->optimization_counter = configuration->OptimizationCounter;
	newConfiguration->optimization_lasttime = configuration->OptimizationLasttime;
	newConfiguration->optimization_time = configuration->OptimizationTime;
	newConfiguration->overmonth_last_month = configuration->OverMonthLastMonth;
	newConfiguration->overnight_last_day = configuration->OverNightLastDay;
	newConfiguration->overnight_last_time = configuration->OverNightLastTime;
	newConfiguration->overnight_prev_time = configuration->OverNightPrevTime;

	char* owner = Convert(configuration->Owner);
	if (owner != NULL)
		COPY_STR(newConfiguration->owner, owner);
	
	char* path_database = Convert(configuration->PathDatabase);
	if (path_database != NULL)
		COPY_STR(newConfiguration->path_database, path_database);
	
	char* path_history = Convert(configuration->PathHistory);
	if (path_history != NULL)
		COPY_STR(newConfiguration->path_history, path_history);
	
	char* path_log = Convert(configuration->PathLog);
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

	char* timesync = Convert(configuration->TimeSync);
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

Time^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConTime* configuration)
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

ConTime* P23::MetaTrader4::Manager::ClrWrapper::Convert(Time^ configuration)
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

Backup^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConBackup* configuration)
{
	Backup^ newConfiguration = gcnew Backup();
	
	newConfiguration->ArchiveLastTime = configuration->archive_lasttime;
	newConfiguration->ArchivePeriod = configuration->archive_period;
	newConfiguration->ArchiveShift = configuration->archive_shift;
	newConfiguration->ArchiveStore = configuration->archive_store;
	newConfiguration->ExportLastTime = configuration->export_lasttime;
	newConfiguration->ExportPath = gcnew String( configuration->export_path);
	newConfiguration->ExportPeriod = configuration->export_period;
	newConfiguration->ExportSecurities = gcnew String(configuration->export_securities);
	newConfiguration->ExternalPath = gcnew String(configuration->external_path);
	newConfiguration->FullBackupLastTime = configuration->fullbackup_lasttime;
	newConfiguration->FullBackupPath = gcnew String(configuration->fullbackup_path);
	newConfiguration->FullBackupPeriod = configuration->fullbackup_period;
	newConfiguration->FullBackupShift = configuration->fullbackup_shift;
	newConfiguration->FullBackupStore = configuration->fullbackup_store;
	newConfiguration->WatchFailover = configuration->watch_failover;
	newConfiguration->WatchIp = configuration->watch_ip;
	newConfiguration->WatchLogin = configuration->watch_login;
	newConfiguration->WatchOpposite = gcnew String(configuration->watch_opposite);
	newConfiguration->WatchPassword = gcnew String(configuration->watch_password);
	newConfiguration->WatchRole = configuration->watch_role;
	newConfiguration->WatchState = configuration->watch_state;
	newConfiguration->WatchTimeout = configuration->watch_timeout;
	newConfiguration->WatchTimestamp = configuration->watch_timestamp;
	
	return newConfiguration;
}

ConBackup* P23::MetaTrader4::Manager::ClrWrapper::Convert(Backup^ configuration)
{
	ConBackup* newConfiguration = new ConBackup();

	newConfiguration->archive_lasttime = configuration->ArchiveLastTime;
	newConfiguration->archive_period = configuration->ArchivePeriod;
	newConfiguration->archive_shift = (char)configuration->ArchiveShift;
	newConfiguration->archive_store = configuration->ArchiveStore;
	newConfiguration->export_lasttime = configuration->ExportLastTime;

	char* export_path = Convert(configuration->ExportPath);
	if (export_path != NULL)
		COPY_STR(newConfiguration->export_path, export_path);
	
	newConfiguration->export_period = configuration->ExportPeriod;

	char* export_securities = Convert(configuration->ExportSecurities);
	if (export_securities != NULL)
		COPY_STR(newConfiguration->export_securities, export_securities);

	char* external_path = Convert(configuration->ExternalPath);
	if (external_path != NULL)
		COPY_STR(newConfiguration->external_path, external_path);
				
	newConfiguration->fullbackup_lasttime = configuration->FullBackupLastTime;

	char* fullbackup_path = Convert(configuration->FullBackupPath);
	if (fullbackup_path != NULL)
		COPY_STR(newConfiguration->fullbackup_path, fullbackup_path);
	
	newConfiguration->fullbackup_period = configuration->FullBackupPeriod;
	newConfiguration->fullbackup_shift = configuration->FullBackupShift;
	newConfiguration->fullbackup_store = configuration->FullBackupStore;
	newConfiguration->watch_failover = (char)configuration->WatchFailover;
	newConfiguration->watch_ip = configuration->WatchIp;
	newConfiguration->watch_login = configuration->WatchLogin;

	char* watch_opposite = Convert(configuration->WatchOpposite);
	if (watch_opposite != NULL)
		COPY_STR(newConfiguration->watch_opposite, watch_opposite);
	
	char* watch_password = Convert(configuration->WatchPassword);
	if (watch_password != NULL)
		COPY_STR(newConfiguration->watch_password, watch_password);
	
	newConfiguration->watch_role = configuration->WatchRole;
	newConfiguration->watch_state = (char)configuration->WatchState;
	newConfiguration->watch_timeout = configuration->WatchTimeout;
	newConfiguration->watch_timestamp = configuration->WatchTimestamp;

	return newConfiguration;
}

SymbolGroup^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConSymbolGroup* configuration)
{
	SymbolGroup^ newConfiguration = gcnew SymbolGroup();

	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Name = gcnew String(configuration->name);

	return newConfiguration;
}

ConSymbolGroup* P23::MetaTrader4::Manager::ClrWrapper::Convert(SymbolGroup^ configuration)
{
	ConSymbolGroup* newConfiguration = new ConSymbolGroup();
	
	char* description = Convert(configuration->Description);
	if (description != NULL)
		COPY_STR(newConfiguration->description, description);

	char* name = Convert(configuration->Name);
	if (name != NULL)
		COPY_STR(newConfiguration->name, name);
	
	return newConfiguration;
}

Access^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConAccess* configuration)
{
	Access^ newConfiguration = gcnew Access();

	newConfiguration->Action = configuration->action;
	newConfiguration->Comment = gcnew String(configuration->comment);
	newConfiguration->From = configuration->from;
	newConfiguration->To = configuration->to;
	
	return newConfiguration;
}

ConAccess* P23::MetaTrader4::Manager::ClrWrapper::Convert(Access^ configuration)
{
	ConAccess* newConfiguration = new ConAccess();

	char* comment = Convert(configuration->Comment);
	if (comment != NULL)
		COPY_STR(newConfiguration->comment, comment);

	newConfiguration->action = configuration->Action;
	newConfiguration->from = configuration->From;
	newConfiguration->to = configuration->To;

	return newConfiguration;
}

DataServer^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConDataServer* configuration)
{
	DataServer^ newConfiguration = gcnew DataServer();

	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Ip = configuration->ip;
	newConfiguration->IpInternal = configuration->ip_internal;
	newConfiguration->IsProxy = configuration->isproxy;
	newConfiguration->Loading = configuration->loading;
	newConfiguration->Priority = configuration->priority;
	newConfiguration->Server = gcnew String(configuration->server);

	return newConfiguration;
}

ConDataServer* P23::MetaTrader4::Manager::ClrWrapper::Convert(DataServer^ configuration)
{
	ConDataServer* newConfiguration = new ConDataServer();

	char* description = Convert(configuration->Description);
	if (description != NULL)
		COPY_STR(newConfiguration->description, description);

	char* server = Convert(configuration->Server);
	if (server != NULL)
		COPY_STR(newConfiguration->server, server);

	newConfiguration->ip = configuration->Ip;
	newConfiguration->ip_internal = configuration->IpInternal;
	newConfiguration->isproxy = configuration->IsProxy;
	newConfiguration->loading = configuration->Loading;
	newConfiguration->priority = configuration->Priority;

	return newConfiguration;
}

Holiday^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConHoliday* configuration)
{
	Holiday^ newConfiguration = gcnew Holiday();

	newConfiguration->Day = configuration->day;
	newConfiguration->Description = gcnew String(configuration->description);
	newConfiguration->Enable = configuration->enable;
	newConfiguration->From = configuration->from;
	newConfiguration->Month = configuration->month;
	newConfiguration->Symbol = gcnew String(configuration->symbol);
	newConfiguration->To = configuration->to;
	newConfiguration->Year = configuration->year;

	return newConfiguration;
}

ConHoliday* P23::MetaTrader4::Manager::ClrWrapper::Convert(Holiday^ configuration)
{
	ConHoliday* newConfiguration = new ConHoliday();

	char* description = Convert(configuration->Description);
	if (description != NULL)
		COPY_STR(newConfiguration->description, description);

	char* symbol = Convert(configuration->Symbol);
	if (symbol != NULL)
		COPY_STR(newConfiguration->symbol, symbol);

	newConfiguration->day = configuration->Day;
	newConfiguration->enable = configuration->Enable;
	newConfiguration->from = configuration->From;
	newConfiguration->month = configuration->Month;
	newConfiguration->to = configuration->To;
	newConfiguration->year = configuration->Year;

	return newConfiguration;
}