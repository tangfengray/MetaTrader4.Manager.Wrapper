using System;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Synchronization
    {
        public string Server { get; set; }                   // name (address
        public int UnusedPort { get; set; }                  // port
        public string Login { get; set; }                    // for future use-login
        public string Password { get; set; }                 // for future use=password
        public int Enable { get; set; }                      // enable sychronization
        public int Mode { get; set; }                        // synchronization mode: HB_ADD,HB_UPDATE,HB_INSERT
        public UInt32 From { get; set; }                     // synchronization range (<0-whole chart)
        public UInt32 To { get; set; }                       // synchronization range (<0-whole chart)
        public string Securities { get; set; }               // symbols list
    }
}
