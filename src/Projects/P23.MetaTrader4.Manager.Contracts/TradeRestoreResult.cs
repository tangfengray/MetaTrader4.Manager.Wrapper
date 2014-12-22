using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class TradeRestoreResult
    {
        public int Order { get; set; }            // order
        public byte Res { get; set; }             // RET_OK_NONE     -order restored
                                                  // RET_INVALID_DATA-existent order restored
                                                  // RET_ERROR       -restoring disabled
    }
}
