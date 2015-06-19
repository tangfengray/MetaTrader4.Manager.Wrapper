using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class OnlineRecord
    {
        public int Counter { get; set; }     // connections counter
        public int Login { get; set; }       // user login
        public UInt32 Ip { get; set; }       // connection ip address
        public string Group { get; set; }    // user group
    }
}
