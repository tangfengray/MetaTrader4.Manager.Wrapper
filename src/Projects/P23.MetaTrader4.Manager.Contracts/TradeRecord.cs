using System;
using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class TradeRecord
    {
        public int Order { get; set; }            // order ticket
        public int Login { get; set; }            // owner's login
        public string Symbol { get; set; }        // security
        public int Digits { get; set; }           // security precision
        public int Cmd { get; set; }              // trade command
        public int Volume { get; set; }           // volume
        //---
        public UInt32 OpenTime { get; set; }      // open time
        public int State { get; set; }            // reserved
        public double OpenPrice { get; set; }     // open price
        public double Sl { get; set; }            // stop loss & take profit
        public double Tp { get; set; }
        public UInt32 CloseTime { get; set; }     // close time
        public int GwVolume { get; set; }         // gateway order volume
        public UInt32 Expiration { get; set; }    // pending order's expiration time
        public char Reason { get; set; }          // trade reason

        public IList<double> ConvRates { get; set; }    // convertation rates from profit currency to group deposit currency
        // (first element-for open time, second element-for close time)
        public double Commission { get; set; }    // commission
        public double CommissionAgent { get; set; } // agent commission
        public double Storage { get; set; }       // order swaps
        public double ClosePrice { get; set; }    // close price
        public double Profit { get; set; }        // profit
        public double Taxes { get; set; }         // taxes
        public int Magic { get; set; }            // special value used by client experts
        public string Comment { get; set; }       // comment
        public int GwOrder { get; set; }          // gateway order ticket
        public int Activation { get; set; }       // used by MT Manager
        public short GwOpenPrice { get; set; }    // gateway order price deviation (pips) from order open price
        public short GwClosePrice { get; set; }   // gateway order price deviation (pips) from order close price
        public double MarginRate { get; set; }    // margin convertation rate (rate of convertation from margin currency to deposit one)
        public UInt32 Timestamp { get; set; }     // timestamp
    }
}
