using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Manager
    {
        public int Login { get; set; }                       // login
        //--- rights
        public int ManagerRights { get; set; }               // right to add & change client records
        public int Money { get; set; }                       // right to balance & credit management
        public int Online { get; set; }                      // right to see online users
        public int Riskman { get; set; }                     // right to use analyzer
        public int Broker { get; set; }                      // right to deal
        public int Admin { get; set; }                       // right to server administration
        public int Logs { get; set; }                        // right to see logs
        public int Reports { get; set; }                     // right to see reports
        public int Trades { get; set; }                      // right to add/modify/delete trades
        public int MarketWatch { get; set; }                 // right to change spread, spread balance, stop levels, execution mode and send quotes
        public int Email { get; set; }                       // right to send internal mail
        public int UserDetails { get; set; }                 // right to see clients private data-name,country,address,phone,email etc.
        public int SeeTrades { get; set; }                   // right to see trades
        public int News { get; set; }                        // right to send news
        public int Plugins { get; set; }                     // right to configure plugins
        public int ServerReports { get; set; }               // right to receive server reports
        public int TechSupport { get; set; }                 // right to access to technical support page
        //--- IP filtration
        public int IpFilter { get; set; }                    // enable IP control
        public ulong IpFrom { get; set; }                    // range of allowed IPs
        public ulong IpTo { get; set; }                      // range of allowed IPs
        //---
        public string Mailbox { get; set; }                  // name of mailbox for internal mail
        public string Groups { get; set; }                   // comma separated list of managed groups (allowed '*' wildcard)
        public IList<ManagerSecurity> SecGroups { get; set; }// manager rights for security groups

        public string Name { get; set; }                     // manager name (read only)
        public int InfoDepth { get; set; }                   // maximum available data (in days)    
    }

    public class ManagerSecurity
    {
        public int Enable { get; set; }                      // enable
        public int MinimumLots { get; set; }                 // min. lots
        public int MaximumLots { get; set; }                 // max. lots

    };
}
