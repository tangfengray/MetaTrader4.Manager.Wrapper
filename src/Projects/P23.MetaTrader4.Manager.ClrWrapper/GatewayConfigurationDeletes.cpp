#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteGatewayAccount(int position)
{
	return _manager->Manager->CfgDeleteGatewayAccount(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteGatewayMarkup(int position)
{
	return _manager->Manager->CfgDeleteGatewayMarkup(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteGatewayRule(int position)
{
	return _manager->Manager->CfgDeleteGatewayRule(position);
}