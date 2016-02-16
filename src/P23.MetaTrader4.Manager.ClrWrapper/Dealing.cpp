#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::DealerSwitch(PumpingCallbackDelegate^ callBackDelegate)
{
	if (_callBackHandler.IsAllocated)
		throw gcnew MetaTrader4::Manager::Contracts::MetaTraderException("Callback handler alread allocated");

	_callBackHandler = GCHandle::Alloc(_callBackDelegate);
	return _manager->Manager->DealerSwitch((MTAPI_NOTIFY_FUNC)Marshal::GetFunctionPointerForDelegate(callBackDelegate).ToPointer(), 0, NULL);
}

P23::MetaTrader4::Manager::Contracts::RequestInfo^ P23::MetaTrader4::Manager::ClrWrapper::DealerRequestGet()
{
	RequestInfo request;
	int result = _manager->Manager->DealerRequestGet(&request);

	if (result != RET_OK)
	{
		P23::MetaTrader4::Manager::Contracts::MetaTraderException^ e = gcnew P23::MetaTrader4::Manager::Contracts::MetaTraderException();
		e->ErrorCode = result;
		throw e;
	}

	return Convert(&request);
}

int P23::MetaTrader4::Manager::ClrWrapper::DealerSend(P23::MetaTrader4::Manager::Contracts::RequestInfo^ info, int requote, int mode)
{
	return _manager->Manager->DealerSend(Convert(info), requote, mode);
}

int P23::MetaTrader4::Manager::ClrWrapper::DealerReject(int id)
{
	return _manager->Manager->DealerReject(id);
}

int P23::MetaTrader4::Manager::ClrWrapper::DealerReset(int id)
{
	return _manager->Manager->DealerReset(id);
}

IList<P23::MetaTrader4::Manager::Contracts::TickInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::TickInfoLast(String^ symbol) 
{
	int total = 0;
	TickInfo* ticks = _manager->Manager->TickInfoLast(Convert(symbol), &total);
	IList<P23::MetaTrader4::Manager::Contracts::TickInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TickInfo^>();
	for (int i = 0; i < total; i++) {
		output->Add(Convert(&ticks[i]));
	}

	_manager->Manager->MemFree(ticks);

	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::SymbolGroup^>^ P23::MetaTrader4::Manager::ClrWrapper::SymbolsGroupsGet()
{
	ConSymbolGroup configurations[MAX_SEC_GROUP];
	int result = _manager->Manager->SymbolsGroupsGet(configurations);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}

	IList<SymbolGroup^>^ output = gcnew List<SymbolGroup^>();
	for (int i = 0; i < MAX_SEC_GROUP; i++)
		output->Add(Convert(&configurations[i]));

	return output;
}

long P23::MetaTrader4::Manager::ClrWrapper::ServerTime()
{
	return _manager->Manager->ServerTime();
}

IList<P23::MetaTrader4::Manager::Contracts::MailBox^>^ P23::MetaTrader4::Manager::ClrWrapper::MailsRequest()
{
	int total = 0;
	MailBox* mails = _manager->Manager->MailsRequest(&total);
	IList<P23::MetaTrader4::Manager::Contracts::MailBox^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::MailBox^>();
	for (int i = 0; i < total; i++) {
		output->Add(Convert(&mails[i]));
	}

	_manager->Manager->MemFree(mails);

	return output;
}
