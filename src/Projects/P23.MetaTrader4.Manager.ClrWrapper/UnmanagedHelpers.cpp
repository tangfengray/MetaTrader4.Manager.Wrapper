#include "stdafx.h"

#include "UnmanagedHelpers.h"

void P23::MetaTrader4::Manager::UnmanagedHelpers::SetMailBody(MailBox* mailBox, char* body)
{
	mailBox->body = body;
}

PluginCfg P23::MetaTrader4::Manager::UnmanagedHelpers::GetPluginParameters(ConPluginParam* configuration, int index)
{
	return configuration->params[index];
}

void P23::MetaTrader4::Manager::UnmanagedHelpers::AssignPluginParameters(ConPluginParam* configuration, PluginCfg parameter, int index)
{
	configuration->params[index] = parameter;
}