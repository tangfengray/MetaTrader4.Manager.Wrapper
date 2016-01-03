#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftAccess(int position, int shift)
{
	return _manager->Manager->CfgShiftAccess(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftDataServer(int position, int shift)
{
	return _manager->Manager->CfgShiftDataServer(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftHoliday(int position, int shift)
{
	return _manager->Manager->CfgShiftHoliday(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftSymbol(int position, int shift)
{
	return _manager->Manager->CfgShiftSymbol(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftGroup(int position, int shift)
{
	return _manager->Manager->CfgShiftGroup(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftManager(int position, int shift)
{
	return _manager->Manager->CfgShiftManager(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftFeeder(int position, int shift)
{
	return _manager->Manager->CfgShiftFeeder(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftLiveUpdate(int position, int shift)
{
	return _manager->Manager->CfgShiftLiveUpdate(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftSync(int position, int shift)
{
	return _manager->Manager->CfgShiftSync(position, shift);
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgShiftPlugin(int position, int shift)
{
	return _manager->Manager->CfgShiftPlugin(position, shift);
}
