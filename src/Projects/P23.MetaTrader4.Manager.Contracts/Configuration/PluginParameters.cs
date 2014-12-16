using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class PluginInfo
    {
        string Name { get; set; }                    // plugin name
        UInt32 Version { get; set; }                 // plugin version
        string Copyright { get; set; }               // plugin copyright

    }

    public class PluginConfigurationParameter
    {
        string Name { get; set; }                     // parameter name
        string Value { get; set; }                    // parameter value

    }

    public class Plugin
    {
        string File { get; set; }                     // plugin file name
        PluginInfo Info { get; set; }                 // plugin description
        int Enabled { get; set; }                     // plugin enabled/disabled
        int Configurable { get; set; }                // is plugin configurable
        int ManagerAccess { get; set; }               // plugin can be accessed from manager terminal
    }

    public class PluginWithParameters
    {
        Plugin Plugin { get; set; }                    // plugin configuration
        IList<PluginConfigurationParameter> Parameters { get; set; } // plugin parameters
        int Total { get; set; }                        // total plugin parameters
    };
}
