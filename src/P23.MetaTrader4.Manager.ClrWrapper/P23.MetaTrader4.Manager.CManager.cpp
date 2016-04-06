#include "stdafx.h"

#include "P23.MetaTrader4.Manager.CManager.h"

P23::MetaTrader4::Manager::CManager::CManager(LPCSTR lib_path) : Factory(lib_path), Manager(NULL)
{
	Factory.WinsockStartup();
	if (Factory.IsValid() == FALSE || (Manager = Factory.Create(ManAPIVersion)) == NULL)
	{
		System::Diagnostics::Debug::WriteLine("Failed to create Manager");
	}
}

P23::MetaTrader4::Manager::CManager::~CManager()
{
	if (Manager != NULL) { Manager->Release(); Manager = NULL; }
	Factory.WinsockCleanup();
	Factory.~CManagerFactory();
}

bool P23::MetaTrader4::Manager::CManager::IsValid()
{
	return(Manager != NULL);
}
