using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class GroupSecurity
    {
        public int Show { get; set; }            // enable show and trade for this group of securites
        public int Trade { get; set; }
        public int Execution { get; set; }       // dealing mode-EXECUTION_MANUAL,EXECUTION_AUTO,EXECUTION_ACTIVITY
        //--- comission settings
        public double CommBase { get; set; }     // standart commission
        public int CommType { get; set; }        // commission type-COMM_TYPE_MONEY,COMM_TYPE_PIPS,COMM_TYPE_PERCENT
        public int CommLots { get; set; }        // commission lots mode-COMMISSION_PER_LOT,COMMISSION_PER_DEAL
        public double CommAgent { get; set; }    // agent commission
        public int CommAgentType { get; set; }   // agent commission mode-COMM_TYPE_MONEY, COMM_TYPE_PIPS
        //---
        public int SpreadDiff { get; set; }      // spread difference in compare with default security spread
        //---
        public int LotMin { get; set; }          // allowed minimal and maximal lot values
        public int LotMax { get; set; }
        public int LotStep { get; set; }         // allowed step value (10 lot-1000, 1 lot-100, 0.1 lot-10)
        public int IeDeviation { get; set; }     // maximum price deviation in Instant Execution mode
        public int Confirmation { get; set; }    // use confirmation in Request mode
        public int TradeRights { get; set; }     // clients trade rights-bit mask see TRADE_DENY_NONE,TRADE_DENY_CLOSEBY,TRADE_DENY_MUCLOSEBY
        public int IeQuickMode { get; set; }     // do not resend request to the dealer when client uses deviation
        public int AutoCloseOutMode { get; set; }// auto close-out method { CLOSE_OUT_NONE, CLOSE_OUT_HIHI, CLOSE_OUT_LOLO, CLOSE_OUT_HILO, CLOSE_OUT_LOHI, CLOSE_OUT_LOHI, CLOSE_OUT_FIFO, CLOSE_OUT_LIFO, CLOSE_OUT_INTRDAY_FIFO }
        public double CommTax { get; set; }      // commission taxes
        public int CommAgentLots { get; set; }   // agent commission per lot/per deal { COMMISSION_PER_LOT,COMMISSION_PER_DEAL }
        public int FreeMarginMode { get; set; }  // "soft" margin check
    }

    public class GroupMargin
    {
        public string Symbol { get; set; }           // security
        public double SwapLong { get; set; }         // tickvalue for bid & ask
        public double SwapShort { get; set; }
        public double MarginDivider { get; set; }    // margin divider
    }
}
