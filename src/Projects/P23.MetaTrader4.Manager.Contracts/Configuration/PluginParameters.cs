using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class PluginInformation
    {
        public string Name { get; set; }                    // plugin name
        public UInt32 Version { get; set; }                 // plugin version
        public string Copyright { get; set; }               // plugin copyright

    }

    public class PluginConfigurationParameter
    {
        public string Name { get; set; }                     // parameter name
        public string Value { get; set; }                    // parameter value

    }

    public class Plugin
    {
        public string File { get; set; }                     // plugin file name
        public PluginInformation Info { get; set; }          // plugin description
        public int Enabled { get; set; }                     // plugin enabled/disabled
        public int Configurable { get; set; }                // is plugin configurable
        public int ManagerAccess { get; set; }               // plugin can be accessed from manager terminal
    }

    public class PluginWithParameters
    {
        public Plugin Plugin { get; set; }                    // plugin configuration
        public IList<PluginConfigurationParameter> Parameters { get; set; } // plugin parameters
        //public int Total { get; set; }                        // total plugin parameters
    };
}
