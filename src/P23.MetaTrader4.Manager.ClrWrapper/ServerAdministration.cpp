#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::SrvRestart()
{
	return _manager->Manager->SrvRestart();
}

int P23::MetaTrader4::Manager::ClrWrapper::SrvChartsSync()
{
	return _manager->Manager->SrvChartsSync();
}

int P23::MetaTrader4::Manager::ClrWrapper::SrvLiveUpdateStart()
{
	return _manager->Manager->SrvLiveUpdateStart();
}

int P23::MetaTrader4::Manager::ClrWrapper::SrvFeedsRestart()
{
	return _manager->Manager->SrvFeedsRestart();
}