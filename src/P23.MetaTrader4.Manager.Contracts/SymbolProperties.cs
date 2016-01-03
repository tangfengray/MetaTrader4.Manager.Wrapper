using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents symbol properties
    /// </summary>
    public class SymbolProperties
    {
        /// <summary>
        /// Symbol
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Symbol color
        /// </summary>
        public UInt32 Color { get; set; }

        /// <summary>
        /// Symbol spread
        /// </summary>
        public int Spread { get; set; }

        /// <summary>
        /// Spread balance
        /// </summary>
        public int SpreadBalance { get; set; }

        /// <summary>
        /// Stops level
        /// </summary>
        public int StopsLevel { get; set; }

        /// <summary>
        /// Smoothing
        /// </summary>
        public int Smoothing { get; set; }

        /// <summary>
        /// Execution mode
        /// </summary>
        public int Exemode { get; set; }
    }
}