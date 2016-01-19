using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents connection parameters
    /// </summary>
    public class ConnectionParameters
    {
        /// <summary>
        /// Login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// Server (ip:port)
        /// </summary>
        public String Server { get; set; }

        /// <summary>
        /// Password
        /// </summary>
        public String Password { get; set; }
    }
}