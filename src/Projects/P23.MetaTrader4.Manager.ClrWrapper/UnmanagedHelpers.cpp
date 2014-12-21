#include "stdafx.h"

#include "UnmanagedHelpers.h"

#pragma warning( push )
#pragma warning( disable : 4793 )
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
#pragma warning( pop ) 