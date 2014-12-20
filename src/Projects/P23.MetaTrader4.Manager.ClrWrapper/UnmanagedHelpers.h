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

			};
		}
	}
}