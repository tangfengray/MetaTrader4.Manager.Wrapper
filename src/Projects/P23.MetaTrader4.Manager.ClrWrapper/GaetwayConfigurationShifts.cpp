#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftGatewayAccount(int position, int shift)
{
	return _manager->Manager->CfgShiftGatewayAccount(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftGatewayMarkup(int position, int shift)
{
	return _manager->Manager->CfgShiftGatewayMarkup(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftGatewayRule(int position, int shift)
{
	return _manager->Manager->CfgShiftGatewayRule(position, shift);
}