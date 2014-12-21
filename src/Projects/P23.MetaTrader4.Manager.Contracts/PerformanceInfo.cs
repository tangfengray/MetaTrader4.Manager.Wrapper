using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class PerformanceInfo
    {
        public UInt32 Ctm { get; set; }
        public short Users { get; set; }                // online users
        public short Cpu { get; set; }                  // processor loading (%)
        public int FreeMem { get; set; }                // free memory (Kb)
        public int Network { get; set; }                // network activity (Kb/s)
        public int Sockets { get; set; }                // all open sockets in system
    };
}
