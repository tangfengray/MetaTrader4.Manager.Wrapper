using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class SymbolInfo
    {
        public string Symbol { get; set; }            // symbol name
        public int Digits { get; set; }               // floating point digits
        public int Count { get; set; }                // symbol counter
        public int Visible { get; set; }              // visibility
        //--- данные для перерасчёта спреда
        public int Type { get; set; }                 // symbol type (symbols group index)
        public double Point { get; set; }             // symbol point=1/pow(10,digits)
        public int Spread { get; set; }               // symbol spread
        public int SpreadBalance { get; set; }        // spread balance
        //---
        public int Direction { get; set; }            // direction
        public int UpdateFlag { get; set; }           // update flag
        public UInt32 LastTime { get; set; }          // last tick time
        public double Bid { get; set; }               // bid
        public double Ask { get; set; }               // ask
        public double High { get; set; }              // high
        public double Low { get; set; }               // low
        public double Commission { get; set; }        // commission
        public int CommType { get; set; }             // commission type  
    }
}
