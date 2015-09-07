using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents gateway account configuration
    /// </summary>
    public class GatewayAccount
    {
        /// <summary>
        /// Enable flag 0 - disabled, 1 - enabled
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Public name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Internal id
        /// </summary>
        public int ID { get; set; }

        /// <summary>
        /// Type (obsolete)
        /// </summary>
        public int Type { get; set; }

        /// <summary>
        /// STP MT4 login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// MT4 server address
        /// </summary>
        public string Address { get; set; }

        /// <summary>
        /// STP MT4 password
        /// </summary>
        public string Password { get; set; }

        /// <summary>
        /// List of logins for internal email notification
        /// </summary>
        public List<int> NotifyLogins { get; set; }

        /// <summary>
        /// Flag fields
        /// </summary>
        public int Flags { get; set; }
    }
}
