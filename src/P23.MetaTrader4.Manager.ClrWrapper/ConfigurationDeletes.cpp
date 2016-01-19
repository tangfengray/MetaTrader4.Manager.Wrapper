#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteAccess(int position)
{
	return _manager->Manager->CfgDeleteAccess(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteDataServer(int position)
{
	return _manager->Manager->CfgDeleteDataServer(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteHoliday(int position)
{
	return _manager->Manager->CfgDeleteHoliday(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteSymbol(int position)
{
	return _manager->Manager->CfgDeleteSymbol(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteGroup(int position)
{
	return _manager->Manager->CfgDeleteGroup(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteManager(int position)
{
	return _manager->Manager->CfgDeleteManager(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteFeeder(int position)
{
	return _manager->Manager->CfgDeleteFeeder(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteLiveUpdate(int position)
{
	return _manager->Manager->CfgDeleteLiveUpdate(position);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgDeleteSync(int position)
{
	return _manager->Manager->CfgDeleteSync(position);
}
