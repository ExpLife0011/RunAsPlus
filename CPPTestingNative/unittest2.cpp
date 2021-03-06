#include "stdafx.h"
#include "CppUnitTest.h"
#include "MainLib.h"
//#include <HelpTools.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define DisplayError(a) MessageBox(NULL,a,a,NULL);
namespace CPPTestingNative
{
	TEST_CLASS(TestingTexts)
	{
	public:
		TEST_METHOD(TestBase64Encode)
		{
			std::string text = "qwedsvggr5&fafsdlol\\fddfellfrtmnbd";
			std::string enctext = ToBase64(reinterpret_cast<unsigned char const*>(text.c_str()), text.length());
			msgbx(enctext.c_str());
		}

		TEST_METHOD(compressTextTest)
		{
			std::string text = "qwedsvggr5&fafsdlol\\fddfellfrtmnbd";
			std::string comptext = CompressBoost(text);
			msgbx(comptext.c_str());
		}

		TEST_METHOD(runWithToken)
		{
			std::string fasdf = "notepad.exe";
			std::string dasf = "cmd.exe";
			RunWithToken(dasf, fasdf);


		}

		TEST_METHOD(runAsUserSharedPtr)
		{
			std::shared_ptr<Logon::ProcessRunData> data = std::make_shared<Logon::ProcessRunData>();
			data->setUser(L"user2");
			data->setPassword(L"1111");
			data->setDomain(L".");
			data->setProcessName(L"cmd.exe");
			//data->setCommandLineArgs(L"");
			data->setRunType(RunType::User);
			RunAsUserEx(data);
		}
	};
}