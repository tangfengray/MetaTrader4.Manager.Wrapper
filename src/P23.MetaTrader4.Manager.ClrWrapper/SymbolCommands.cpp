#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::SymbolsRefresh()
{
	return _manager->Manager->SymbolsRefresh();
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::Symbol^>^ P23::MetaTrader4::Manager::ClrWrapper::SymbolsGetAll()
{
	int total = 0;
	ConSymbol* symbols = _manager->Manager->SymbolsGetAll(&total);

	IList<P23::MetaTrader4::Manager::Contracts::Configuration::Symbol^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::Configuration::Symbol^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&symbols[i]));

	_manager->Manager->MemFree(symbols);

	return result;
}

P23::MetaTrader4::Manager::Contracts::Configuration::Symbol^ P23::MetaTrader4::Manager::ClrWrapper::SymbolGet(String^ symbol)
{
	char* s = Convert(symbol);
	ConSymbol cs;
	
	int result = _manager->Manager->SymbolGet(s, &cs);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}
	
	return Convert(&cs);
}

P23::MetaTrader4::Manager::Contracts::SymbolInfo^ P23::MetaTrader4::Manager::ClrWrapper::SymbolInfoGet(String^ symbol)
{
	char* s = Convert(symbol);
	SymbolInfo si;

	int result = _manager->Manager->SymbolInfoGet(s, &si);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&si);
}

int P23::MetaTrader4::Manager::ClrWrapper::SymbolAdd(String^ symbol)
{	
	return _manager->Manager->SymbolAdd(Convert(symbol));
}

int P23::MetaTrader4::Manager::ClrWrapper::SymbolHide(String^ symbol)
{
	return _manager->Manager->SymbolHide(Convert(symbol));
}

//--- symbol commands
int P23::MetaTrader4::Manager::ClrWrapper::SymbolSendTick(String^ symbol, double bid, double ask)
{
	return _manager->Manager->SymbolSendTick(Convert(symbol), bid, ask);
}
