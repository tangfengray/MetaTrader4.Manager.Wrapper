// This is the main DLL file.

#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

#define COPY_STR(dst,src)  { strncpy_s(dst,src,sizeof(dst)-1); dst[sizeof(dst)-1]=0; }

P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper() :P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper((String^)nullptr)
{
	
}

P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper(String^ metatraderLibraryPath)
{
	char* path = Convert(metatraderLibraryPath);
	_manager = new CManager(path);
	if (_manager == NULL)
		throw gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException("Failed to instantiate manager instance");
	if (_manager->Manager == NULL)
		throw gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException("Failed to instantiate manager instance");
}

P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters, String^ metatraderLibraryPath) : P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper(metatraderLibraryPath)
{
	char* server = Convert(connectionParameters->Server);
	char* password = Convert(connectionParameters->Password);

	if (server == NULL)
		throw gcnew ArgumentException("Server is required");
	if (password == NULL)
		throw gcnew ArgumentException("Password is required");

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

P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper(P23::MetaTrader4::Manager::Contracts::ConnectionParameters^ connectionParameters) : P23::MetaTrader4::Manager::ClrWrapper::ClrWrapper(connectionParameters, nullptr)
{	
	
}

System::String^ P23::MetaTrader4::Manager::ClrWrapper::ErrorDescription(int code){
	LPCSTR description = _manager->Manager->ErrorDescription(code);
	return gcnew System::String(description);
}

P23::MetaTrader4::Manager::ClrWrapper::~ClrWrapper()
{
	if (_isDisposed)
		return;
		
	this->!ClrWrapper(); // call finalizer
	_isDisposed = true;
}

P23::MetaTrader4::Manager::ClrWrapper::!ClrWrapper()
{
	if (_callBackHandler.IsAllocated)
		_callBackHandler.Free();

	if (_manager->Manager->IsConnected())
		_manager->Manager->Disconnect();
	_manager->~CManager();
	_manager = NULL;
}