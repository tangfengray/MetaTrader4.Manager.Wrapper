using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Access
    {
        public int Action { get; set; }             // type of action (FW_BLOCK,FW_PERMIT)
        public UInt32 From { get; set; }            // from addresses
        public UInt32 To { get; set; }              // to addresses
        public string Comment { get; set; }         // comment
    }
}
