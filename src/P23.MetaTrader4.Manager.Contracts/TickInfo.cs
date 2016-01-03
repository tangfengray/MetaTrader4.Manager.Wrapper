namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents tick info
    /// </summary>
    public class TickInfo
    {
        /// <summary>
        /// Symbol
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Tick time
        /// </summary>
        public long Ctm { get; set; }

        /// <summary>
        /// Bid
        /// </summary>
        public double Bid { get; set; }

        /// <summary>
        /// Ask
        /// </summary>
        public double Ask { get; set; }
    }
}
