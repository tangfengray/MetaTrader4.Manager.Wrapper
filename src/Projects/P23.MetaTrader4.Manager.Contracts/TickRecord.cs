using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents tick record
    /// </summary>
    public class TickRecord
    {
        /// <summary>
        /// Tick time
        /// </summary>
        public UInt32 Ctm { get; set; }

        /// <summary>
        /// Bid
        /// </summary>
        public double Bid { get; set; }

        /// <summary>
        /// Ask
        /// </summary>
        public double Ask { get; set; }

        /// <summary>
        /// Index if datafeed
        /// </summary>
        public int DataFeed { get; set; }

        /// <summary>
        /// TICK_FLAG_* flags
        /// </summary>
        public char Flags { get; set; }
    }
}
