#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::BytesSent()
{
	return _manager->Manager->BytesSent();
}

int P23::MetaTrader4::Manager::ClrWrapper::BytesReceived()
{
	return _manager->Manager->BytesReceived();
}