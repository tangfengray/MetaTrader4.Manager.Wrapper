using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents symbol info
    /// </summary>
    public class SymbolInfo
    {
        /// <summary>
        /// Symbol name
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Floating point digits
        /// </summary>
        public int Digits { get; set; }

        /// <summary>
        /// Symbol counter
        /// </summary>
        public int Count { get; set; }

        /// <summary>
        /// Visibility
        /// </summary>
        public int Visible { get; set; }

        /// <summary>
        /// Symbol type (symbols group index)
        /// </summary>
        public int Type { get; set; }

        /// <summary>
        /// Symbol point=1/pow(10,digits)
        /// </summary>
        public double Point { get; set; }

        /// <summary>
        /// Symbol spread
        /// </summary>
        public int Spread { get; set; }

        /// <summary>
        /// Spread balance
        /// </summary>
        public int SpreadBalance { get; set; }

        /// <summary>
        /// Direction
        /// </summary>
        public SymbolPriceDirection Direction { get; set; }

        /// <summary>
        /// Update flag
        /// </summary>
        public int UpdateFlag { get; set; }

        /// <summary>
        /// Last tick time
        /// </summary>
        public UInt32 LastTime { get; set; }

        /// <summary>
        /// Bid
        /// </summary>
        public double Bid { get; set; }

        /// <summary>
        /// Ask
        /// </summary>
        public double Ask { get; set; }

        /// <summary>
        /// High
        /// </summary>
        public double High { get; set; }

        /// <summary>
        /// Low
        /// </summary>
        public double Low { get; set; }

        /// <summary>
        /// Commission
        /// </summary>
        public double Commission { get; set; }

        /// <summary>
        /// Commission type  
        /// </summary>
        public int CommType { get; set; }
    }
}
