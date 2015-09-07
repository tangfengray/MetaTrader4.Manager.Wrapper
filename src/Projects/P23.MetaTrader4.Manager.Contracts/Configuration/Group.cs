using System;
using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents group configuration
    /// </summary>
    public class Group
    {
        /// <summary>
        /// Group name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Enable group
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Trade confirmation timeout (seconds)
        /// </summary>
        public int Timeout { get; set; }

        /// <summary>
        /// Enable advanced security
        /// </summary>
        public int AdvSecurity { get; set; }

        /// <summary>
        /// Company name
        /// </summary>
        public string Company { get; set; }

        /// <summary>
        /// Statements signature
        /// </summary>
        public string Signature { get; set; }

        /// <summary>
        /// Company support page
        /// </summary>
        public string SupportPage { get; set; }

        /// <summary>
        /// Statements SMTP server
        /// </summary>
        public string SmtpServer { get; set; }

        /// <summary>
        /// Statements SMTP login
        /// </summary>
        public string SmtpLogin { get; set; }

        /// <summary>
        /// Statements SMTP password
        /// </summary>
        public string SmtpPassword { get; set; }

        /// <summary>
        /// Support email
        /// </summary>
        public string SupportEmail { get; set; }

        /// <summary>
        /// Path to directory with custom templates
        /// </summary>
        public string Templates { get; set; }

        /// <summary>
        /// Copy statements on support email
        /// </summary>
        public int Copies { get; set; }

        /// <summary>
        /// Enable statements
        /// </summary>
        public int Reports { get; set; }

        /// <summary>
        /// Default leverage (user don't specify leverage himself)
        /// </summary>
        public int DefaultLeverage { get; set; }

        /// <summary>
        /// Default deposit  (user don't specify balance  himself)
        /// </summary>
        public double DefaultDeposit { get; set; }

        /// <summary>
        /// Maximum simultaneous securities
        /// </summary>
        public int MaxSecurities { get; set; }

        /// <summary>
        /// Security group settings
        /// </summary>
        public IList<GroupSecurity> SecGroups { get; set; }

        /// <summary>
        /// Special securities settings
        /// </summary>
        public IList<GroupMargin> SecMargins { get; set; }

        /// <summary>
        /// Count of special securities settings
        /// </summary>
        public int SecMarginsTotal { get; set; }

        /// <summary>
        /// Deposit currency
        /// </summary>
        public string Currency { get; set; }

        /// <summary>
        /// Virtual credit
        /// </summary>
        public double Credit { get; set; }

        /// <summary>
        /// Margin call level (percents)
        /// </summary>
        public int MarginCall { get; set; }

        /// <summary>
        /// Margin mode-MARGIN_DONT_USE,MARGIN_USE_ALL,MARGIN_USE_PROFIT,MARGIN_USE_LOSS
        /// </summary>
        public int MarginMode { get; set; }

        /// <summary>
        /// Stop out level
        /// </summary>
        public int MarginStopout { get; set; }

        /// <summary>
        /// Annual interest rate (percents)
        /// </summary>
        public double InterestRate { get; set; }

        /// <summary>
        /// Use rollovers & interestrate
        /// </summary>
        public int UseSwap { get; set; }

        /// <summary>
        /// News mode
        /// </summary>
        public int News { get; set; }

        /// <summary>
        /// Rights bit mask-ALLOW_FLAG_EMAIL
        /// </summary>
        public int Rights { get; set; }

        /// <summary>
        /// Check IE prices on requests
        /// </summary>
        public int CheckIePrices { get; set; }

        /// <summary>
        /// Maximum orders and open positions
        /// </summary>
        public int MaxPositions { get; set; }

        /// <summary>
        /// Partial close mode (if !=0 original position will be fully closed and remain position will be fully reopened)
        /// </summary>
        public int CloseReopen { get; set; }

        /// <summary>
        /// Hedge prohibition flag
        /// </summary>
        public int HedgeProhibited { get; set; }

        /// <summary>
        /// Fifo rule 
        /// </summary>
        public int CloseFifo { get; set; }

        /// <summary>
        /// Use large leg margin for hedged positions    
        /// </summary>
        public int HedgeLargeLeg { get; set; }

        /// <summary>
        /// Margin controlling type { MARGIN_TYPE_PERCENT,  MARGIN_TYPE_CURRENCY }
        /// </summary>
        public int MarginType { get; set; }

        /// <summary>
        /// Inactivity period after which account moves to archive base (in days)
        /// </summary>
        public int ArchivePeriod { get; set; }

        /// <summary>
        /// Maxumum balance of accounts to move in archive base
        /// </summary>
        public int ArchiveMaxBalance { get; set; }

        /// <summary>
        /// Skip fully hedged accounts when checking for stopout
        /// </summary>
        public int StopOutSkipHedged { get; set; }

        /// <summary>
        /// Pendings clean period
        /// </summary>
        public int ArchivePendingPeriod { get; set; }

        /// <summary>
        /// LANGID array
        /// </summary>
        public IList<UInt32> NewsLanguages { get; set; }
    }
}
