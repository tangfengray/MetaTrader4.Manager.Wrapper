#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::Configuration::GatewayAccount^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGatewayAccount()
{
	IList<GatewayAccount^>^ configurations = gcnew List<GatewayAccount^>();
	int total = 0;
	ConGatewayAccount* result = _manager->Manager->CfgRequestGatewayAccount(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::GatewayMarkup^>^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGatewayMarkup()
{
	IList<GatewayMarkup^>^ configurations = gcnew List<GatewayMarkup^>();
	int total = 0;
	ConGatewayMarkup* result = _manager->Manager->CfgRequestGatewayMarkup(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::GatewayRule^>^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGatewayRule()
{
	IList<GatewayRule^>^ configurations = gcnew List<GatewayRule^>();
	int total = 0;
	ConGatewayRule* result = _manager->Manager->CfgRequestGatewayRule(&total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}