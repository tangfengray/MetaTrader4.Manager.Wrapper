#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"


IList<P23::MetaTrader4::Manager::Contracts::SymbolSummary^>^ P23::MetaTrader4::Manager::ClrWrapper::SummaryGetAll()
{
	int total = 0;
	SymbolSummary* s = _manager->Manager->SummaryGetAll(&total);

	IList<P23::MetaTrader4::Manager::Contracts::SymbolSummary^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::SymbolSummary^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&s[i]));

	_manager->Manager->MemFree(s);

	return output;
}

P23::MetaTrader4::Manager::Contracts::SymbolSummary^ P23::MetaTrader4::Manager::ClrWrapper::SummaryGet(String^ symbol)
{
	SymbolSummary s;
	int result = _manager->Manager->SummaryGet(Convert(symbol), &s);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}
	return Convert(&s);
}

P23::MetaTrader4::Manager::Contracts::SymbolSummary^ P23::MetaTrader4::Manager::ClrWrapper::SummaryGetByCount(int symbol)
{
	SymbolSummary s;
	int result = _manager->Manager->SummaryGetByCount(symbol, &s);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}
	return Convert(&s);
}

P23::MetaTrader4::Manager::Contracts::SymbolSummary^ P23::MetaTrader4::Manager::ClrWrapper::SummaryGetByType(int sectype)
{
	SymbolSummary s;
	int result = _manager->Manager->SummaryGetByCount(sectype, &s);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}
	return Convert(&s);
}

int P23::MetaTrader4::Manager::ClrWrapper::SummaryCurrency(String^ cur, int maxchars)
{
	return _manager->Manager->SummaryCurrency(Convert(cur), maxchars);
}

IList<P23::MetaTrader4::Manager::Contracts::ExposureValue^>^ P23::MetaTrader4::Manager::ClrWrapper::ExposureGet()
{
	int total = 0;
	ExposureValue* s = _manager->Manager->ExposureGet(&total);

	IList<P23::MetaTrader4::Manager::Contracts::ExposureValue^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::ExposureValue^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&s[i]));

	_manager->Manager->MemFree(s);

	return output;
}

P23::MetaTrader4::Manager::Contracts::ExposureValue^ P23::MetaTrader4::Manager::ClrWrapper::ExposureValueGet(String^ cur)
{
	ExposureValue s;
	int result = _manager->Manager->ExposureValueGet(Convert(cur), &s);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}
	return Convert(&s);
}

P23::MetaTrader4::Manager::Contracts::MarginLevel^ P23::MetaTrader4::Manager::ClrWrapper::MarginLevelRequest(int login)
{
	MarginLevel m;
	int result = _manager->Manager->MarginLevelRequest(login, &m);
	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}
	return Convert(&m);
}

int P23::MetaTrader4::Manager::ClrWrapper::HistoryCorrect(String^ symbol, int updated)
{
	return _manager->Manager->HistoryCorrect(Convert(symbol), &updated);
}
