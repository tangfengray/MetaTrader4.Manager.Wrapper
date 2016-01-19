using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents symbol summary
    /// </summary>
    public class SymbolSummary
    {
        /// <summary>
        /// Symbol
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Symbol counter
        /// </summary>
        public int Count { get; set; }

        /// <summary>
        /// Floating point digits
        /// </summary>
        public int Digits { get; set; }

        /// <summary>
        /// Symbol type (symbol group index)
        /// </summary>
        public int Type { get; set; }

        /// <summary>
        /// Number of client orders
        /// </summary>
        public int Orders { get; set; }

        /// <summary>
        /// Buy volume
        /// </summary>
        public Int64 BuyLots { get; set; }

        /// <summary>
        /// Sell volume
        /// </summary>
        public Int64 SellLots { get; set; }

        /// <summary>
        /// Average buy price
        /// </summary>
        public double BuyPrice { get; set; }

        /// <summary>
        /// Average sell price
        /// </summary>
        public double SellPrice { get; set; }

        /// <summary>
        /// Clients profit
        /// </summary>
        public double Profit { get; set; }

        /// <summary>
        /// Number of coverage orders
        /// </summary>
        public int CovOrders { get; set; }

        /// <summary>
        /// Buy volume
        /// </summary>
        public Int64 CovBuyLots { get; set; }

        /// <summary>
        /// Sell volume
        /// </summary>
        public Int64 CovSellLots { get; set; }

        /// <summary>
        /// Average buy price
        /// </summary>
        public double CovBuyPrice { get; set; }

        /// <summary>
        /// Average sell price
        /// </summary>
        public double CovSellPrice { get; set; }

        /// <summary>
        /// Coverage profit
        /// </summary>
        public double CovProfit { get; set; }
    }
}
