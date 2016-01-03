namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents feed description
    /// </summary>
    public class FeedDescription
    {
        /// <summary>
        /// Data source version
        /// </summary>
        public int Version { get; set; }

        /// <summary>
        /// Data source name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Copyright string
        /// </summary>
        public string Copyright { get; set; }

        /// <summary>
        /// Data source web
        /// </summary>
        public string Web { get; set; }

        /// <summary>
        /// Data source email
        /// </summary>
        public string Email { get; set; }

        /// <summary>
        /// Feeder server
        /// </summary>
        public string Server { get; set; }

        /// <summary>
        /// Default feeder name
        /// </summary>
        public string UserName { get; set; }

        /// <summary>
        /// Default feeder password
        /// </summary>
        public string UserPass { get; set; }

        /// <summary>
        /// Feeder modes (enum FeederModes)
        /// </summary>
        public FeederModes Modes { get; set; }

        /// <summary>
        /// Feeder description
        /// </summary>
        public string Description { get; set; }

        /// <summary>
        /// Reserved
        /// </summary>
        public string Module { get; set; }
    }
}