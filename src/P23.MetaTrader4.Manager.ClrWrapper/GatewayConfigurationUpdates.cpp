#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGatewayAccount(GatewayAccount^ cfg)
{
	return _manager->Manager->CfgUpdateGatewayAccount(Convert(cfg));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGatewayMarkup(GatewayMarkup^ cfg)
{
	return _manager->Manager->CfgUpdateGatewayMarkup(Convert(cfg));
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGatewayRule(GatewayRule^ cfg)
{
	return _manager->Manager->CfgUpdateGatewayRule(Convert(cfg));
}