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

			public delegate void ExtendedCallBackDelegate(int code, int type, void *data, void *param);

			public delegate void TradeRecordUpdated(System::Object^ sender, P23::MetaTrader4::Manager::Contracts::TradeRecord^ tradeRecord);
			
			public delegate void OnlineRecordUpdated(System::Object^ sender, P23::MetaTrader4::Manager::Contracts::OnlineRecord^ onlineRecord);
			
			public delegate void UserRecordUpdated(System::Object^ sender, P23::MetaTrader4::Manager::Contracts::UserRecord^ userRecord);

			/// <summary>
			/// Wrapper around mtmanapi.dll to provede managed access to MT4 manager API
			/// </summary>
			public ref class ClrWrapper : IDisposable
			{
			private:
				const int					NumberOfSecondsInDay = 86400;

				CManager*					_manager;
				bool						_isDisposed;
				GCHandle					_callBackHandler = GCHandle();
				PumpingCallbackDelegate^	_callBackDelegate;
				ExtendedCallBackDelegate^	_extendedPumpingCallBack;
				void						ExtendedPumpingNotify(int code, int type, void *data, void *param);
				
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

				static SymbolProperties* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::SymbolProperties^ input);
						
				static P23::MetaTrader4::Manager::Contracts::Configuration::GatewayAccount^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConGatewayAccount* input);
				static ConGatewayAccount* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::Configuration::GatewayAccount^ input);

				static P23::MetaTrader4::Manager::Contracts::Configuration::GatewayMarkup^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConGatewayMarkup* input);
				static ConGatewayMarkup* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::Configuration::GatewayMarkup^ input);

				static P23::MetaTrader4::Manager::Contracts::Configuration::GatewayRule^ P23::MetaTrader4::Manager::ClrWrapper::Convert(ConGatewayRule* input);
				static ConGatewayRule* P23::MetaTrader4::Manager::ClrWrapper::Convert(P23::MetaTrader4::Manager::Contracts::Configuration::GatewayRule^ input);

				static P23::MetaTrader4::Manager::Contracts::BalanceDiff^ P23::MetaTrader4::Manager::ClrWrapper::Convert(BalanceDiff* input);
				
				static P23::MetaTrader4::Manager::Contracts::TickInfo^ P23::MetaTrader4::Manager::ClrWrapper::Convert(TickInfo* input);
				
			public:
				
				/// <summary>
				/// Event rised when added new trade. Works only in extended pumping mode
				/// </summary>
				event TradeRecordUpdated^		TradeAdded;

				/// <summary>
				/// Event rised when trade changed. Works only in extended pumping mode
				/// </summary>
				event TradeRecordUpdated^		TradeUpdated;

				/// <summary>
				/// Event rised when trade closed. Works only in extended pumping mode
				/// </summary>
				event TradeRecordUpdated^		TradeClosed;

				/// <summary>
				/// Event rised when pending order deleted. Works only in extended pumping mode
				/// </summary>
				event TradeRecordUpdated^		TradeDeleted;

				/// <summary>
				/// Event rised when pumping started. Works only in pumping mode
				/// </summary>
				event EventHandler^				PumpingStarted;

				/// <summary>
				/// Event rised when pumping stopped. Works only in pumping mode
				/// </summary>
				event EventHandler^				PumpingStopped;

				/// <summary>
				/// Event rised when new quote recieved. Works only in extended pumping mode
				/// </summary>
				event EventHandler^				BidAskUpdated;

				/// <summary>
				/// Event rised when online users updated. Works only in extended pumping mode
				/// </summary>
				event OnlineRecordUpdated^		OnlineUpdated;

				/// <summary>
				/// Event rised when user record changes. Works only in extended pumping mode
				/// </summary>
				event UserRecordUpdated^		UserUpdated;

				//constructors
				/// <summary>
				/// Instantiate ClrWrapper, no connection will be created, mtmanapi.dll should be located in current directory
				/// </summary>
				ClrWrapper();

				/// <summary>
				/// Instantiate ClrWrapper, no connection will be created
				/// </summary>
				/// <param name="metatraderLibraryPath">path to mtmanapi.dll</param>
				ClrWrapper(String^ metatraderLibraryPath);

				/// <summary>
				/// Instantiate ClrWrapper, connection will be created, mtmanapi.dll should be located in current directory
				/// </summary>
				/// <param name="connectionParameters">parameters to connect to MT server</param>
				ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters);

				/// <summary>
				/// Instantiate ClrWrapper, connection will be created
				/// </summary>
				/// <param name="connectionParameters">parameters to connect to MT server</param>
				/// <param name="metatraderLibraryPath">path to mtmanapi.dll</param>
				ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters, String^ metatraderLibraryPath);

				//Destructors, finalizers
				~ClrWrapper();
				!ClrWrapper();

				//--- service methods	
				/// <summary>
				/// Get error description for provided code
				/// </summary>
				/// <param name="code">error code</param>
				System::String^ ErrorDescription(int code);

				//--- connection
				/// <summary>
				/// Connect to MT server
				/// </summary>
				/// <param name="server">MT Server address(ip:port). It's recomended to user actual MT server address, not data center</param>
				int Connect(System::String^ server);
				
				/// <summary>
				/// Disconnect from MT server
				/// </summary>
				int Disconnect();

				/// <summary>
				/// Check connection to MT server
				/// </summary>
				int IsConnected();
				
				/// <summary>
				/// Login into MT server, connection must be established
				/// </summary>
				/// <param name="login">manager's login</param>
				/// <param name="password">manager's password</param>
				int Login(int login, System::String^ password);
				
				/// <summary>
				/// Login into MT server, using RSA key
				/// </summary>
				/// <param name="keyPath">path to the RSA - keys file</param>
				int LoginSecured(System::String^ keyPath);

				/// <summary>
				/// Send public key to MT server
				/// </summary>
				/// <param name="keyPath">path to the RSA - keys file</param>
				int KeysSend(System::String^ keyPath);

				/// <summary>
				/// Ping MT server
				/// </summary>
				int Ping();

				/// <summary>
				/// Change manager's password
				/// </summary>
				/// <param name="password">new password</param>
				/// <param name="isInvestor">0 - change trader's password, 1 - change investor's password</param>
				int PasswordChange(System::String^ password, int isInvestor);

				/// <summary>
				/// Request manager rights for provided manager
				/// </summary>
				/// <param name="manager">manager structure</param>
				int ManagerRights(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ manager);

				//--- server administration commands
				/// <summary>
				/// Restart MT server
				/// </summary>
				int SrvRestart();

				/// <summary>
				/// Synchronize history data
				/// </summary>
				int SrvChartsSync();
				
				/// <summary>
				/// Start LiveUpdate
				/// </summary>				
				int SrvLiveUpdateStart();

				/// <summary>
				/// Restart data feeds
				/// </summary>	
				int SrvFeedsRestart();

				//--- server configuration
				//--- configuration request
				/// <summary>
				/// Request common configuration section
				/// </summary>	
				Common^  CfgRequestCommon();

				/// <summary>
				/// Request time configuration section
				/// </summary>	
				Time^  CfgRequestTime();

				/// <summary>
				/// Request backup configuration section
				/// </summary>	
				Backup^  CfgRequestBackup();

				/// <summary>
				/// Request symbol group configuration section
				/// </summary>	
				SymbolGroup^  CfgRequestSymbolGroup();

				/// <summary>
				/// Request accesses configuration
				/// </summary>	
				IList<Access^>^      CfgRequestAccess();

				/// <summary>
				/// Request dataservers configuration
				/// </summary>	
				IList<DataServer^>^  CfgRequestDataServer();

				/// <summary>
				/// Request holidays configuration
				/// </summary>	
				IList<Holiday^>^     CfgRequestHoliday();

				/// <summary>
				/// Request symbols configuration
				/// </summary>
				IList<Symbol^>^      CfgRequestSymbol();

				/// <summary>
				/// Request groups configuration
				/// </summary>
				IList<Group^>^       CfgRequestGroup();

				/// <summary>
				/// Request managers configuration
				/// </summary>
				IList<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>^     CfgRequestManager();
				
				/// <summary>
				/// Request feeders configuration
				/// </summary>
				IList<Feeder^>^      CfgRequestFeeder();
				
				/// <summary>
				/// Request live updates configuration
				/// </summary>
				IList<LiveUpdate^>^  CfgRequestLiveUpdate();
				
				/// <summary>
				/// Request synchronizations configuration
				/// </summary>
				IList<Synchronization^>^        CfgRequestSync();

				/// <summary>
				/// Request plugins configuration
				/// </summary>
				IList<PluginWithParameters^>^ CfgRequestPlugin();

				//--- configuration update
				/// <summary>
				/// Update common configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateCommon(Common^ configuration);

				/// <summary>
				/// Create access configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				/// <param name="position">place where new configuration should be inserted</param>
				int CfgUpdateAccess(Access^ configuration, int position);

				/// <summary>
				/// Create date server configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				/// <param name="position">place where new configuration should be inserted</param>
				int CfgUpdateDataServer(DataServer^ configuration, int position);

				/// <summary>
				/// Update time configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateTime(Time^ configuration);

				/// <summary>
				/// Create new holiday configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				/// <param name="position">place where new configuration should be inserted</param>
				int CfgUpdateHoliday(Holiday^ configuration, int position);

				/// <summary>
				/// Update or create symbol configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateSymbol(Symbol^ configuration);

				/// <summary>
				/// Create symbol group configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				/// <param name="position">place where new configuration should be inserted</param>
				int CfgUpdateSymbolGroup(SymbolGroup^ configuration, int position);

				/// <summary>
				/// Create or update configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateGroup(Group^ configuration);

				/// <summary>
				/// Create or update manager configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateManager(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ configuration);
				
				/// <summary>
				/// Create or update feeder configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateFeeder(Feeder^ configuration);
				
				/// <summary>
				/// Update backup configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateBackup(Backup^ configuration);

				/// <summary>
				/// Create or update live update configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateLiveUpdate(LiveUpdate^ configuration);

				/// <summary>
				/// Create or update synchronization configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdateSync(Synchronization^ configuration);

				/// <summary>
				/// Create or update plugin configuration
				/// </summary>
				/// <param name="configuration">new configuration parameters</param>
				int CfgUpdatePlugin(Plugin^ configuration, IList<PluginConfigurationParameter^>^ parameters);

				//--- configuration delete
				/// <summary>
				/// Delete access configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteAccess(int position);

				/// <summary>
				/// Delete data server configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteDataServer(int position);

				/// <summary>
				/// Delete holiday configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteHoliday(int position);

				/// <summary>
				/// Delete symbol configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteSymbol(int position);

				/// <summary>
				/// Delete group configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteGroup(int position);

				/// <summary>
				/// Delete manager configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteManager(int position);

				/// <summary>
				/// Delete feeder configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteFeeder(int position);

				/// <summary>
				/// Delete live update configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteLiveUpdate(int position);

				/// <summary>
				/// Delete synchonization configuration
				/// </summary>
				/// <param name="position">position of configuration to be deleted(zero-based index)</param>
				int CfgDeleteSync(int position);

				//--- configuration shift
				/// <summary>
				/// Shift position for access configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftAccess(int position, int shift);

				/// <summary>
				/// Shift position for data server configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftDataServer(int position, int shift);

				/// <summary>
				/// Shift position for holiday configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftHoliday(int position, int shift);
				
				/// <summary>
				/// Shift position for symbol configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftSymbol(int position, int shift);

				/// <summary>
				/// Shift position for group configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftGroup(int position, int shift);

				/// <summary>
				/// Shift position for manager configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftManager(int position, int shift);

				/// <summary>
				/// Shift position for feeder configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftFeeder(int position, int shift);

				/// <summary>
				/// Shift position for live update configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftLiveUpdate(int position, int shift);

				/// <summary>
				/// Shift position for synchronization configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftSync(int position, int shift);

				/// <summary>
				/// Shift position for plugin configuration
				/// </summary>
				/// <param name="position">position of configuration to be shifter(zero-based index)</param>
				/// <param name="shift">offset from current position</param>
				int CfgShiftPlugin(int position, int shift);

				//--- server feeders
				/// <summary>
				/// Request all available on MT server data feeds
				/// </summary>
				IList<P23::MetaTrader4::Manager::Contracts::ServerFeed^>^ SrvFeeders();

				/// <summary>
				/// Request logs of configured data feed
				/// </summary>
				/// <param name="name">feed name</param>
				String^ SrvFeederLog(String^ name);

				//--- performance info
				/// <summary>
				/// Request performance counters from MT server
				/// </summary>
				/// <param name="from">from</param>
				IList<P23::MetaTrader4::Manager::Contracts::PerformanceInfo^>^ PerformaneRequest(UInt32 from);

				//--- users/trades backups
				/// <summary>
				/// Request for the file list of backups of the account database
				/// </summary>
				/// <param name="mode">mode</param>
				IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^  BackupInfoUsers(int mode);

				/// <summary>
				/// Request for the file list of backups of the order database
				/// </summary>
				/// <param name="mode">mode</param>
				IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^  BackupInfoOrders(int mode);

				/// <summary>
				/// Search for users in specified backup
				/// </summary>
				/// <param name="file">name of backup file</param>
				/// <param name="request">search string</param>
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^  BackupRequestUsers(String^ file, String^ request);
				
				/// <summary>
				/// Search for orders in specified backup
				/// </summary>
				/// <param name="file">name of backup file</param>
				/// <param name="request">search string</param>
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ BackupRequestOrders(String^ file, String^ request);
				
				/// <summary>
				/// Restore specified users from backup
				/// </summary>
				/// <param name="users">users to be restored</param>
				int BackupRestoreUsers(IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ users);
				
				/// <summary>
				/// Restore specified orders from backup
				/// </summary>
				/// <param name="users">orders to be restored</param>
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

				//---
				IList<P23::MetaTrader4::Manager::Contracts::TickInfo^>^ TickInfoLast(String^ symbol);
				int SymbolsGroupsGet(IList<P23::MetaTrader4::Manager::Contracts::Configuration::SymbolGroup^>^ groups);
				long ServerTime();
				IList<P23::MetaTrader4::Manager::Contracts::MailBox^>^ MailsRequest();

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
				int PumpingSwitchEx();
				int UsersSyncStart(UInt32 timestamp);
				IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ UsersSyncRead();
				IList<int>^ UsersSnapshot();
				int TradesSyncStart(UInt32 timestamp);
				IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ TradesSyncRead();
				IList<int>^ TradesSnapshot();
				int DailySyncStart(UInt32 timestamp);
				IList<P23::MetaTrader4::Manager::Contracts::DailyReport^>^ DailySyncRead();

				//--- profit recalculation
				int TradeCalcProfit(P23::MetaTrader4::Manager::Contracts::TradeRecord^ trade);
				
				//--- new symbol commands
				int SymbolChange(P23::MetaTrader4::Manager::Contracts::SymbolProperties^ prop);
				
				//--- network statistics
				int BytesSent();
				int BytesReceived();
				
				//---
				int ManagerCommon(Common^ common);
				
				//--- log access
				void LogsOut(int code, System::String^ source, System::String^ msg);
				void LogsMode(int mode);
				
				//--- check license
				int LicenseCheck(System::String^ licenseName);

				//--- gateway configs
				IList<GatewayAccount^>^ CfgRequestGatewayAccount();
				IList<GatewayMarkup^>^ CfgRequestGatewayMarkup();
				IList<GatewayRule^>^ CfgRequestGatewayRule();
				
				//--- configuration update
				int CfgUpdateGatewayAccount(GatewayAccount^ cfg);
				int CfgUpdateGatewayMarkup(GatewayMarkup^ cfg);
				int CfgUpdateGatewayRule(GatewayRule^ cfg);
				
				//--- configuration delete
				int CfgDeleteGatewayAccount(int pos);
				int CfgDeleteGatewayMarkup(int pos);
				int CfgDeleteGatewayRule(int pos);
				
				//--- configuration shift
				int CfgShiftGatewayAccount(int pos, int shift);
				int CfgShiftGatewayMarkup(int pos, int shift);
				int CfgShiftGatewayRule(int pos, int shift);
				
				//--- administrator databases commands
				IList<P23::MetaTrader4::Manager::Contracts::BalanceDiff^>^  AdmBalanceCheck(IList<int>^ logins);
			};		
		}
	}
}

	
