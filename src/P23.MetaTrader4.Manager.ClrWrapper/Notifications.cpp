#include "stdafx.h"
#include <vcclr.h>

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::NotificationsSend(String^ metaquotesIds, String^ message)
{
	if(String::IsNullOrEmpty(message))
		throw gcnew ArgumentNullException("message is mandatory parameter");

	if (String::IsNullOrEmpty(metaquotesIds))
		throw gcnew ArgumentNullException("metaquotesIds is mandatory parameter");

	return _manager->Manager->NotificationsSend(ConvertToLPWSTR(metaquotesIds), ConvertToLPCWSTR(message));
}

int P23::MetaTrader4::Manager::ClrWrapper::NotificationsSend(List<int>^ logins, String^ message)
{
	if (String::IsNullOrEmpty(message))
		throw gcnew ArgumentNullException("message is mandatory parameter");

	if(logins == nullptr || logins->Count == 0)
		throw gcnew ArgumentNullException("logins is mandatory parameter");

	UINT total = logins->Count;
	int* l = new int[total];
	for (int i = 0; i < logins->Count; i++)
		l[i] = logins[i];

	return _manager->Manager->NotificationsSend(l, total, ConvertToLPCWSTR(message));
}