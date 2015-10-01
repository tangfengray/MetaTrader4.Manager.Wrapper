using System;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents plugin information configuration
    /// </summary>
    public class PluginInformation
    {
        /// <summary>
        /// Plugin name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Plugin version
        /// </summary>
        public UInt32 Version { get; set; }

        /// <summary>
        /// Plugin copyright
        /// </summary>
        public string Copyright { get; set; }
    }
}