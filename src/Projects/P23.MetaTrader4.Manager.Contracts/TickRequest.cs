using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class TickRequest
    {
        public string Symbol { get; set; }             // symbol
        public UInt32 From { get; set; }               // start of period
        public UInt32 To { get; set; }                 // end of period
        public char Flags { get; set; }                // TICK_FLAG_* flags
    }
}
