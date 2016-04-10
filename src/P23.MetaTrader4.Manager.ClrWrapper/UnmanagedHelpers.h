#include "MT4ManagerAPI.h"
namespace P23{
	namespace MetaTrader4{
		namespace Manager
		{
			class UnmanagedHelpers
			{
			public:
				static void SetMailBody(MailBox* mailBox, char* body);
				static PluginCfg GetPluginParameters(ConPluginParam* configuration, int index);
				static void AssignPluginParameters(ConPluginParam* configuration, PluginCfg parameter, int index);
				static void SetNewsBody(NewsTopic* news, char* body);				
				static char* GetNewsBody(NewsTopic* news);
				static wchar_t* GetNewNewsBody(NewsTopicNew* news);
				static char* GetMailBody(MailBox* mailBox);
			};
		}
	}
}