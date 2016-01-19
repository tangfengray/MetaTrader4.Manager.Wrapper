#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::TradeCalcProfit(P23::MetaTrader4::Manager::Contracts::TradeRecord^ trade)
{
	return _manager->Manager->TradeCalcProfit(Convert(trade));	
}