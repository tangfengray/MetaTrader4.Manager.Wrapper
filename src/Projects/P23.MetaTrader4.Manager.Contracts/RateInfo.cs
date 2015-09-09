using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents bar/candle
    /// </summary>
    public class RateInfo
    {
        /// <summary>
        /// Rate time
        /// </summary>
        public UInt32 Ctm { get; set; }

        /// <summary>
        /// Open price: 11987=119.87
        /// </summary>
        public int Open { get; set; }

        /// <summary>
        /// High shift from open
        /// </summary>
        public int High { get; set; }

        /// <summary>
        /// Low shift from open
        /// </summary>
        public int Low { get; set; }

        /// <summary>
        /// Close shift from open
        /// </summary>
        public int Close { get; set; }

        /// <summary>
        /// Volume
        /// </summary>
        public double Vol { get; set; }
    }
}
