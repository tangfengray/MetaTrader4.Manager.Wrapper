using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents plugin with parameters configuration
    /// </summary>
    public class PluginWithParameters
    {
        /// <summary>
        /// Plugin configuration
        /// </summary>
        public Plugin Plugin { get; set; }

        /// <summary>
        /// Plugin parameters
        /// </summary>
        public IList<PluginConfigurationParameter> Parameters { get; set; }
    };
}