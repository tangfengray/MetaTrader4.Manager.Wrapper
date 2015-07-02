using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class SymbolProperties
    {
        public string Symbol { get; set; }             // symbol
        public UInt32 Color { get; set; }              // symbol color
        public int Spread { get; set; }                // symbol spread
        public int SpreadBalance { get; set; }         // spread balance
        public int StopsLevel { get; set; }            // stops level
        public int Smoothing { get; set; }             // smoothing
        public int Exemode { get; set; }               // execution mode
    };
}