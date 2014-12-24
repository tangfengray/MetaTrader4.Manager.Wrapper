#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::BackupInfoUsers(int mode)
{
	IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::BackupInfo^>();
	int total = 0;
	BackupInfo* result = _manager->Manager->BackupInfoUsers(mode, &total);
	for (int i = 0; i < total; i++)	
		output->Add(Convert(&result[i]));
	
	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^  P23::MetaTrader4::Manager::ClrWrapper::BackupInfoOrders(int mode)
{

	IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::BackupInfo^>();
	int total = 0;
	BackupInfo* result = _manager->Manager->BackupInfoOrders(mode, &total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^  P23::MetaTrader4::Manager::ClrWrapper::BackupRequestUsers(String^ file, String^ request)
{
	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>();
	int total = 0;
	
	char* f = Convert(file);
	char* r = Convert(request);
	if (f == NULL || r == NULL)
		throw gcnew ArgumentException("File and request mandatory parameters");
	
	UserRecord* result = _manager->Manager->BackupRequestUsers(f, r, &total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::BackupRequestOrders(String^ file, String^ request)
{
	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>();
	int total = 0;

	char* f = Convert(file);
	char* r = Convert(request);
	if (f == NULL || r == NULL)
		throw gcnew ArgumentException("File and request mandatory parameters");

	TradeRecord* result = _manager->Manager->BackupRequestOrders(f, r, &total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::BackupRestoreUsers(IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ users)
{
	int total = 0;

	UserRecord* u = new UserRecord[users->Count];
	for (int i = 0; i < users->Count; i++)
		u[i] = *Convert(users[i]);

	int result = _manager->Manager->BackupRestoreUsers(u, total);

	return result;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^>^ P23::MetaTrader4::Manager::ClrWrapper::BackupRestoreOrders(IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ trades)
{
	int total = trades->Count;

	TradeRecord* t = new TradeRecord[total];
	for (int i = 0; i < total; i++)
		t[i] = *Convert(trades[i]);

	TradeRestoreResult* result = _manager->Manager->BackupRestoreOrders(t, &total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^>();
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	return output;
}