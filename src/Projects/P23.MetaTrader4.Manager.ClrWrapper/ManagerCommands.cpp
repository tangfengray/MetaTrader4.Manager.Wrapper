#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>^ P23::MetaTrader4::Manager::ClrWrapper::GroupsRequest()
{
	int total = 0;
	ConGroup* groups = _manager->Manager->GroupsRequest(&total);

	IList<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>^ result = gcnew List<P23::MetaTrader4::Manager::Contracts::Configuration::Group^>();

	for (int i = 0; i < total; i++)
		result->Add(Convert(&groups[i]));

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::MailSend(P23::MetaTrader4::Manager::Contracts::MailBox^ mail, IList<int>^ logins)
{
	int* l = new int[logins->Count];
	for (int i = 0; i < logins->Count; i++)
		l[i] = logins[i];
	return _manager->Manager->MailSend(Convert(mail), l);
}


int P23::MetaTrader4::Manager::ClrWrapper::NewsSend(P23::MetaTrader4::Manager::Contracts::NewsTopic^ news)
{
	return _manager->Manager->NewsSend(Convert(news));
}

