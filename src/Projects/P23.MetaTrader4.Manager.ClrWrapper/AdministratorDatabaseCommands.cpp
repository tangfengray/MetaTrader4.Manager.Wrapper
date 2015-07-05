#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^  P23::MetaTrader4::Manager::ClrWrapper::AdmUsersRequest(String^ group)
{
	int total = 0;

	char* g = Convert(group);
	if (g == NULL)
		throw gcnew ArgumentException("Group is mandatory parameter");

	UserRecord* users = _manager->Manager->AdmUsersRequest(g, &total);

	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&users[i]));
	
	return result;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::AdmTradesRequest(String^ group, int openOnly)
{
	int total = 0;

	char* g = Convert(group);
	if (g == NULL)
		throw gcnew ArgumentException("Group is mandatory parameter");

	TradeRecord* trades = _manager->Manager->AdmTradesRequest(g, openOnly, &total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	for (int i = 0; i < total; i++)
		result->Add(Convert(&trades[i]));

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::AdmBalanceFix(IList<int>^ logins)
{
	int total = logins->Count;
	int* l = new int[total];
	for (int i = 0; i < total; i++)
		l[i] = logins[i];
	return _manager->Manager->AdmBalanceFix(l, total);
}

int P23::MetaTrader4::Manager::ClrWrapper::AdmTradesDelete(IList<int>^ orders)
{
	int total = orders->Count;
	int* l = new int[total];
	for (int i = 0; i < total; i++)
		l[i] = orders[i];
	return _manager->Manager->AdmTradesDelete(l, total);
}

int P23::MetaTrader4::Manager::ClrWrapper::AdmTradeRecordModify(P23::MetaTrader4::Manager::Contracts::TradeRecord^ trade)
{	
	return _manager->Manager->AdmTradeRecordModify(Convert(trade));
}

IList<P23::MetaTrader4::Manager::Contracts::BalanceDiff^>^ P23::MetaTrader4::Manager::ClrWrapper::AdmBalanceCheck(IList<int>^ logins)
{
	int total = 0;
	int* l = new int[logins->Count];
	for (int i = 0; i < logins->Count; i++)
		l[i] = logins[i];
	BalanceDiff* balanceDiff = _manager->Manager->AdmBalanceCheck(l, &total);
	IList<P23::MetaTrader4::Manager::Contracts::BalanceDiff^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::BalanceDiff^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&balanceDiff[i]));
	return output;
}