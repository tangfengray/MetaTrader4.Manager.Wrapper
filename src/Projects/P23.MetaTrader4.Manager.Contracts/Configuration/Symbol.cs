using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Symbol
    {
        //--- common settings
        public string Name { get; set; }                  // name
        public string Description { get; set; }             // description
        public string Source { get; set; }                  // synonym
        public string Currency { get; set; }                // currency
        public int Type { get; set; }                       // security group (see ConSymbolGroup)
        public int Digits { get; set; }                     // security precision
        public int Trade { get; set; }                      // trade mode
        //--- external settings
        public UInt32 BackgroundColor { get; set; }         // background color
        public int Count { get; set; }                      // symbols index
        public int CountOriginal { get; set; }              // symbols index in market watch

        //--- sessions
        public int RealTime { get; set; }                   // allow real time quotes
        public UInt32 Starting { get; set; }                // trades starting date (UNIX time)
        public UInt32 Expiration { get; set; }              // trades end date      (UNIX time)
        public IList<Sessions> Sessions { get; set; }       // quote & trade sessions
        //--- profits
        public int ProfitMode { get; set; }                 // profit calculation mode
        
        //--- filtration
        public int Filter { get; set; }                     // filter value
        public int FilterCounter { get; set; }              // filtration parameter
        public double FilterLimit { get; set; }             // max. permissible deviation from last quote (percents)
        public int FilterSmoothing { get; set; }            // smoothing
        
        public int Logging { get; set; }                    // enable to log quotes
        //--- spread & swaps
        public int Spread { get; set; }                     // spread
        public int SpreadBalance { get; set; }              // spread balance
        public int Exemode { get; set; }                    // execution mode
        public int SwapEnable { get; set; }                 // enable swaps
        public int SwapType { get; set; }                   // swap type
        public double SwapLong { get; set; }                // swaps values for long & short postions
        public double SwapShort { get; set; }
        public int SwapRollover3Days { get; set; }          // triple rollover day-0-Monday,1-Tuesday...4-Friday
        public double ContractSize { get; set; }            // contract size
        public double TickValue { get; set; }               // one tick value
        public double TickSize { get; set; }                // one tick size
        public int StopsLevel { get; set; }                 // stops deviation value
        //---            овернайты и прочие свопы
        public int GtcPendings { get; set; }                // GTC mode { ORDERS_DAILY, ORDERS_GTC, ORDERS_DAILY_NO_STOPS }
        //--- margin calculation
        public int MarginMode { get; set; }                 // margin calculation mode
        public double MarginInitial { get; set; }           // initial margin
        public double MarginMaintenance { get; set; }       // margin maintenance
        public double MarginHedged { get; set; }            // hadget margin
        public double MarginDivider { get; set; }           // margin divider
        //--- calclulated variables (internal data)
        public double Point { get; set; }                   // point size-(1/(10^digits)
        public double Multiply { get; set; }                // multiply 10^digits
        public double BidTickValue { get; set; }            // tickvalue for bid
        public double AskTickValue { get; set; }            // tickvalue for ask
        //---
        public int LongOnly { get; set; }                   // allow only BUY positions
        public int InstantMaxVolume { get; set; }           // max. volume for Instant Execution
        //---
        public string MarginCurrency { get; set; }          // currency of margin requirments
        public int FreezeLevel { get; set; }                // modification freeze level
        public int MarginHedgedStrong { get; set; }         // strong hedged margin mode
        public UInt32 ValueDate { get; set; }               // value date
        public int QuotesDelay { get; set; }                // quotes delay after session start
        public int SwapOpenPrice { get; set; }         	    // use open price at swaps calculation in SWAP_BY_INTEREST mode
        public int SwapVariationMargin { get; set; }        // charge variation margin on rollover
    }
}
