using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class DailyReport
    {
        public int Login { get; set; }                   // login
        public UInt32 Ctm { get; set; }                  // time
        public string Group { get; set; }                // group
        public string Bank { get; set; }                 // bank
        public double BalancePrev { get; set; }         // previous balance
        public double Balance { get; set; }              // balance
        public double Deposit { get; set; }              // deposit
        public double Credit { get; set; }               // credit
        public double ProfitClosed { get; set; }        // closed profit/loss
        public double Profit { get; set; }               // floating profit/loss
        public double Equity { get; set; }               // equity
        public double Margin { get; set; }               // used margin
        public double MarginFree { get; set; }          // free margin
    }
}
