// MainLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MainLib.h"
#include "ProcessRunData.h"
#include "LogonTools.h"

externC NATIVEFUNC bool Cdecl LogInAsUser(MyMap mymap)
{
	try
	{
		std::shared_ptr<Logon::ProcessRunData> data{};
		data->setUser(const_cast<LPWSTR>(mymap.left.find(PData::user)->second.c_str()));
		//std::wstring ff = 
		data->setDomain(const_cast<LPWSTR>(mymap.left.find(PData::domain)->second.c_str()));
		data->setPassword(const_cast<LPWSTR>(mymap.left.find(PData::password)->second.c_str()));
		data->setProcessName(const_cast<LPWSTR>(mymap.left.find(PData::processName)->second.c_str()));
		data->setCommandLineArgs(const_cast<LPWSTR>(mymap.left.find(PData::commandLineArgs)->second.c_str()));
		//data->setRunType(_cast<LPWSTR>())
		std::wstring::size_type sz;
		int tmp = std::stoi(mymap.left.find(PData::type)->second, &sz);
		RunType type = static_cast<RunType>(tmp);
		data->setRunType(type);
		std::shared_ptr<Logon::LogonTools> logon_tools{};
		logon_tools->RunProcessAsUser(&*data);
		return true;
	} catch (...)
	{
		return false;
	}
}

externC NATIVEFUNC void Cdecl MsgBx(LPCWSTR str)
/*
 *
 */

try
{
	Logon::LogonTools *helper = new Logon::LogonTools();
	helper->MsgBx(str);
} catch(...)
{

} 

#ifdef __cplusplus
NATIVEFUNC void RunAsUser(Logon::ProcessRunDataW *data)
{
	Logon::LogonTools *logon_tools = new Logon::LogonTools();
	//msgbxw(data->getProcessName());
	logon_tools->RunProcessAsUser(std::move(data));
}
#endif
