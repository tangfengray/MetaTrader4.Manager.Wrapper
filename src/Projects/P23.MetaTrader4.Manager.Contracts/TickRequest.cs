using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class TickRequest
    {
        public string symbol { get; set; }             // symbol
        public UInt32 from { get; set; }               // start of period
        public UInt32 to { get; set; }                 // end of period
        public char flags { get; set; }                // TICK_FLAG_* flags
    }
}
