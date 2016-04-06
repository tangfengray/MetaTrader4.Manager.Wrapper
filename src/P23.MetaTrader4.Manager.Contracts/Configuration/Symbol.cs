using System;
using System.Collections.Generic;
using P23.MetaTrader4.Manager.Contracts.Configuration.Enums;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents symbol configuration
    /// </summary>
    public class Symbol
    {
        /// <summary>
        /// Name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Description
        /// </summary>
        public string Description { get; set; }

        /// <summary>
        /// Synonym
        /// </summary>
        public string Source { get; set; }

        /// <summary>
        /// Currency
        /// </summary>
        public string Currency { get; set; }

        /// <summary>
        /// Security group (see SymbolGroup)
        /// </summary>
        public int Type { get; set; }

        /// <summary>
        /// Security precision
        /// </summary>
        public int Digits { get; set; }

        /// <summary>
        /// Trade mode
        /// </summary>
        public TradeMode Trade { get; set; }

        /// <summary>
        /// Background color
        /// </summary>
        public UInt32 BackgroundColor { get; set; }

        /// <summary>
        /// Symbols index
        /// </summary>
        public int Count { get; set; }

        /// <summary>
        /// Symbols index in Market watch
        /// </summary>
        public int CountOriginal { get; set; }

        /// <summary> 
        /// Allow real time quotes
        /// </summary>
        public int RealTime { get; set; }

        /// <summary>
        /// Trades starting date (UNIX time)
        /// </summary>
        public UInt32 Starting { get; set; }

        /// <summary>
        /// Trades end date      (UNIX time)
        /// </summary>
        public UInt32 Expiration { get; set; }

        /// <summary>
        /// Quote and trade sessions
        /// </summary>
        public IList<Sessions> Sessions { get; set; }

        /// <summary>
        /// Profit calculation mode
        /// </summary>
        public ProfitCalculationMode ProfitMode { get; set; }

        /// <summary>
        /// Filter value
        /// </summary>
        public int Filter { get; set; }

        /// <summary>
        /// Filtration parameter
        /// </summary>
        public int FilterCounter { get; set; }

        /// <summary>
        /// Max. permissible deviation from last quote (percents)
        /// </summary>
        public double FilterLimit { get; set; }

        /// <summary>
        /// Smoothing
        /// </summary>
        public int FilterSmoothing { get; set; }

        /// <summary>
        /// Enable to log quotes
        /// </summary>
        public int Logging { get; set; }

        /// <summary>
        /// Spread
        /// </summary>
        public int Spread { get; set; }

        /// <summary>
        /// Spread balance
        /// </summary>
        public int SpreadBalance { get; set; }

        /// <summary>
        /// Execution mode
        /// </summary>
        public SymbolExecutionMode Exemode { get; set; }

        /// <summary>
        /// Enable swaps
        /// </summary>
        public int SwapEnable { get; set; }

        /// <summary>
        /// Swap type
        /// </summary>
        public SwapType SwapType { get; set; }

        /// <summary>
        /// Swaps values for long postions
        /// </summary>
        public double SwapLong { get; set; }

        /// <summary>
        /// Swaps values for short postions
        /// </summary>
        public double SwapShort { get; set; }

        /// <summary>
        /// Triple rollover day-0-Monday,1-Tuesday...4-Friday
        /// </summary>
        public int SwapRollover3Days { get; set; }

        /// <summary>
        /// Contract size
        /// </summary>
        public double ContractSize { get; set; }

        /// <summary>
        /// One tick value
        /// </summary>
        public double TickValue { get; set; }

        /// <summary>
        /// One tick size
        /// </summary>
        public double TickSize { get; set; }

        /// <summary>
        /// Stops deviation value
        /// </summary>
        public int StopsLevel { get; set; }

        /// <summary>
        /// GTC mode { ORDERS_DAILY, ORDERS_GTC, ORDERS_DAILY_NO_STOPS }
        /// </summary>
        public GtcMode GtcPendings { get; set; }
        
        /// <summary>
        /// Margin calculation mode
        /// </summary>
        public SymbolMarginCalculationMode MarginMode { get; set; }

        /// <summary>
        /// Initial margin
        /// </summary>
        public double MarginInitial { get; set; }

        /// <summary>
        /// Margin maintenance
        /// </summary>
        public double MarginMaintenance { get; set; }

        /// <summary>
        /// Hadged margin
        /// </summary>
        public double MarginHedged { get; set; }

        /// <summary>
        /// Margin divider
        /// </summary>
        public double MarginDivider { get; set; }

        /// <summary>
        /// Point size-(1/(10^digits)
        /// </summary>
        public double Point { get; set; }

        /// <summary>
        /// Multiply 10^digits
        /// </summary>
        public double Multiply { get; set; }

        /// <summary>
        /// Tick value for bid
        /// </summary>
        public double BidTickValue { get; set; }

        /// <summary>
        /// Tick value for ask
        /// </summary>
        public double AskTickValue { get; set; }

        /// <summary>
        /// Allow only BUY positions
        /// </summary>
        public int LongOnly { get; set; }

        /// <summary>
        /// Max. volume for Instant Execution
        /// </summary>
        public int InstantMaxVolume { get; set; }

        /// <summary>
        /// Currency of margin requirments
        /// </summary>
        public string MarginCurrency { get; set; }

        /// <summary>
        /// Modification freeze level
        /// </summary>
        public int FreezeLevel { get; set; }

        /// <summary>
        /// Strong hedged margin mode
        /// </summary>
        public int MarginHedgedStrong { get; set; }

        /// <summary>
        /// Value date
        /// </summary>
        public UInt32 ValueDate { get; set; }

        /// <summary>
        /// Quotes delay after session start
        /// </summary>
        public int QuotesDelay { get; set; }

        /// <summary>
        /// Use open price at swaps calculation in SWAP_BY_INTEREST mode
        /// </summary>
        public int SwapOpenPrice { get; set; }

        /// <summary>
        /// Charge variation margin on rollover
        /// </summary>
        public int SwapVariationMargin { get; set; }
    }
}
