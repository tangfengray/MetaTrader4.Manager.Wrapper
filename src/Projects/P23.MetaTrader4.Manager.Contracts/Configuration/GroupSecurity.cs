namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents group security configuration
    /// </summary>
    public class GroupSecurity
    {
        /// <summary>
        /// Enable show for this group of securites
        /// </summary>
        public int Show { get; set; }

        /// <summary>
        /// Enable for this group of securites
        /// </summary>
        public int Trade { get; set; }

        /// <summary>
        /// Dealing mode-EXECUTION_MANUAL,EXECUTION_AUTO,EXECUTION_ACTIVITY
        /// </summary>
        public int Execution { get; set; }

        /// <summary>
        /// Standart commission
        /// </summary>
        public double CommBase { get; set; }

        /// <summary>
        /// Commission type-COMM_TYPE_MONEY,COMM_TYPE_PIPS,COMM_TYPE_PERCENT
        /// </summary>
        public int CommType { get; set; }

        /// <summary>
        /// Commission lots mode-COMMISSION_PER_LOT,COMMISSION_PER_DEAL
        /// </summary>
        public int CommLots { get; set; }

        /// <summary>
        /// Agent commission
        /// </summary>
        public double CommAgent { get; set; }

        /// <summary>
        /// Agent commission mode-COMM_TYPE_MONEY, COMM_TYPE_PIPS
        /// </summary>
        public int CommAgentType { get; set; }

        /// <summary>
        /// Spread difference in compare with default security spread
        /// </summary>
        public int SpreadDiff { get; set; }

        /// <summary>
        /// Allowed minimal lot values
        /// </summary>
        public int LotMin { get; set; }          // 

        /// <summary>
        /// Allowed maximal lot values
        /// </summary>
        public int LotMax { get; set; }

        /// <summary>
        /// Allowed step value (10 lot-1000, 1 lot-100, 0.1 lot-10)
        /// </summary>
        public int LotStep { get; set; }

        /// <summary>
        /// Maximum price deviation in Instant Execution mode
        /// </summary>
        public int IeDeviation { get; set; }

        /// <summary>
        /// Use confirmation in Request mode
        /// </summary>
        public int Confirmation { get; set; }

        /// <summary>
        /// Clients trade rights-bit mask see TRADE_DENY_NONE,TRADE_DENY_CLOSEBY,TRADE_DENY_MUCLOSEBY
        /// </summary>
        public int TradeRights { get; set; }

        /// <summary>
        /// Do not resend request to the dealer when client uses deviation
        /// </summary>
        public int IeQuickMode { get; set; }

        /// <summary>
        /// Auto close-out method { CLOSE_OUT_NONE, CLOSE_OUT_HIHI, CLOSE_OUT_LOLO, CLOSE_OUT_HILO, CLOSE_OUT_LOHI, CLOSE_OUT_LOHI, CLOSE_OUT_FIFO, CLOSE_OUT_LIFO, CLOSE_OUT_INTRDAY_FIFO }
        /// </summary>
        public int AutoCloseOutMode { get; set; }

        /// <summary>
        /// Commission taxes
        /// </summary>
        public double CommTax { get; set; }

        /// <summary>
        /// Agent commission per lot/per deal { COMMISSION_PER_LOT,COMMISSION_PER_DEAL }
        /// </summary>
        public int CommAgentLots { get; set; }

        /// <summary>
        /// "soft" margin check
        /// </summary>
        public int FreeMarginMode { get; set; }
    }
}
