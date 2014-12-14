#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::PumpingSwitch(PumpingCallbackDelegate^ callBackDelegate)
{	
	if (_callBackHandler.IsAllocated)
		_callBackHandler.Free();

	_callBackHandler = GCHandle::Alloc(_callBackDelegate);
	return _manager->Manager->PumpingSwitchEx((MTAPI_NOTIFY_FUNC_EX)Marshal::GetFunctionPointerForDelegate(callBackDelegate).ToPointer(), 0, NULL);
}