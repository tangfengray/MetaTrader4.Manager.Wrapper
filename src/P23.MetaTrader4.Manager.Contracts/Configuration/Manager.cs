using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents manager configuration
    /// </summary>
    public class Manager
    {
        /// <summary>
        /// Login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// Right to add and change client records
        /// </summary>
        public int ManagerRights { get; set; }

        /// <summary>
        /// Right to balance and credit management
        /// </summary>
        public int Money { get; set; }

        /// <summary>
        /// Right to see online users
        /// </summary>
        public int Online { get; set; }

        /// <summary>
        /// Right to use analyzer
        /// </summary>
        public int Riskman { get; set; }

        /// <summary>
        /// Right to deal
        /// </summary>
        public int Broker { get; set; }

        /// <summary>
        /// Right to server administration
        /// </summary>
        public int Admin { get; set; }

        /// <summary>
        /// Right to see logs
        /// </summary>
        public int Logs { get; set; }

        /// <summary>
        /// Right to see reports
        /// </summary>
        public int Reports { get; set; }

        /// <summary>
        /// Right to add/modify/delete trades
        /// </summary>
        public int Trades { get; set; }

        /// <summary>
        /// Right to change spread, spread balance, stop levels, execution mode and send quotes
        /// </summary>
        public int MarketWatch { get; set; }

        /// <summary>
        /// Right to send internal mail
        /// </summary>
        public int Email { get; set; }

        /// <summary>
        /// Right to see clients private data-name,country,address,phone,email etc.
        /// </summary>
        public int UserDetails { get; set; }

        /// <summary>
        /// Right to see trades
        /// </summary>
        public int SeeTrades { get; set; }

        /// <summary>
        /// Right to send news
        /// </summary>
        public int News { get; set; }

        /// <summary>
        /// Right to configure plugins
        /// </summary>
        public int Plugins { get; set; }

        /// <summary>
        /// Right to receive server reports
        /// </summary>
        public int ServerReports { get; set; }

        /// <summary>
        /// Right to access to technical support page
        /// </summary>
        public int TechSupport { get; set; }

        /// <summary>
        /// Right to access server applications Market
        /// </summary>
        public int Market { get; set; }

        /// <summary>
        /// Right to push Notifications
        /// </summary>
        public int Notifications { get; set; }

        /// <summary>
        /// Enable IP control
        /// </summary>
        public int IpFilter { get; set; }
        
        /// <summary>
        /// range of allowed IPs
        /// </summary>
        public ulong IpFrom { get; set; }

        /// <summary>
        /// range of allowed IPs
        /// </summary>
        public ulong IpTo { get; set; }

        /// <summary>
        /// Name of mailbox for internal mail
        /// </summary>
        public string Mailbox { get; set; }

        /// <summary>
        /// Comma separated list of managed groups (allowed '*' wildcard)
        /// </summary>
        public string Groups { get; set; }

        /// <summary>
        /// Manager rights for security groups
        /// </summary>
        public IList<ManagerSecurity> SecGroups { get; set; }

        /// <summary>
        /// Manager name (read only)
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Maximum available data (in days)
        /// </summary>
        public int InfoDepth { get; set; }
    }
}
