namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents group margin configuration
    /// </summary>
    public class GroupMargin
    {
        /// <summary>
        /// Security
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Tickvalue for bid
        /// </summary>
        public double SwapLong { get; set; }

        /// <summary>
        /// /// <summary>
        /// Tickvalue for ask
        /// </summary>
        /// </summary>
        public double SwapShort { get; set; }

        /// <summary>
        /// Margin divider
        /// </summary>
        public double MarginDivider { get; set; }
    }
}