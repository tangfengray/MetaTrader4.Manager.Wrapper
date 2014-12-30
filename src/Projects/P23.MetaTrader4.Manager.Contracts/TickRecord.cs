using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class TickRecord
    {
        public UInt32 Ctm { get; set; }                // tick time
        public double Bid { get; set; }                // bid, ask
        public double Ask { get; set; }
        public int DataFeed { get; set; }              // index if datafeed
        public char Flags { get; set; }                // TICK_FLAG_* flags
    }
}
