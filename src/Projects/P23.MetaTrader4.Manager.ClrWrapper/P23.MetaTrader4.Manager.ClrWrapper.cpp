// This is the main DLL file.

#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

#define COPY_STR(dst,src)  { strncpy_s(dst,src,sizeof(dst)-1); dst[sizeof(dst)-1]=0; }

P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters)
{
	_manager = new CManager();
	char* server = (char*)Marshal::StringToHGlobalAnsi(connectionParameters->Server).ToPointer();
	char* password = (char*)Marshal::StringToHGlobalAnsi(connectionParameters->Password).ToPointer();
	
	if (server == NULL)
		throw gcnew ArgumentException("Server is required");
	if (password == NULL)
		throw gcnew ArgumentException("Password is required");
	
	if (_manager == NULL)
		throw gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException("Failed to instantiate manager instance");
	if (_manager->Manager == NULL)
		throw gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException("Failed to instantiate manager instance");
	if (_manager->Manager->IsConnected() != TRUE)
	{	
		int connectionResult = _manager->Manager->Connect(server);
		if (connectionResult != RET_OK)
			throw gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException("Failed to connect to server");

		int res = _manager->Manager->Login(connectionParameters->Login, password);
		if (res != RET_OK) 
			throw gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException("Failed to login to server");
	}
}