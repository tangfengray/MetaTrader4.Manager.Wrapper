using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents online record
    /// </summary>
    public class OnlineRecord
    {
        /// <summary>
        /// Connections counter
        /// </summary>
        public int Counter { get; set; }

        /// <summary>
        /// User login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// Connection ip address
        /// </summary>
        public UInt32 Ip { get; set; }

        /// <summary>
        /// User group
        /// </summary>
        public string Group { get; set; }
    }
}
