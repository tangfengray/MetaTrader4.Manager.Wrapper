#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::TradeTransaction(P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ info)
{
	return _manager->Manager->TradeTransaction(Convert(info));
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradesRequest()
{
	int total = 0;
	TradeRecord* trades = _manager->Manager->TradesRequest(&total);
	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&trades[i]));
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradeRecordsRequest(IList<int>^ orders)
{
	int total = orders->Count;
	int* o = new int[total];
	for (int i = 0; i < total; i++)
		o[i] = orders[i];

	TradeRecord* trades = _manager->Manager->TradeRecordsRequest(o, &total);
	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&trades[i]));
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TradesUserHistory(int login, UInt32 from, UInt32 to)
{
	int total = 0;
	TradeRecord* trades = _manager->Manager->TradesUserHistory(login, from, to, &total);
	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&trades[i]));
	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::TradeCheckStops(P23::MetaTrader4::Manager::Contracts::TradeTransInfo^ trade, double price)
{
	return _manager->Manager->TradeCheckStops(Convert(trade), price);
}

