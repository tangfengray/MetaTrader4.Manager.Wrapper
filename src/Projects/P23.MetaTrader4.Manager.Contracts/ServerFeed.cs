namespace P23.MetaTrader4.Manager.Contracts
{
    public class ServerFeed
    {
        public string File { get; set; }                 // feeder file name
        public FeedDescription Feed { get; set; }        // feeder description
    }

    public class FeedDescription
    {
        public int Version { get; set; }                 // data source version
        public string Name { get; set; }                 // data source name
        public string Copyright { get; set; }            // copyright string
        public string Web { get; set; }                  // data source web
        public string Email { get; set; }                // data source email
        public string Server { get; set; }               // feeder server
        public string UserName { get; set; }             // default feeder name
        public string UserPass { get; set; }             // default feeder password
        public int Modes { get; set; }                   // feeder modes (enum FeederModes)
        public string Description { get; set; }          // feeder description
        public string Module { get; set; }               // reserved
    }
}
