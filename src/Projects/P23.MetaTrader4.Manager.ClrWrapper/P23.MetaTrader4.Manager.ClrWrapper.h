// P23.MetaTrader4.Manager.ClrWrapper.h

#pragma once
#pragma comment(lib, "ws2_32.lib")

#include "MT4ManagerAPI.h"

#pragma unmanaged
#include "UnmanagedHelpers.h"
#pragma managed

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace P23::MetaTrader4::Manager::Contracts::Configuration;
using namespace System::Collections::Generic;

namespace P23{
	namespace MetaTrader4{
		namespace Manager{
			private class CManager
			{
			public:
				CManagerFactory    Factory;
				CManagerInterface *Manager;
				CManager(LPCSTR lib_path = NULL) : Factory(lib_path), Manager(NULL)
				{
					Factory.WinsockStartup();
					if (Factory.IsValid() == FALSE || (Manager = Factory.Create(ManAPIVersion)) == NULL)
					{
						System::Diagnostics::Debug::WriteLine("Manager Created");						
					}
				}
				~CManager()
				{
					if (Manager != NULL) { Manager->Release(); Manager = NULL; }
					Factory.WinsockCleanup();
					Factory.~CManagerFactory();
				}
				bool               IsValid()    { return(Manager != NULL); }				
			};

			public delegate void PumpingCallbackDelegate(int i);

			public ref class ClrWrapper : IDisposable
			{
			private:
				CManager*					_manager;
				bool						_isDisposed;
				GCHandle					_callBackHandler = GCHandle();
				PumpingCallbackDelegate^	_callBackDelegate;
				
				//Helpers
				static char* Convert(System::String^ inputString);
				static int* Convert(IList<int>^ input);

				//Helper method to convert managed objects to unmanaged un vise versa
				static ConManager* Convert(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ manager);
				static P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ Convert(ConManager* manager);
		
				static ConManagerSec* Convert(ManagerSecurity^ security);
				static ManagerSecurity^ Convert(ConManagerSec* security);
				
				static ConCommon* Convert(Common^ configuration);
				static Common^ Convert(ConCommon* configuration);

				static ConTime* Convert(Time^ configuration);
				static Time^ Convert(ConTime* configuration);
				
				static ConBackup* Convert(Backup^ configuration);
				static Backup^ Convert(ConBackup* configuration);

				static ConSymbolGroup* Convert(SymbolGroup^ configuration);
				static SymbolGroup^ Convert(ConSymbolGroup* configuration);

				static ConAccess* Convert(Access^ configuration);
				static Access^ Convert(ConAccess* configuration);

				static ConDataServer* Convert(DataServer^ configuration);
				static DataServer^ Convert(ConDataServer* configuration);

				static ConHoliday* Convert(Holiday^ configuration);
				static Holiday^ Convert(ConHoliday* configuration);

				static ConSymbol* Convert(Symbol^ configuration);
				static Symbol^ Convert(ConSymbol* configuration);

				static ConSessions* Convert(Sessions^ configuration);
				static Sessions^ Convert(ConSessions* configuration);

				static ConSession* Convert(Session^ configuration);
				static Session^ Convert(ConSession* configuration);

				static ConGroup* Convert(Group^ configuration);
				static Group^ Convert(ConGroup* configuration);

				static ConGroupSec* Convert(GroupSecurity^ configuration);
				static GroupSecurity^ Convert(ConGroupSec* configuration);

				static ConGroupMargin* Convert(GroupMargin^ configuration);
				static GroupMargin^ Convert(ConGroupMargin* configuration);

				static ConFeeder* Convert(Feeder^ configuration);
				static Feeder^ Convert(ConFeeder* configuration);

				static ConLiveUpdate* Convert(LiveUpdate^ configuration);
				static LiveUpdate^ Convert(ConLiveUpdate* configuration);

				static ConSync* Convert(Synchronization^ configuration);
				static Synchronization^ Convert(ConSync* configuration);

				static LiveInfoFile* Convert(FilesConfigurations^ configuration);
				static FilesConfigurations^ Convert(LiveInfoFile* configuration);
				
				static ConPluginParam* Convert(PluginWithParameters^ configuration);
				static PluginWithParameters^ Convert(ConPluginParam* configuration);
				
				static ConPlugin* Convert(Plugin^ configuration);
				static Plugin^ Convert(ConPlugin* configuration);
				
				static PluginInfo* Convert(PluginInformation^ configuration);
				static PluginInformation^ Convert(PluginInfo* configuration);
				
				static PluginCfg* Convert(PluginConfigurationParameter^ configuration);
				static PluginConfigurationParameter^ Convert(PluginCfg* configuration);

				static P23::MetaTrader4::Manager::Contracts::ServerFeed^  P23::MetaTrader4::Manager::ClrWrapper::Convert(ServerFeed* configuration);
				static P23::MetaTrader4::Manager::Contracts::FeedDescription^  P23::MetaTrader4::Manager::ClrWrapper::Convert(FeedDescription* input);

				static P23::MetaTrader4::Manager::Contracts::PerformanceInfo^  P23::MetaTrader4::Manager::ClrWrapper::Convert(PerformanceInfo* input);
								
				static P23::MetaTrader4::Manager::Contracts::BackupInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(BackupInfo* input);

				static P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^ P23::MetaTrader4::Manager::ClrWrapper::Convert(TradeRestoreResult* input);

				static P23::MetaTrader4::Manager::Contracts::UserRecord^ P23::MetaTrader4::Manager::ClrWrapper::Convert(UserRecord* input);
				static UserRecord* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::UserRecord^ input);
				
