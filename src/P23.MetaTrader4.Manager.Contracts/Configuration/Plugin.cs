namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents plugin configuration
    /// </summary>
    public class Plugin
    {
        /// <summary>
        /// Plugin file name
        /// </summary>
        public string File { get; set; }

        /// <summary>
        /// Plugin description
        /// </summary>
        public PluginInformation Info { get; set; }

        /// <summary>
        /// Plugin enabled/disabled
        /// </summary>
        public int Enabled { get; set; }

        /// <summary>
        /// Is plugin configurable
        /// </summary>
        public int Configurable { get; set; }

        /// <summary>
        /// Plugin can be accessed from manager terminal
        /// </summary>
        public int ManagerAccess { get; set; }
    }
}