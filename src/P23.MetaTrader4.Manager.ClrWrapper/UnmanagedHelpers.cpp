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

void P23::MetaTrader4::Manager::UnmanagedHelpers::SetNewsBody(NewsTopic* configuration, char* body)
{
	configuration->body = body;
}

char* P23::MetaTrader4::Manager::UnmanagedHelpers::GetNewsBody(NewsTopic* news)
{
	return news->body;
}

wchar_t* P23::MetaTrader4::Manager::UnmanagedHelpers::GetNewNewsBody(NewsTopicNew* news)
{
	return news->body;
}

char* P23::MetaTrader4::Manager::UnmanagedHelpers::GetMailBody(MailBox* mailBox)
{
	return mailBox->body;
}

#pragma warning( pop ) 