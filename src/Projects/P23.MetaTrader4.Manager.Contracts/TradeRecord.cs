using System;
using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents trade record
    /// </summary>
    public class TradeRecord
    {
        /// <summary>
        /// Order ticket
        /// </summary>
        public int Order { get; set; }

        /// <summary>
        /// Owner's login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// Security
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Security precision
        /// </summary>
        public int Digits { get; set; }

        /// <summary>
        /// Trade command
        /// </summary>
        public int Cmd { get; set; }

        /// <summary>
        /// Volume
        /// </summary>
        public int Volume { get; set; }

        /// <summary>
        /// Open time
        /// </summary>
        public UInt32 OpenTime { get; set; }

        /// <summary>
        /// Reserved
        /// </summary>
        public int State { get; set; }

        /// <summary>
        /// Open price
        /// </summary>
        public double OpenPrice { get; set; }

        /// <summary>
        /// Stop loss
        /// </summary>
        public double Sl { get; set; }

        /// <summary>
        /// Take profit
        /// </summary>
        public double Tp { get; set; }

        /// <summary>
        /// Close time
        /// </summary>
        public UInt32 CloseTime { get; set; }

        /// <summary>
        /// Gateway order volume
        /// </summary>
        public int GwVolume { get; set; }

        /// <summary>
        /// Pending order's expiration time
        /// </summary>
        public UInt32 Expiration { get; set; }

        /// <summary>
        /// Trade reason
        /// </summary>
        public char Reason { get; set; }

        /// <summary>
        /// Convertation rates from profit currency to group deposit currency
        /// (first element-for open time, second element-for close time)
        /// </summary>
        public IList<double> ConvRates { get; set; }

        /// <summary>
        /// Commission
        /// </summary>
        public double Commission { get; set; }

        /// <summary>
        /// Agent commission
        /// </summary>
        public double CommissionAgent { get; set; }

        /// <summary>
        /// Order swaps
        /// </summary>
        public double Storage { get; set; }

        /// <summary>
        /// Close price
        /// </summary>
        public double ClosePrice { get; set; }

        /// <summary>
        /// Profit
        /// </summary>
        public double Profit { get; set; }

        /// <summary>
        /// Taxes
        /// </summary>
        public double Taxes { get; set; }

        /// <summary>
        /// Special value used by client experts
        /// </summary>
        public int Magic { get; set; }

        /// <summary>
        /// Comment
        /// </summary>
        public string Comment { get; set; }

        /// <summary>
        /// Gateway order ticket
        /// </summary>
        public int GwOrder { get; set; }

        /// <summary>
        /// used by MT Manager
        /// </summary>
        public int Activation { get; set; }

        /// <summary>
        /// Gateway order price deviation (pips) from order open price
        /// </summary>
        public short GwOpenPrice { get; set; }

        /// <summary>
        /// Gateway order price deviation (pips) from order close price
        /// </summary>
        public short GwClosePrice { get; set; }

        /// <summary>
        /// Margin convertation rate (rate of convertation from margin currency to deposit one)
        /// </summary>
        public double MarginRate { get; set; }

        /// <summary>
        /// Timestamp when traderecord was requested
        /// </summary>
        public UInt32 Timestamp { get; set; }
    }
}
