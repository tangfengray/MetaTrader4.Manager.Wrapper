#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::SymbolChange(P23::MetaTrader4::Manager::Contracts::SymbolProperties^ symbolProperties)
{
	return _manager->Manager->SymbolChange(Convert(symbolProperties));
}