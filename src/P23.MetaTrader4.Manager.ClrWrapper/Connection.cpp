#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::Connect(System::String^ server)
{
	char* cServer = Convert(server);
	if (cServer == NULL)
		throw gcnew ArgumentException("Server missing", "server");
	return _manager->Manager->Connect(cServer);
}

int P23::MetaTrader4::Manager::ClrWrapper::Disconnect()
{
	return _manager->Manager->Disconnect();
}

int P23::MetaTrader4::Manager::ClrWrapper::IsConnected()
{
	return _manager->Manager->IsConnected();
}

int P23::MetaTrader4::Manager::ClrWrapper::Login(int login, System::String^ password)
{	
	char* cPassword = Convert(password);
	if (cPassword == NULL)
		throw gcnew ArgumentException("Password is required");
	return _manager->Manager->Login(login, cPassword);		
}

int P23::MetaTrader4::Manager::ClrWrapper::LoginSecured(System::String^ keyPath)
{
	char* cKeyPath = Convert(keyPath);
	if (cKeyPath == NULL)
		throw gcnew ArgumentException("keyPath is required");
	return _manager->Manager->LoginSecured(cKeyPath);
}

int P23::MetaTrader4::Manager::ClrWrapper::KeysSend(System::String^ keyPath)
{
	char* cKeyPath = Convert(keyPath);
	if (cKeyPath == NULL)
		throw gcnew ArgumentException("keyPath is required");
	return _manager->Manager->KeysSend(cKeyPath);
}

int P23::MetaTrader4::Manager::ClrWrapper::Ping()
{
	return _manager->Manager->Ping();
}

int P23::MetaTrader4::Manager::ClrWrapper::PasswordChange(System::String^ password, int isInvestor)
{
	char* cPassword = Convert(password);
	if (cPassword == NULL)
		throw gcnew ArgumentException("password is required");
	return _manager->Manager->PasswordChange(cPassword, isInvestor);
}

int P23::MetaTrader4::Manager::ClrWrapper::ManagerRights(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ manager)
{
	return _manager->Manager->ManagerRights(Convert(manager));
}