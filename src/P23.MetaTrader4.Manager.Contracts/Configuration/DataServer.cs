using System;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents data server configuration
    /// </summary>
    public class DataServer
    {
        /// <summary>
        /// Server address (server:ip)
        /// </summary>
        public string Server { get; set; }

        /// <summary>
        /// Server IP
        /// </summary>
        public UInt32 Ip { get; set; }

        /// <summary>
        /// Server description
        /// </summary>
        public string Description { get; set; }

        /// <summary>
        /// Can server be proxy?
        /// </summary>
        public int IsProxy { get; set; }

        /// <summary>
        /// Priority: 0-7 base, 255-idle
        /// </summary>
        public int Priority { get; set; }

        /// <summary>
        /// Server loading (UINT_MAX-server does not inform its loading)
        /// </summary>
        public UInt32 Loading { get; set; }

        /// <summary>
        /// Internal IP address   
        /// </summary>
        public UInt32 IpInternal { get; set; }
    }
}
