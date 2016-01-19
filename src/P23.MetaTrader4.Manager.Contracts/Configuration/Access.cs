using System;
using P23.MetaTrader4.Manager.Contracts.Configuration.Enums;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents access configuration
    /// </summary>
    public class Access
    {
        /// <summary>
        /// Type of action (FW_BLOCK,FW_PERMIT)
        /// </summary>
        public AccessActionType Action { get; set; }

        /// <summary>
        /// From addresses
        /// </summary>
        public UInt32 From { get; set; }

        /// <summary>
        /// To addresses
        /// </summary>
        public UInt32 To { get; set; }

        /// <summary>
        /// Comment
        /// </summary>
        public string Comment { get; set; }
    }
}
