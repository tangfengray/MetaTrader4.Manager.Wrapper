using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents trade transaction info
    /// </summary>
    public class TradeTransInfo
    {
        /// <summary>
        /// Trade transaction type
        /// </summary>
        public byte Type { get; set; }

        /// <summary>
        ///Trade command
        /// </summary>
        public short Cmd { get; set; }

        /// <summary>
        /// Order
        /// </summary>
        public int Order { get; set; }

        /// <summary>
        /// Login, in case of closing with opposite second order ticket
        /// </summary>
        public int OrderBy { get; set; }

        /// <summary>
        /// Trade symbol
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Trade volume
        /// </summary>
        public int Volume { get; set; }

        /// <summary>
        /// Trade price(open, close), amount to deposit in case of balance operation
        /// </summary>
        public double Price { get; set; }

        /// <summary>
        /// Stop Loss
        /// </summary>
        public double Sl { get; set; }

        /// <summary>
        /// Take Profit
        /// </summary>
        public double Tp { get; set; }

        /// <summary>
        /// Deviation on IE
        /// </summary>
        public int IeDeviation { get; set; }

        /// <summary>
        /// Comment
        /// </summary>
        public string Comment { get; set; }

        /// <summary>
        /// Pending order expiration time
        /// </summary>
        public UInt32 Expiration { get; set; }

        /// <summary>
        /// Crc
        /// </summary>
        public int Crc { get; set; }
    }
}