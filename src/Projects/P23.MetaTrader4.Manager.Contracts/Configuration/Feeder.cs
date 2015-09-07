namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents feeder configuration
    /// </summary>
    public class Feeder
    {
        /// <summary>
        /// Name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// DataFeed filename
        /// </summary>
        public string File { get; set; }

        /// <summary>
        /// Server address
        /// </summary>
        public string Server { get; set; }

        /// <summary>
        /// DataFeed login
        /// </summary>
        public string Login { get; set; }

        /// <summary>
        /// DataFeed password
        /// </summary>
        public string Pass { get; set; }

        /// <summary>
        /// Keywords (news filtration)
        /// </summary>
        public string Keywords { get; set; }

        /// <summary>
        /// Enable feeder
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Datafeed mode-enumeration FEED_QUOTES, FEED_NEWS, FEED_QUOTESNEWS
        /// </summary>
        public int Mode { get; set; }

        /// <summary>
        /// Max. freeze time (default ~120 sec.)
        /// </summary>
        public int Timeout { get; set; }

        /// <summary>
        /// Reconnect timeout before attemps_sleep connect attempts (default ~ 5  sec)
        /// </summary>
        public int TimeoutReconnect { get; set; }

        /// <summary>
        /// Reconnect timeout after attemps_sleep connect attempts  (default ~ 60 sec)
        /// </summary>
        public int TimeoutSleep { get; set; }

        /// <summary>
        /// Reconnect count (see timeout_reconnect & timeout_sleep)
        /// </summary>
        public int AttempsSleep { get; set; }

        /// <summary>
        /// News language id
        /// </summary>
        public int NewsLangId { get; set; }
    }
}
