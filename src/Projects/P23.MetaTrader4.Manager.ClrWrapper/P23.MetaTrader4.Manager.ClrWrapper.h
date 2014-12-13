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
				//CManagerInterface* operator->() { return(m_manager);       }
			};

			public ref class ClrWrapper
			{
			private:
				CManager*       _manager;
				/*bool			_managerConnected;
				ConSymbol		FindSymbolConfig(char* symbol);
				ConGroup		FindGroupConfig(char* group);
				ConGroup		FindGroupConfig(System::String^ groupName);
				RateInfo*		CheckAndCreateRates(char* symbol, List<InstaForex::Metatrader::DataContracts::Chart::RateInfoManaged^>^ rates, int length);
				static const int		DaysInWeek = 7;*/
			public:
				ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters);

			};		
		}
	}
}

	
