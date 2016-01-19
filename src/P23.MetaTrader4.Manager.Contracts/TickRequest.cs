using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents tick request
    /// </summary>
    public class TickRequest
    {
        /// <summary>
        /// Symbol
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Start of period
        /// </summary>
        public UInt32 From { get; set; }

        /// <summary>
        /// End of period
        /// </summary>
        public UInt32 To { get; set; }

        /// <summary>
        /// TICK_FLAG_* Flags
        /// </summary>
        public char Flags { get; set; }
    }
}
