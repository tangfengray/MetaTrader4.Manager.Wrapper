using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class TickInfo
    {
        public string Symbol { get; set; }   // symbol
        public long Ctm { get; set; }        // tick time
        public double Bid { get; set; }      // bid
        public double Ask { get; set; }      // ask
    }
}
