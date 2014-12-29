using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class SymbolSummary
    {
        public string Symbol { get; set; }          // symbol
        public int Count { get; set; }              // symbol counter
        public int Digits { get; set; }             // floating point digits
        public int Type { get; set; }               // symbol type (symbol group index)
        //--- clients summary
        public int Orders { get; set; }             // number of client orders
        public Int64 BuyLots { get; set; }          // buy volume
        public Int64 SellLots { get; set; }         // sell volume
        public double BuyPrice { get; set; }        // average buy price
        public double SellPrice { get; set; }       // average sell price
        public double Profit { get; set; }          // clients profit
        //--- coverage summary
        public int CovOrders { get; set; }          // number of coverage orders
        public Int64 CovBuyLots { get; set; }       // buy volume
        public Int64 CovSellLots { get; set; }      // sell volume
        public double CovBuyPrice { get; set; }     // average buy price
        public double CovSellPrice { get; set; }    // average sell price
        public double CovProfit { get; set; }       // coverage profit
    }
}
