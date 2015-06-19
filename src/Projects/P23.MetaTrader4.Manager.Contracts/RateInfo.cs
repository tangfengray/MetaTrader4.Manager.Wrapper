using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class RateInfo
    {
        public UInt32 Ctm { get; set; }         // rate time
        public int Open { get; set; }           // open price: 11987=119.87
        public int High { get; set; }           // high,low,close shift from open
        public int Low { get; set; }
        public int Close { get; set; }
        public double Vol { get; set; }         // volume
    }
}
