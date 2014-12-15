// P23.MetaTrader4.Manager.ClrWrapper.h

#pragma once
#pragma comment(lib, "ws2_32.lib")

#include "MT4ManagerAPI.h"

using namespace System;
using namespace System::Runtime::InteropServices;

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
				static char* ConvertStringToChar(System::String^ inputString);

				//Helper method to convert managed objects to unmanaged un vise versa
				static ConManager* ConvertManagerConfiguration(P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration^ manager);
				static P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration^ ConvertManagerConfiguration(ConManager* manager);
				
				static ConManagerSec* ConvertManagerSecurity(P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ security);
				static P23::MetaTrader4::Manager::Contracts::Configuration::ManagerSecurity^ ConvertManagerSecurity(ConManagerSec* security);		
		
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
				int ManagerRights(P23::MetaTrader4::Manager::Contracts::Configuration::ManagerConfiguration^ manager);

				//--- server administration commands
				int SrvRestart();
				int SrvChartsSync();
				int SrvLiveUpdateStart();
				int SrvFeedsRestart();

				//--- server configuration
				//--- configuration request
				/*int  CfgRequestCommon(ConCommon *cfg);
				int  CfgRequestTime(ConTime *cfg);
				int  CfgRequestBackup(ConBackup *cfg);
				int  CfgRequestSymbolGroup(ConSymbolGroup *cfg);
				ConAccess*      CfgRequestAccess(int *total);
				ConDataServer*  CfgRequestDataServer(int *total);
				ConHoliday*     CfgRequestHoliday(int *total);
				ConSymbol*      CfgRequestSymbol(int *total);
				ConGroup*       CfgRequestGroup(int *total);
				ConManager*     CfgRequestManager(int *total);
				ConFeeder*      CfgRequestFeeder(int *total);
				ConLiveUpdate*  CfgRequestLiveUpdate(int *total);
				ConSync*        CfgRequestSync(int *total);
				ConPluginParam* CfgRequestPlugin(int *total);*/

				//pumping
				int PumpingSwitch(PumpingCallbackDelegate^ callBackDelegate);
			};		
		}
	}
}

	
