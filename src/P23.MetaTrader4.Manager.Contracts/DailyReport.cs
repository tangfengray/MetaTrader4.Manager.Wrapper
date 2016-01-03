using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents daily report
    /// </summary>
    public class DailyReport
    {
        /// <summary>
        /// login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// Time
        /// </summary>
        public UInt32 Ctm { get; set; }

        /// <summary>
        /// Group
        /// </summary>
        public string Group { get; set; }

        /// <summary>
        /// Bank
        /// </summary>
        public string Bank { get; set; }

        /// <summary>
        /// Previous balance
        /// </summary>
        public double BalancePrev { get; set; }

        /// <summary>
        /// Balance
        /// </summary>
        public double Balance { get; set; }

        /// <summary>
        /// Deposit
        /// </summary>
        public double Deposit { get; set; }

        /// <summary>
        /// Credit
        /// </summary>
        public double Credit { get; set; }

        /// <summary>
        /// Closed profit/loss
        /// </summary>
        public double ProfitClosed { get; set; }

        /// <summary>
        /// Floating profit/loss
        /// </summary>
        public double Profit { get; set; }

        /// <summary>
        /// Equity
        /// </summary>
        public double Equity { get; set; }

        /// <summary>
        /// Used margin
        /// </summary>
        public double Margin { get; set; }

        /// <summary>
        /// Free margin
        /// </summary>
        public double MarginFree { get; set; }
    }
}
