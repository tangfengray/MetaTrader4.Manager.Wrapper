#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::UsersRequest()
{
	int total = 0;
	UserRecord* users = _manager->Manager->UsersRequest(&total);
	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&users[i]));
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::UserRecordsRequest(IList<int>^ logins)
{
	int total = logins->Count;
	int* l = new int[total];
	for (int i = 0; i < logins->Count; i++)
		l[i] = logins[i];

	UserRecord* users = _manager->Manager->UserRecordsRequest(l, &total);
	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>();

	for (int i = 0; i < total; i++)
		output->Add(Convert(&users[i]));
	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::UserRecordNew(P23::MetaTrader4::Manager::Contracts::UserRecord^ user)
{
	return _manager->Manager->UserRecordNew(Convert(user));
}

int P23::MetaTrader4::Manager::ClrWrapper::UserRecordUpdate(P23::MetaTrader4::Manager::Contracts::UserRecord^ user)
{
	return _manager->Manager->UserRecordUpdate(Convert(user));
}

int P23::MetaTrader4::Manager::ClrWrapper::UsersGroupOp(P23::MetaTrader4::Manager::Contracts::GroupCommandInfo^ info, IList<int>^ logins)
{
	int* l = new int[logins->Count];
	for (int i = 0; i < logins->Count; i++)
		l[i] = logins[i];
	return _manager->Manager->UsersGroupOp(Convert(info), l);
}

int P23::MetaTrader4::Manager::ClrWrapper::UserPasswordCheck(int login, String^ password)
{
	return _manager->Manager->UserPasswordCheck(login, Convert(password));
}

int P23::MetaTrader4::Manager::ClrWrapper::UserPasswordSet(int login, String^ password, int changeInvestor, int cleanPubKey)
{
	return _manager->Manager->UserPasswordSet(login, Convert(password), changeInvestor, cleanPubKey);
}

IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::OnlineRequest()
{
	int total = 0;
	OnlineRecord* users = _manager->Manager->OnlineRequest(&total);
	IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&users[i]));
	return output;
}
