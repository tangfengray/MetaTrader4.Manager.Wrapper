namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents server feed
    /// </summary>
    public class ServerFeed
    {
        /// <summary>
        /// Feeder file name
        /// </summary>
        public string File { get; set; }

        /// <summary>
        /// Feeder description
        /// </summary>
        public FeedDescription Feed { get; set; }
    }
}
