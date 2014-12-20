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
				CManager() : Factory(NULL), Manager(NULL)
				{
					Factory.WinsockStartup();
					if (Factory.IsValid() == FALSE || (Manager = Factory.Create(ManAPIVersion)) == NULL)
					{
						return;
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
				
			public:
				//constructors
				ClrWrapper();
				ClrWrapper(P23::MetaTrader4::Manager::Contracts::IConnectionParameters^ connectionParameters);

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
				/*int CfgShiftAccess(int position, int shift);
				int CfgShiftDataServer(int position, int shift);
				int CfgShiftHoliday(int position, int shift);
				int CfgShiftSymbol(int position, int shift);
				int CfgShiftGroup(int position, int shift);
				int CfgShiftManager(int position, int shift);
				int CfgShiftFeeder(int position, int shift);
				int CfgShiftLiveUpdate(int position, int shift);
				int CfgShiftSync(int position, int shift);
				int CfgShiftPlugin(int position, int shift);*/

				//pumping
				int PumpingSwitch(PumpingCallbackDelegate^ callBackDelegate);
			};		
		}
	}
}

	
