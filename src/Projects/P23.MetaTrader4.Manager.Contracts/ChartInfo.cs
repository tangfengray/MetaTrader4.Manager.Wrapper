using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents chart request
    /// </summary>
    public class ChartInfo
    {
        /// <summary>
        /// Symbol
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Period (PERIOD_*)
        /// </summary>
        public int Period { get; set; }

        /// <summary>
        /// Start of chart block
        /// </summary>
        public UInt32 Start { get; set; }

        /// <summary>
        /// End of chart block
        /// </summary>
        public UInt32 End { get; set; }

        /// <summary>
        /// Timestamp of existing chart base
        /// </summary>
        public UInt32 TimeSign { get; set; }

        /// <summary>
        /// Request mode
        /// </summary>
        public int Mode { get; set; }
    }
}
