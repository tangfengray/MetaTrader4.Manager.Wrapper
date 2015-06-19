namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Feeder
    {
        public string Name { get; set; }              // name
        public string File { get; set; }              // datafeed filename
        public string Server { get; set; }            // server address
        public string Login { get; set; }             // datafeed login
        public string Pass { get; set; }              // datafeed password
        public string Keywords { get; set; }          // keywords (news filtration)
        public int Enable { get; set; }               // enable feeder
        public int Mode { get; set; }                 // datafeed mode-enumeration FEED_QUOTES, FEED_NEWS, FEED_QUOTESNEWS
        public int Timeout { get; set; }              // max. freeze time (default ~120 sec.)
        public int TimeoutReconnect { get; set; }     // reconnect timeout before attemps_sleep connect attempts (default ~ 5  sec)
        public int TimeoutSleep { get; set; }         // reconnect timeout after attemps_sleep connect attempts  (default ~ 60 sec)
        public int AttempsSleep { get; set; }         // reconnect count (see timeout_reconnect & timeout_sleep)
        public int NewsLangId { get; set; }           // news language id
    }
}
