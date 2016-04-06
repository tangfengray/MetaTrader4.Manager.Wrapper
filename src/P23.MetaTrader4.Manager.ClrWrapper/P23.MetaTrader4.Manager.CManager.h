#pragma once

#include "MT4ManagerAPI.h"

namespace P23 {
	namespace MetaTrader4 {
		namespace Manager {
			private class CManager
			{
				public:
					CManagerFactory    Factory;
					CManagerInterface *Manager;
					CManager(LPCSTR lib_path = NULL);
					~CManager();
					bool               IsValid();
			};
		}
	}
}