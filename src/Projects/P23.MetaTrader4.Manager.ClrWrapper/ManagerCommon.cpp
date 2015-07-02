#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::ManagerCommon(Common^ common)
{
	return _manager->Manager->ManagerCommon(Convert(common));
}