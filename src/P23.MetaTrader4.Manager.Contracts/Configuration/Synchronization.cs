using System;
using P23.MetaTrader4.Manager.Contracts.Configuration.Enums;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents synchronization configuration
    /// </summary>
    public class Synchronization
    {
        /// <summary>
        /// Name (address)
        /// </summary>
        public string Server { get; set; }

        /// <summary>
        /// Port
        /// </summary>
        public int UnusedPort { get; set; }

        /// <summary>
        /// For future use-login
        /// </summary>
        public string Login { get; set; }

        /// <summary>
        /// For future use=password
        /// </summary>
        public string Password { get; set; }

        /// <summary>
        /// Enable sychronization
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Synchronization mode: HB_ADD,HB_UPDATE,HB_INSERT
        /// </summary>
        public SynchronizationMode Mode { get; set; }

        /// <summary>
        /// Synchronization range (0-whole chart)
        /// </summary>
        public UInt32 From { get; set; }

        /// <summary>
        /// Synchronization range (0-whole chart)
        /// </summary>
        public UInt32 To { get; set; }

        /// <summary>
        /// Symbols list
        /// </summary>
        public string Securities { get; set; }
    }
}
