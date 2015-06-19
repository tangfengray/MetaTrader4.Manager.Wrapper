using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class ChartInfo
    {
        public string Symbol { get; set; }          // symbol
        public int Period { get; set; }             // period (PERIOD_*)
        public UInt32 Start { get; set; }           // start of chart block
        public UInt32 End { get; set; }             // end of chart block
        public UInt32 TimeSign { get; set; }        // timestamp of existing chart base
        public int Mode { get; set; }               // request mode
    }
}