				static P23::MetaTrader4::Manager::Contracts::TradeRecord^ P23::MetaTrader4::Manager::ClrWrapper::Convert(TradeRecord* input);
				static TradeRecord* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::TradeRecord^ input);

				static P23::MetaTrader4::Manager::Contracts::SymbolInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(SymbolInfo* input);

				static P23::MetaTrader4::Manager::Contracts::MailBox^ P23::MetaTrader4::Manager::ClrWrapper::Convert(MailBox* input);
				static MailBox* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::MailBox^ input);

				static P23::MetaTrader4::Manager::Contracts::NewsTopic^ P23::MetaTrader4::Manager::ClrWrapper::Convert(NewsTopic* input);
				static NewsTopic* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::NewsTopic^ input);

				static P23::MetaTrader4::Manager::Contracts::ServerLog^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ServerLog* input);

				static TradeTransInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ input);
				static P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(TradeTransInfo* input);

				static GroupCommandInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::GroupCommandInfo^ input);

				static P23::MetaTrader4::Manager::Contracts::OnlineRecord^ P23::MetaTrader4::Manager::ClrWrapper::Convert(OnlineRecord* input);

				static P23::MetaTrader4::Manager::Contracts::DailyReport^ P23::MetaTrader4::Manager::ClrWrapper::Convert(DailyReport* input);
				
				static ReportGroupRequest* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::ReportGroupRequest^ input);

				static DailyGroupRequest* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::DailyGroupRequest^ input);
						
				static P23::MetaTrader4::Manager::Contracts::RequestInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(RequestInfo* input);
				static RequestInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::RequestInfo^ input);

				static P23::MetaTrader4::Manager::Contracts::MarginLevel^ P23::MetaTrader4::Manager::ClrWrapper::Convert(MarginLevel* input);

				static P23::MetaTrader4::Manager::Contracts::SymbolSummary^ P23::MetaTrader4::Manager::ClrWrapper::Convert(SymbolSummary* input);

				static P23::MetaTrader4::Manager::Contracts::ExposureValue^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ExposureValue* input);
					
				static P23::MetaTrader4::Manager::Contracts::RateInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(RateInfo* input);
				static RateInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::RateInfo^ input);
				
				static ChartInfo* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::ChartInfo^ input);

				static TickRequest* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::TickRequest^ input);

				static P23::MetaTrader4::Manager::Contracts::TickRecord^ P23::MetaTrader4::Manager::ClrWrapper::Convert(TickRecord* input);
				
				
			public:
				//constructors
				ClrWrapper();
				ClrWrapper(String^ metatraderLibraryPath);
				ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters);
				ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters, String^ metatraderLibraryPath);

				//Destructors, finalizers
				~ClrWrapper();
				!ClrWrapper();

				//--- service methods				
				System::String^ ErrorDescription(int code);

				//--- connection
				int Connect(System::String^ server);
				int Disconnect();
				int IsConnected();
				int Login(int login, System::String^ password);
				int LoginSecured(System::String^ keyPath);
				int KeysSend(System::String^ keyPath);
				int Ping();
				int PasswordChange(System::String^ password, int isInvestor);
				int ManagerRights(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ manager);

				//--- server administration commands
				int SrvRestart();
				int SrvChartsSync();
				int SrvLiveUpdateStart();
				int SrvFeedsRestart();

				//--- server configuration
				//--- configuration request
				Common^  CfgRequestCommon();
				Time^  CfgRequestTime();
				Backup^  CfgRequestBackup();
				SymbolGroup^  CfgRequestSymbolGroup();
				IList<Access^>^      CfgRequestAccess();
				IList<DataServer^>^  CfgRequestDataServer();
				IList<Holiday^>^     CfgRequestHoliday();
				IList<Symbol^>^      CfgRequestSymbol();
				IList<Group^>^       CfgRequestGroup();
				IList<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>^     CfgRequestManager();
				IList<Feeder^>^      CfgRequestFeeder();
				IList<LiveUpdate^>^  CfgRequestLiveUpdate();
				IList<Synchronization^>^        CfgRequestSync();
				IList<PluginWithParameters^>^ CfgRequestPlugin();

				//--- configuration update
				int CfgUpdateCommon(Common^ configuration);
				int CfgUpdateAccess(Access^ configuration, int position);
				int CfgUpdateDataServer(DataServer^ configuration, int position);
				int CfgUpdateTime(Time^ configuration);
				int CfgUpdateHoliday(Holiday^ configuration, int position);
				int CfgUpdateSymbol(Symbol^ configuration);
				int CfgUpdateSymbolGroup(SymbolGroup^ configuration, int position);
				int CfgUpdateGroup(Group^ configuration);
				int CfgUpdateManager(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ configuration);
				int CfgUpdateFeeder(Feeder^ configuration);
				int CfgUpdateBackup(Backup^ configuration);
				int CfgUpdateLiveUpdate(LiveUpdate^ configuration);
				int CfgUpdateSync(Synchronization^ configuration);
				int CfgUpdatePlugin(Plugin^ configuration, IList<PluginConfigurationParameter^>^ parameters);

				//--- configuration delete
				int CfgDeleteAccess(int position);
				int CfgDeleteDataServer(int position);
				int CfgDeleteHoliday(int position);
				int CfgDeleteSymbol(int position);
				int CfgDeleteGroup(int position);
				int CfgDeleteManager(int position);
				int CfgDeleteFeeder(int position);
				int CfgDeleteLiveUpdate(int position);
				int CfgDeleteSync(int position);

				//--- configuration shift
				int CfgShiftAccess(int position, int shift);
				int CfgShiftDataServer(int position, int shift);
				int CfgShiftHoliday(int position, int shift);
				int CfgShiftSymbol(int position, int shift);
				int CfgShiftGroup(int position, int shift);
				int CfgShiftManager(int position, int shift);
				int CfgShiftFeeder(int position, int shift);
				int CfgShiftLiveUpdate(int position, int shift);
				int CfgShiftSync(int position, int shift);
				int CfgShiftPlugin(int position, int shift);

				//--- server feeders
				IList<P23::MetaTrader4::Manager::Contracts::ServerFeed^>^ SrvFeeders();
				String^ SrvFeederLog(String^ name);

				//--- performance info
				IList<P23::MetaTrader4::Manager::Contracts::PerformanceInfo^>^ PerformaneRequest(UInt32 from);

				//--- users/trades backups
				IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^  BackupInfoUsers(int mode);
				IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^  BackupInfoOrders(int mode);
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^  BackupRequestUsers(String^ file, String^ request);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ BackupRequestOrders(String^ file, String^ request);
				int BackupRestoreUsers(IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ users);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^>^ BackupRestoreOrders(IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ trades);

				//--- administrator databases commands
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^  AdmUsersRequest(String^ group);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ AdmTradesRequest(String^ group, int openOnly);
				int AdmBalanceFix(IList<int>^ logins);
				int AdmTradesDelete(IList<int>^ orders);
				int AdmTradeRecordModify(P23::MetaTrader4::Manager::Contracts::TradeRecord^ trade);

				//--- symbols
				int SymbolsRefresh();
				IList<P23::MetaTrader4::Manager::Contracts::Configuration::Symbol^>^ SymbolsGetAll();
				P23::MetaTrader4::Manager::Contracts::Configuration::Symbol^ SymbolGet(String^ symbol);
				P23::MetaTrader4::Manager::Contracts::SymbolInfo^ SymbolInfoGet(String^ symbol);
				int SymbolAdd(String^ symbol);
				int SymbolHide(String^ symbol);
				//--- symbol commands
				int SymbolSendTick(String^ symbol, double bid, double ask);

				//--- manager commands
				IList<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>^ GroupsRequest();
				int MailSend(P23::MetaTrader4::Manager::Contracts::MailBox^ mail, IList<int>^ logins);
				int NewsSend(P23::MetaTrader4::Manager::Contracts::NewsTopic^ news);

				//--- journal
				IList<P23::MetaTrader4::Manager::Contracts::ServerLog^>^ JournalRequest(int mode, UInt32 from, UInt32 to, String^ filter);

				//--- databases: direct request to the server
				//--- users
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ UsersRequest();
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ UserRecordsRequest(IList<int>^ logins);
				int UserRecordNew(P23::MetaTrader4::Manager::Contracts::UserRecord^ user);
				int UserRecordUpdate(P23::MetaTrader4::Manager::Contracts::UserRecord^ user);
				int UsersGroupOp(P23::MetaTrader4::Manager::Contracts::GroupCommandInfo^ info, IList<int>^ logins);
				int UserPasswordCheck(int login, String^ password);
				int UserPasswordSet(int login, String^ password, int changeInvestor, int cleanPubKey);
				IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ OnlineRequest();

				//--- orders
				int TradeTransaction(P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ info);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesRequest();
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradeRecordsRequest(IList<int>^ orders);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesUserHistory(int login, UInt32 from, UInt32 to);
				int TradeCheckStops(P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ trade, double price);

				//--- reports
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ ReportsRequest(P23::MetaTrader4::Manager::Contracts::ReportGroupRequest^ request, IList<int>^ logins);
				IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ DailyReportsRequest(P23::MetaTrader4::Manager::Contracts::DailyGroupRequest^ request, IList<int>^ logins);
				//--- external command
				int ExternalCommand(String^ dataIn, int sizeIn, String^ dataOut, int sizeOut);
				//--- plugins
				int PluginUpdate(PluginWithParameters^ plugin);

				//pumping
				int PumpingSwitch(PumpingCallbackDelegate^ callBackDelegate);
				IList<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>^ GroupsGet();
				P23::MetaTrader4::Manager::Contracts::Configuration::Group^ GroupRecordGet(String^ name);
				IList<P23::MetaTrader4::Manager::Contracts::SymbolInfo^>^ SymbolInfoUpdated();
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ UsersGet();
				P23::MetaTrader4::Manager::Contracts::UserRecord^ UserRecordGet(int login);
				IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ OnlineGet();
				P23::MetaTrader4::Manager::Contracts::OnlineRecord^ OnlineRecordGet(int login);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesGet();
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesGetBySymbol(String^ symbol);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesGetByLogin(int login, String^ group);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesGetByMarket();
				P23::MetaTrader4::Manager::Contracts::TradeRecord^ TradeRecordGet(int order);
				int TradeClearRollback(int order);
				IList<P23::MetaTrader4::Manager::Contracts::MarginLevel^>^ MarginsGet();
				P23::MetaTrader4::Manager::Contracts::MarginLevel^ MarginLevelGet(int login, String^ group);
				IList<P23::MetaTrader4::Manager::Contracts::RequestInfo^>^ RequestsGet();
				P23::MetaTrader4::Manager::Contracts::RequestInfo^ RequestInfoGet(int position);
				IList<P23::MetaTrader4::Manager::Contracts::Configuration::Plugin^>^ PluginsGet();
				P23::MetaTrader4::Manager::Contracts::Configuration::PluginWithParameters^ PluginParamGet(int position);
				int MailLast(String^ path, int length);
				IList<P23::MetaTrader4::Manager::Contracts::NewsTopic^>^ NewsGet();
				int NewsTotal();
				P23::MetaTrader4::Manager::Contracts::NewsTopic^ NewsTopicGet(int position);
				void NewsBodyRequest(int key);
				String^ NewsBodyGet(int key);

				//--- dealing
				int DealerSwitch(PumpingCallbackDelegate^ callBackDelegate);
				P23::MetaTrader4::Manager::Contracts::RequestInfo^ DealerRequestGet();
				int DealerSend(P23::MetaTrader4::Manager::Contracts::RequestInfo^ info, int requote, int mode);
				int DealerReject(int id);
				int DealerReset(int id);

				//--- risk management
				IList<P23::MetaTrader4::Manager::Contracts::SymbolSummary^>^ SummaryGetAll();
				P23::MetaTrader4::Manager::Contracts::SymbolSummary^ SummaryGet(String^ symbol);
				P23::MetaTrader4::Manager::Contracts::SymbolSummary^ SummaryGetByCount(int symbol);
				P23::MetaTrader4::Manager::Contracts::SymbolSummary^ SummaryGetByType(int sectype);
				int SummaryCurrency(String^ cur, int maxchars);
				IList<P23::MetaTrader4::Manager::Contracts::ExposureValue^>^ ExposureGet();
				P23::MetaTrader4::Manager::Contracts::ExposureValue^ ExposureValueGet(String^ cur);
				//---
				P23::MetaTrader4::Manager::Contracts::MarginLevel^ MarginLevelRequest(int login);
				int HistoryCorrect(String^ symbol, int updated);

				//--- new chart bases
				IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ ChartRequest(P23::MetaTrader4::Manager::Contracts::ChartInfo^ chart, UInt32 timesign);
				int ChartAdd(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates);
				int ChartUpdate(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates);
				int ChartDelete(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates);
				//--- ticks base
				IList<P23::MetaTrader4::Manager::Contracts::TickRecord^>^ TicksRequest(P23::MetaTrader4::Manager::Contracts::TickRequest^ request);

				//--- internal methods
				/*int PumpingSwitchEx(MTAPI_NOTIFY_FUNC_EX pfnFunc, const int flags, void *param);
				int UsersSyncStart(UInt32 timestamp);
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ UsersSyncRead();
				IList<int>^ UsersSnapshot();
				int TradesSyncStart(UInt32 timestamp);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesSyncRead();
				IList<int>^ TradesSnapshot();
				int DailySyncStart(UInt32 timestamp);
				IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ DailySyncRead();*/
			};		
		}
	}
}

	
