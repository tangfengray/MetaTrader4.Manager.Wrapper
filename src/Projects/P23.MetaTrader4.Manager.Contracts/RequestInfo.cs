using System;
using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents request info
    /// </summary>
    public class RequestInfo
    {
        /// <summary>
        /// Request id
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// Request status
        /// </summary>
        public char Status { get; set; }

        /// <summary>
        /// Request time
        /// </summary>
        public UInt32 Time { get; set; }

        /// <summary>
        /// Manager processing request (if any)
        /// </summary>
        public int Manager { get; set; }

        /// <summary>
        /// User login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// User group
        /// </summary>
        public string Group { get; set; }

        /// <summary>
        /// User balance
        /// </summary>
        public double Balance { get; set; }

        /// <summary>
        /// User credit
        /// </summary>
        public double Credit { get; set; }

        /// <summary>
        /// Bid/Ask
        /// </summary>
        public IList<double> Prices { get; set; }
        
        /// <summary>
        /// Trade transaction
        /// </summary>
        public TradeTransInfo Trade { get; set; }

        /// <summary>
        /// Gateway order volume
        /// </summary>
        public int GwVolume { get; set; }

        /// <summary>
        /// Gateway order ticket
        /// </summary>
        public int GwOrder { get; set; }

        /// <summary>
        /// Gateway order price deviation (pips) from request price
        /// </summary>
        public short GwPrice { get; set; }
    }
}
