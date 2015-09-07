namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents gateway markup configuration
    /// </summary>
    public class GatewayMarkup
    {
        /// <summary>
        /// Enable flag 0 - disabled, 1 - enabled
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Source symbol\symbols mask\symbols group name
        /// </summary>
        public string Source { get; set; }

        /// <summary>
        /// Local symbol name
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Account name (obsolete)
        /// </summary>
        public string AccountName { get; set; }

        /// <summary>
        /// Account internal id (obsolete)
        /// </summary>
        public int AccountID { get; set; }

        /// <summary>
        /// Bid markup in pips
        /// </summary>
        public int BidMarkup { get; set; }

        /// <summary>
        /// Ask markup in pips
        /// </summary>
        public int AskMarkup { get; set; }
    }
}