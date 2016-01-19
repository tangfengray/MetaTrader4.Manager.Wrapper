#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

void P23::MetaTrader4::Manager::ClrWrapper::LogsOut(int code, System::String^ source, System::String^ msg)
{
	if (System::String::IsNullOrEmpty(source))
		throw gcnew ArgumentNullException("source");

	if (System::String::IsNullOrEmpty(msg))
		throw gcnew ArgumentNullException("msg");
	
	_manager->Manager->LogsOut(code, Convert(source), Convert(msg));
}

void P23::MetaTrader4::Manager::ClrWrapper::LogsMode(int mode)
{
	_manager->Manager->LogsMode(mode);
}