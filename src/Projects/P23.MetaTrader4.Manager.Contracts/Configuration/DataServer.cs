using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class DataServer
    {
        public string Server { get; set; }             // server address (server:ip)
        public UInt32 Ip { get; set; }                 // server IP
        public string Description { get; set; }        // server description
        public int IsProxy { get; set; }               // can server be proxy?
        public int Priority { get; set; }              // priority: 0-7 base, 255-idle
        public UInt32 Loading { get; set; }            // server loading (UINT_MAX-server does not inform its loading)
        public UInt32 IpInternal { get; set; }         // internal IP address   
    }
}
