using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class GatewayAccount
    {
        public int Enable { get; set; }                      // enable flag 0 - disabled, 1 - enabled
        public string Name { get; set; }                     // public name
        public int ID { get; set; }                          // internal id
        public int Type { get; set; }                        // type (obsolete)
        public int Login { get; set; }                       // STP MT4 login
        public string Address { get; set; }                  // MT4 server address
        public string Password { get; set; }                 // STP MT4 password
        public List<int> NotifyLogins { get; set; }          // list of logins for internal email notification
        public int Flags { get; set; }                       // flag fields
    }
}
